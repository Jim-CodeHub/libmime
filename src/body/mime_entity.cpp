/**-----------------------------------------------------------------------------------------------------------------
 * @file	mime_entity.cpp
 * @brief	Multi-purpose mail extensions	
 * @ref		IETF-rfc2045, rfc2046, rfc2047, rfc2048, rfc2049 
 *
 * Copyright (c) 2019-2019 Jim Zhang 303683086@qq.com
 *------------------------------------------------------------------------------------------------------------------
*/

#include <libMIME/src/body/mime_entity.hpp>

using namespace NS_LIBMIME;


/*
--------------------------------------------------------------------------------------------------------------------
*
*			                                  FUNCTIONS IMPLEMENT
*
--------------------------------------------------------------------------------------------------------------------
*/

/**
 *	@brief	    Set mime entity leaf node 
 *	@param[in]  header - mime entity header 
 *	@param[in]  sdbody - mime entity shadow body 
 *	@param[out] None 
 *	@return	    None 
 *	@note		The function can be called repeatedly, but only to save the last settings 
 *	@note		The function SHOULD BE used as a leaf node setting 
 **/
void mime_entity::set_node(const class mime_header &header, const class body_shadow &sdbody)
{
	this->header = header;
	this->sdbody = sdbody; return;
}

/**
 *	@brief	    Set mime enity part which under the param 'header' 
 *	@param[in]  header - mime entity (part father's) header
 *	@param[out] None 
 *	@return		mime entity part pointer 
 *
 *	@note		1. The function can be called repeatedly, and each call returns a new mime_entity for the part extension  
 *	@note		2. Param 'header' belong to the part father
 *	@note		3. The header only to save the first settings
 *	@note		4. Set Content-Type field with 'multipart' correctly, or the exception will be throw	
 *
 *	@exception  "Const char *" 'multipart' type does not exsits
 **/
class mime_entity *mime_entity::set_part(const class mime_header &header)
{
	if (this->header.is_empty()) 
	{   this->header = header; }

	contenttype_body cb(this->header.get_field("Content-Type").get_body());

	if (cb.get_major_type() != "multipart")
	{
		throw("Exception : 'multipart' type does not exsits!");
	}

	this->sdbody.clear();

	class mime_entity *pEntity = new class mime_entity;

	this->sdbody.part_entity.push_back(pEntity);
	
	return pEntity; //*(this->sdbody.part_entity.rbegin());
}

/**
 *	@brief	    Get mime entity
 *	@param[in]  None 
 *	@param[out] None 
 *	@return	    mime entity 
 **/
const string mime_entity::make(void)
{
	string _mime_entity, boundary;
	list<class mime_entity*>::const_iterator _big = this->sdbody.part_entity.begin(),
											 _end = this->sdbody.part_entity.  end();
	class contenttype_body cb;

	/**----------------------------------------------------------------------------*/
	/**< Add header */

	_mime_entity  = this->header.get();

	/**----------------------------------------------------------------------------*/
	/**< Mult-part does not exsits (End recursive) */

	if (_big == _end) { goto _ADD_NODE_BODY; }

	/**----------------------------------------------------------------------------*/
	/**< Construct boundary */

	cb.set(this->header.get_field("Content-Type").get_body());

	if ("" == (boundary = cb.get_param_value("boundary")))
	{
		boundary = contenttype_body::construct_boundary();
		cb.set_param("boundary", boundary);

		this->header.get_field("Content-Type").set_body(&cb);
	}

	/**----------------------------------------------------------------------------*/
	/**< Recursive sub multi-part */

	while ((_big != _end) && (NULL != *_big))
	{
		_mime_entity += "--" + boundary + "\r\n\r\n";

		_mime_entity += (*_big)->make(); _big++;
	}

	_mime_entity += "--" + boundary + "--\r\n\r\n";

	/**----------------------------------------------------------------------------*/

_ADD_NODE_BODY:
	_mime_entity += (this->sdbody.preamble.empty())?"":(this->sdbody.preamble + "\r\n\r\n");
	_mime_entity += *(this->sdbody.bodys);
	_mime_entity += (this->sdbody.epilogue.empty())?"":(this->sdbody.epilogue + "\r\n\r\n");

	return _mime_entity; 
}


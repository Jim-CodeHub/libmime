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
 *	@brief	    Delete the header field, if it's not belong to the mime entity
 *	@param[in]  _header 
 *	@param[out] None 
 *	@return	    Reference class mime_header which has been filtered 
 **/
const class mime_header &mime_entity::check_header(class mime_header &_header)
{
	long unsigned int i = 0;

	while (!(field::null_field == (_header.header::get_field(i))))
	{
		if (string::npos == (_header.header::get_field(i)).get_name().find("Content-", 0))
		{
			_header.remove((_header.header::get_field(i)).get_name());
			continue;
		}

		i++;
	}

	return _header;
}

/**
 *	@brief	    Set mime entity leaf node 
 *	@param[in]  header - mime entity header 
 *	@param[in]  sdbody - mime entity shadow body 
 *	@param[out] None 
 *	@return	    None 
 *	@note		The function can be called repeatedly, but only to save the last settings 
 *	@note		The function SHOULD BE used as a leaf node setting 
 *	@note		The header will be filtered when set an non-mime-entity header
 **/
void mime_entity::set_node(class mime_header &header, const class body_shadow &sdbody)
{
	this->header = check_header(header);
	this->sdbody = sdbody;		 return;
}

/**
 *	@brief	    Set mime enity part which under the param 'header' 
 *	@param[in]  header - mime entity (part father's) header
 *	@param[out] None 
 *	@return		mime entity part pointer OR NULL if subtype 'mixed' does not exsists
 *
 *	@note		*Param 'header'
 *					1. belong to the part father
 *					2. will be filtered when an non-mime-entity header setted 
 *					3. only to save the first settings when set mutil times
 *
 *	@note		*Multi part depth
 *					1. The function can be called repeatedly, to set sub-part with return pointer OR
 *					   to set brother-part under the same object 
 *					2. Only 'Content-Type' with major-type 'multipart' and subtype 'mixed' can be nested deeply, 
 *					   if not in this case, NULL will be returned
 *
 *	@exception  "Const char *" 'multipart' type does not exsits & 'mixed' subtyp lose
 **/
class mime_entity *mime_entity::set_part(class mime_header &header)
{
	/**----------------------------------------------------------------------------*/
	/**< Nesting check */

	if (false == this->nest) 
	{
		throw("Exception : 'mime_entity.cpp' - 'mixed' subtype lose, connot continue nesting!");
	}

	/**----------------------------------------------------------------------------*/
	/**< Set header */

	if (this->header.is_empty()) {
		this->header = check_header(header);
	}

	/**----------------------------------------------------------------------------*/
	/**< Multi-part check */

	contenttype_body cb(this->header.get_field(CONTENT_TYPE).get_body());

	if (cb.get_major_type() != "multipart")
	{
		throw("Exception : 'mime_entity.cpp' - 'multipart' type does not exsits!");
	}

	this->sdbody.clear();

	/**----------------------------------------------------------------------------*/
	/**< Make part instance */

	class mime_entity *pEntity = new class mime_entity();

	pEntity->nest = (cb.get_minor_type() == "mixed")?true:false;

	this->sdbody.part_entity.push_back(pEntity);
	
	return pEntity;
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
	/**< Mult-part does not exsits (End recursive) */

	if (_big == _end) {_mime_entity = this->header.get(); goto _ADD_NODE_BODY; }

	/**----------------------------------------------------------------------------*/
	/**< Construct AND set boundary AND set header */

	cb.set(this->header.get_field(CONTENT_TYPE).get_body());

	if ("" == (boundary = cb.get_param_value("boundary")))
	{
		boundary = contenttype_body::construct_boundary();
		cb.set_param("boundary", boundary);

		this->header.get_field(CONTENT_TYPE).set_body(&cb);
	}

	_mime_entity  = this->header.get();

	boundary.erase(0, 1);
	boundary.erase(boundary.size() - 1, 1);

	/**----------------------------------------------------------------------------*/
	/**< Recursive sub multi-part */

	while ((_big != _end) && (NULL != *_big))
	{
		_mime_entity += "--" + boundary + "\r\n";

		_mime_entity += (*_big)->make(); _big++;
	}

	_mime_entity += "--" + boundary + "--\r\n";

_ADD_NODE_BODY:
	_mime_entity += *(this->sdbody.bodys);

	/**----------------------------------------------------------------------------*/
	/**< Release eneity */

	list<class mime_entity*>::const_iterator _big_ = this->sdbody.part_entity.begin(),
											 _end_ = this->sdbody.part_entity.  end();
	while (_big_ != _end_)
	{
		delete *_big_; _big_++;
	}

	return _mime_entity; 
}
mime_entity::~mime_entity(){
#if 0
	list<class mime_entity*>::iterator _big =  sdbody.part_entity.begin(), _end = sdbody.part_entity.end();

	while (_big != _end)
	{
		delete *_big; *_big = NULL;
		_big++;
	}
#endif
}

/**
 *	@brief	    Load mime entity from some string buffer 
 *	@param[in]  _eneity - entity buffer 
 *	@param[in]  _size   - size of entity buffer
 *	@param[out] None 
 *	@return	    ture/flase 
 **/
bool load(const char *_eneity, string::size_type _size)
{


	return false;
}


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
 *	@brief	    Set mime header for mime entity 
 *	@param[in]  header - mime entity header 
 *	@param[out] None 
 *	@return	    None 
 *	@note		The function can be called repeatedly, but leave only the last settings
 **/
void mime_entity::set_header(const class mime_header &header)
{
	this->header = header;
	return;
}

/**
 *	@brief	    Set mime body(s) for mime entity 
 *	@param[in]  _body - mime entity body 
 *	@param[out] None 
 *	@return	    None 
 *	@note		The function can be called repeatedly, but leave only the last settings
 *	@note		Continue setting with the return value, if multi part should be setted 
 **/
class mime_entity *mime_entity::set_body(const class mime_body &_body)
{
	this->_body = _body;	

	class mime_entity *pEntity = new class mime_entity;

	this->_body.part_entity.push_back(pEntity);

	return pEntity; //*(this->_body.part_entity.rbegin());
}

/**
 *	@brief	    Get mime header from mime entity 
 *	@param[in]  None 
 *	@param[out] None 
 *	@return	    mime header of the mime entity 
 **/
const class mime_header &mime_entity::get_header(void) const noexcept
{
	return this->header;
}
		
/**
 *	@brief	    Get mime body(s) from mime entity 
 *	@param[in]  None 
 *	@param[out] None 
 *	@return	    mime body(s) of the mime entity 
 **/
const class mime_body &mime_entity::get_body(void) const noexcept
{
	return this->_body;
}

/**
 *	@brief	    class mime_entity destructure 
 *	@param[in]  None 
 *	@param[out] None 
 *	@return	    None 
 **/
mime_entity::~mime_entity()
{
	list<class mime_entity*>::iterator _big = this->_body.part_entity.begin();	
	list<class mime_entity*>::iterator _end = this->_body.part_entity.  end();	

	while ((_big != _end) && (NULL != *_big))
	{
		delete *_big; _big++;
	}
}

/**
 *	@brief	    Get string of mime entity 
 *	@param[in]  None 
 *	@param[out] None 
 *	@return	    String of mime entity 
 **/
const string mime_entity::get(void) const noexcept
{
	string _mime_entity;

	_mime_entity  = this->header.get();
	_mime_entity += (this->_body.preamble.empty())?"":(this->_body.preamble + "\r\n");
	_mime_entity += *(this->_body.bodys); 

	list<class mime_entity*>::const_iterator _big = this->_body.part_entity.begin();	
	list<class mime_entity*>::const_iterator _end = this->_body.part_entity.  end();	

	while ((_big != _end) && (NULL != *_big))
	{
		_mime_entity += (*_big)->get();
		_big++;
	}

	_mime_entity += (this->_body.epilogue.empty())?"":(this->_body.epilogue + "\r\n");

	return _mime_entity; 
}


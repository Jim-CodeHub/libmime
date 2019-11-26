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
 *	@brief	    Get mime header from mime entity 
 *	@param[in]  None 
 *	@param[out] None 
 *	@return	    mime header of mime entity 
 **/
void mime_entity::set(const class mime_header &header, const class mime_body &body)
{
	this->header = header;
	this->body   = body  ;

	return;
}

mime_entity::mime_entity(const class mime_header &header, const class mime_body &body)
{
	this->set(header, body);
}

/**
 *	@brief	    Get mime header from mime entity 
 *	@param[in]  None 
 *	@param[out] None 
 *	@return	    mime header of mime entity 
 **/
const class mime_header &mime_entity::get_header(void) const noexcept
{
	return this->header;
}

/**
 *	@brief	    Get mime body from mime entity 
 *	@param[in]  None 
 *	@param[out] None 
 *	@return	    mime body of mime entity 
 **/
const class mime_body &mime_entity::get_body(void) const noexcept
{
	return this->body;
}

/**
 *	@brief	    Get mime entity 
 *	@param[in]  None 
 *	@param[out] None 
 *	@return	    mime entity 
 *	@note		The function is slow, use is if necessary
 **/
const string mime_entity::get(void) const noexcept
{
	return (this->header.get() + this->body.get());
}


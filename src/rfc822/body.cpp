/**-----------------------------------------------------------------------------------------------------------------
 * @file	body.cpp
 * @brief	Standrad for ARPA Ineternet text messages	
 * @ref		IETF-rfc822
 *
 * Copyright (c) 2019-2019 Jim Zhang 303683086@qq.com
 *------------------------------------------------------------------------------------------------------------------
*/

#include <libMIME/src/rfc822/body.hpp>

using namespace NS_LIBMIME;


/*
--------------------------------------------------------------------------------------------------------------------
*
*			                                  FUNCTIONS IMPLEMENT
*
--------------------------------------------------------------------------------------------------------------------
*/

/**
 *	@brief	    Structure, set match string 
 *	@param[in]  field_name 
 *	@param[out] None
 *	@return		None
 **/

/**
 *	@brief	    Set string body 
 *	@param[in]  _body - string body 
 *	@param[out] None
 *	@return		None
 **/
void body::set(const string &_body)
{ 
	this->bodys.assign(_body);
	return;	
}

body::body(const string &_body) { this->set(_body); }

/**
 *	@brief	    Set string body 
 *	@param[in]  _body - string body 
 *	@param[in]  _size - size of string body 
 *	@param[out] None
 *	@return		None
 **/
void body::set(const char *_body, string::size_type _size)
{
	string _body_(_body, _size);

	this->set(_body_); return;
}

body::body(const char *body, string::size_type _size)
{
	this->set(body, _size);
}

/**
 *	@brief	    Get string body 
 *	@param[in]  None 
 *	@param[out] None
 *	@return		string body	
 **/
const string &body::get(void) const noexcept
{
	return bodys;
}


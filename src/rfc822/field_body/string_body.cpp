/**-----------------------------------------------------------------------------------------------------------------
 * @file	string_body.cpp
 * @brief	Standrad for ARPA Ineternet text messages	
 * @ref		IETF-rfc822
 *
 * Copyright (c) 2019-2019 Jim Zhang 303683086@qq.com
 *------------------------------------------------------------------------------------------------------------------
*/


#include <libMIME/src/rfc822/field_body/string_body.hpp>

using namespace NS_LIBMIME;


/*
--------------------------------------------------------------------------------------------------------------------
*
*			                                  FUNCTIONS IMPLEMENT
*
--------------------------------------------------------------------------------------------------------------------
*/

/**
 *	@brief	    Set string body 
 *	@param[in]  body - string body 
 *	@param[out] None
 *	@return		None
 **/
void string_body::set(const string &body)
{
	this->body = body;
	return;
}

string_body::string_body(const string &body) { this->set(body); }

/**
 *	@brief	    Set string body 
 *	@param[in]  body - string body 
 *	@param[out] None
 *	@return		None
 *	@note		The string param 'body' must end with '\0'
 **/
void string_body::set(const char *body)
{
	this->set(body, strlen(body));
	return;
}

string_body::string_body(const char *body) { this->set(body); }

/**
 *	@brief	    Set string body 
 *	@param[in]  body - string body 
 *	@param[in]  body - sizeof string body 
 *	@param[out] None
 *	@return		None
 **/
void string_body::set(const char *body, string::size_type _size)
{
	this->body.clear();
	this->body.assign(body, _size);

	return;
}

string_body::string_body(const char *body, string::size_type _size) { this->set(body, _size); }

/**
 *	@brief	    Get string body 
 *	@param[in]  None 
 *	@param[out] None
 *	@return		None
 **/
const string &string_body::get(void) const noexcept 
{
	return body;
}


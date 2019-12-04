/**-----------------------------------------------------------------------------------------------------------------
 * @file	string_body.cpp
 * @brief	Standrad for ARPA Ineternet text messages	
 * @ref		IETF-rfc822
 *
 * Copyright (c) 2019-2019 Jim Zhang 303683086@qq.com
 *------------------------------------------------------------------------------------------------------------------
*/


#include <libmime/rfc822/field_body/string_body.hpp>

using namespace NS_LIBMIME;


/*
--------------------------------------------------------------------------------------------------------------------
*
*			                                  VARIABLES DECLARATION
*
--------------------------------------------------------------------------------------------------------------------
*/
const string string_body::lable = "string";


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
	string::size_type i = 0;

	while ((i < body.length()) && ((' ' == body[i]) || ('\t' == body[i])))
		i++; /**< Skip LWSP befor field body */

	this->body.assign(body, i, body.length());

	return;
}

string_body::string_body(const string &body) { this->set(body); }

/**
 *	@brief	    Set string body 
 *	@param[in]  body - string body 
 *	@param[in]  body - sizeof string body 
 *	@param[out] None
 *	@return		None
 **/
void string_body::set(const char *body, string::size_type _size)
{
	string _body(body, _size);
	
	this->set(_body);  return;
}

string_body::string_body(const char *body, string::size_type _size)
{
	this->set(body, _size);
}

/**
 *	@brief	    Clone a heap instance for field_body
 *	@param[in]  None 
 *	@param[out] None
 *	@return	    Pointer to heap instance	
 **/
field_body *string_body::clone() const
{
	return new string_body(*this);
}


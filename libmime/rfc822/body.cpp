/**-----------------------------------------------------------------------------------------------------------------
 * @file	body.cpp
 * @brief	Standrad for ARPA Ineternet text messages	
 * @ref		IETF-rfc822
 *
 * Copyright (c) 2019-2019 Jim Zhang 303683086@qq.com
 *------------------------------------------------------------------------------------------------------------------
*/

#include <libmime/rfc822/body.hpp>

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
void body::set(const string &body)
{ 
	this->bodys->assign(body + "\r\n");
	return;	
}

body::body(const string &body) { this->set(body); }

/**
 *	@brief	    Set string body 
 *	@param[in]  body - string body 
 *	@param[in]  _size - size of string body 
 *	@param[out] None
 *	@return		None
 *	@note		param '_size' is to prevent the 'body' not ending in '\0' 
 *				or 
 *				having '\0' truncated in binary data
 **/
void body::set(const char *body, string::size_type _size)
{
	string _body_(body, _size);

	this->set(_body_); return;
}

body::body(const char *body, string::size_type _size)
{
	this->set(body, _size);
}

/**
 *	@brief	    Operator '=' overloading 
 *	@param[in]  _body
 *	@param[out] None
 *	@return	    Reference class body	
 **/
const class body &body::operator=(const class body &_body)
{
	*(this->bodys) = *(_body.bodys);

	//this->_size = _body.bodys->size();
	//this->bodys->assign(*(_body.bodys), 0, _size);

	return _body;
}

/**
 *	@brief	    Get string body 
 *	@param[in]  None 
 *	@param[out] None
 *	@return		string body	
 **/
const string &body::get(void) const noexcept
{
	return *bodys;
}

/**
 *	@brief	    Clear body 
 *	@param[in]  None 
 *	@param[out] None
 *	@return		None	
 **/
void body::clear(void) { this->bodys->clear(); }

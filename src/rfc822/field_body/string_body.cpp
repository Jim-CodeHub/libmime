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

/**
 *	@brief	    Unfold string body 
 *	@param[in]  None 
 *	@param[out] None
 *	@return	    string body	which has been unfolded
 **/
const string &string_body::unfold(void) noexcept
{
	string::iterator _big = body.begin(), _end = body.end();

	string::size_type index = 0; 

	while(string::npos != (index = body.find("\r\n", index))) /**< Point to '\r' */
	{
		string::iterator _big_ = _big  + index; 
		string::iterator _inx_ = _big_ + 2    ; /**< Skip '*\r\n' */

		while((_inx_ != _end) && (('\t' == *_inx_) || (' ' == *_inx_)))
			_inx_++; /**< Skip SPACE or HTab */

		if (_big_ + 2 == _inx_) { break; }  /**< There are no HT or SPACE' after CRLF  */ 

		body.replace(_big_, _inx_, 1, ' '); /**< Replace CRLF + 1*LWSP_char with SPACE */
	}

	return  body;
}

/**
 *	@brief	    Unfold string body 
 *	@param[in]  body 
 *	@param[out] body 
 *	@return	    None 
 **/
const void string_body::unfold(string &body)
{
	string::iterator _big = body.begin(), _end = body.end();

	string::size_type index = 0; 

	while(string::npos != (index = body.find("\r\n", index))) /**< Point to '\r' */
	{
		string::iterator _big_ = _big  + index; 
		string::iterator _inx_ = _big_ + 2    ; /**< Skip '*\r\n' */

		while((_inx_ != _end) && (('\t' == *_inx_) || (' ' == *_inx_)))
			_inx_++; /**< Skip SPACE or HTab */

		if (_big_ + 2 == _inx_) { break; }  /**< There are no HT or SPACE' after CRLF  */ 

		body.replace(_big_, _inx_, 1, ' '); /**< Replace CRLF + 1*LWSP_char with SPACE */
	}

	return;
}

/**
 *	@brief	    Unfold string body 
 *	@param[in]  body 
 *	@param[out] None 
 *	@return	    string body	which has been unfolded
 **/
string string_body::unfold(const char *body, string::size_type _size)
{
	string _body(body, _size);

	string_body::unfold(_body);

	return _body;
}


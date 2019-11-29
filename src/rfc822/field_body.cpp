/**-----------------------------------------------------------------------------------------------------------------
 * @file	field_body.cpp
 * @brief	Standrad for ARPA Ineternet text messages	
 * @ref		IETF-rfc822
 *
 * Copyright (c) 2019-2019 Jim Zhang 303683086@qq.com
 *------------------------------------------------------------------------------------------------------------------
*/


#include <libMIME/src/rfc822/field_body.hpp>

using namespace NS_LIBMIME;


/*
--------------------------------------------------------------------------------------------------------------------
*
*			                                  FUNCTIONS IMPLEMENT
*
--------------------------------------------------------------------------------------------------------------------
*/

/**
 *	@brief	    Unfold field body 
 *	@param[in]  body 
 *	@param[out] None 
 *	@return	    field body which has been unfolded
 **/
const string field_body::unfold(const string &body)
{
	string _body = body;
	string::iterator _big = _body.begin(), _end = _body.end();

	string::size_type index = 0; 

	while (string::npos != (index = _body.find("\r\n", index))) /**< Point to '\r' */
	{
		string::iterator _big_ = _big  + index; 
		string::iterator _inx_ = _big_ + 2    ; /**< Skip '*\r\n' */

		while ((_inx_ != _end) && (('\t' == *_inx_) || (' ' == *_inx_)))
			_inx_++; /**< Skip SPACE or HTab */

		if (_big_ + 2 == _inx_) { break; }  /**< There are no HT or SPACE' after CRLF  */ 

		_body.replace(_big_, _inx_, 1, ' '); /**< Replace CRLF + 1*LWSP_char with SPACE */
	}

	return _body;
}

/**
 *	@brief	    Unfold field body 
 *	@param[in]  body 
 *	@param[out] None 
 *	@return	    field body which has been unfolded
 **/
const string field_body::unfold(const char *body, string::size_type _size)
{
	string _body(body, _size);

	return field_body::unfold(_body);
}

/**
 *	@brief	    Unfold field body 
 *	@param[in]  body 
 *	@param[out] None 
 *	@return	    field body which has been unfolded
 *	@note		The string param 'body' must end with '\0'
 **/
const string field_body::unfold(const char *body)
{
	string _body(body, strlen(body));

	return field_body::unfold(_body);
}


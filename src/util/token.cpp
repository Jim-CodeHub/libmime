/**-----------------------------------------------------------------------------------------------------------------
 * @file	token.cpp
 * @brief   token utility tool
 *
 * Copyright (c) 2019-2019 Jim Zhang 303683086@qq.com
 *------------------------------------------------------------------------------------------------------------------
*/

#include <libMIME/src/util/token.hpp>

using namespace NS_LIBMIME;


/*
--------------------------------------------------------------------------------------------------------------------
*
*			                                  FUNCTIONS IMPLEMENT
*
--------------------------------------------------------------------------------------------------------------------
*/
/**
 *	@brief	    Split string 
 *	@param[in]  str	  - the string to be splited
 *	@param[in]  delim - delimiter 
 *	@param[out] None
 *	@return	    None 
 **/
void string_token::set(const string &str, const string &delim)
{
	string::size_type _inx_prev = 0, _inx_next = 0;

	while (string::npos != (_inx_next = str.find(delim, _inx_prev)))
	{
		this->stoks.push_back(str.substr(_inx_prev, _inx_next - _inx_prev));

		_inx_prev = _inx_next + 1;
	}

	if ((string::npos == _inx_next) && (0 == _inx_prev))
		this->stoks.push_back(""); /**< Push the empty string */
	else
		this->stoks.push_back(str.substr(_inx_prev, _inx_next - _inx_prev)); /**< Push the last substring */

	return;
}

string_token::string_token(const string &str, const string &delim)
{
	this->set(str, delim);
}

string_token::string_token(const string &str, const char *delim, string::size_type _dSize)
{
	string _delim(delim, _dSize);	
	this->set(str      , _delim);
}

string_token::string_token(const string &str, const char *delim)
{
	string _delim(delim, strlen(delim));	
	this->set(str      , _delim       );
}

/**
 *	@brief		Get string token from token vector
 *	@param[in]  pos - position of string in vector 
 *	@param[out] None
 *	@return	    split string OR "" 
 *	@note		
 **/
const string string_token::get_stok(string::size_type pos) const noexcept
{
	return (pos >= stoks.size())?"":stoks.at(pos); 
}


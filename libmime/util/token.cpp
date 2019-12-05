/**-----------------------------------------------------------------------------------------------------------------
 * @file	token.cpp
 * @brief   token utility tool
 *
 * Copyright (c) 2019-2019 Jim Zhang 303683086@qq.com
 *------------------------------------------------------------------------------------------------------------------
*/

#include <libmime/util/token.hpp>

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
 *	@note		*** TO BE SURE param 'str' has certain size info, If str contain '\0' 
 **/
void string_token::set(const string &str, const string &delim)
{
	string::size_type _inx_prev = 0, _inx_next = 0;

	while (string::npos != (_inx_next = str.find(delim, _inx_prev)))
	{
		this->stoks.push_back(str.substr(_inx_prev, _inx_next - _inx_prev));

		_inx_prev = _inx_next + delim.size();
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

/**
 *	@brief	    Split string (MAY BE oct that contain '\0')
 *	@param[in]  str	  - the string to be splited
 *	@param[in]  _size - size of split string 
 *	@param[in]  delim - delimiter 
 *	@param[out] None
 *	@return	    None 
 **/
void string_token::set(const char *str, string::size_type _size, const string &delim)
{
	string _str(str, _size);
	this->set(_str, delim );

	return;
}

string_token::string_token(const char *str, string::size_type _size, const string &delim)
{
	this->set(str, _size, delim);
}

/**
 *	@brief	    Split string (MAY BE oct that contain '\0')
 *	@param[in]  str	  - the string to be splited
 *	@param[in]  _size - size of split string 
 *	@param[in]  delim - delimiter 
 *	@param[in]  _dsize - size of delimeter 
 *	@param[out] None
 *	@return	    None 
 **/
void string_token::set(const char *str, string::size_type _size, const char *delim, string::size_type _dsize)
{
	const char *_big = str, *_nxt = str;

	while ((_size >= 0) && (_size >= _dsize))
	{
		if (0 == memcmp(_nxt, delim, _dsize))
		{
			string str_tok; str_tok.assign(_big, _nxt - _big);
			this->stoks.push_back(str_tok);

			_nxt += _dsize; _size -= _dsize; _big = _nxt;
			continue;
		}

		_nxt++, _size--;
	}

	string str_tok(_big, _nxt + _size - _big);
	this->stoks.push_back(str_tok);

	return;
}

string_token::string_token(const char *str, string::size_type _size, const char *delim, string::size_type _dsize)
{
	this->set(str, _size, delim, _dsize);
}

/**
 *	@brief	    Split string from delim into two part
 *	@param[in]  str	  - the string to be splited
 *	@param[in]  delim - delimiter 
 *	@param[out] None
 *	@return	    None 
 *	@note		*** TO BE SURE param 'str' has certain size info, If str contain '\0' 
 **/
void string_token::cut(const string &str, const string &delim)
{
	string::size_type _inx_prev = 0, _inx_next = 0;

	if (string::npos != (_inx_next = str.find(delim, _inx_prev)))
	{
		this->stoks.push_back(str.substr(_inx_prev, _inx_next - _inx_prev));

		_inx_prev = _inx_next + delim.size();
	}

	if ((string::npos == _inx_next) && (0 == _inx_prev))
		this->stoks.push_back(""); /**< Push the empty string */
	else
		this->stoks.push_back(str.substr(_inx_prev, _inx_next - _inx_prev)); /**< Push the last substring */

	return;
}

/**
 *	@brief	    Split string from delim into two part
 *	@param[in]  str	  - the string to be splited
 *	@param[in]  delim - delimiter 
 *	@param[out] None
 *	@return	    None 
 **/
void string_token::cut(const char *str, string::size_type _size, const string &delim)
{
	string _str(str, _size);
	this->set(_str, delim );

	return;
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


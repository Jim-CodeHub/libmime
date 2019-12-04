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
 *	@note		Dangerous interfase : body MAY having '\0' truncated in binary data
 **/
void body::set(const string &body)
{ 
	this->bodys->assign(body + "\r\n");
	this->_size = body.size();

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
	this->bodys->assign(body, _size);
	this->bodys->append("\r\n");

	this->_size = _size;

	return;
}

body::body(const char *body, string::size_type _size)
{
	this->set(body, _size);
}

/**
 *	@brief	    Load file content to body 
 *	@param[in]  file_path - file path with name 
 *	@param[in]  offset	  - the postion to load from 
 *	@param[in]  _size	  - the size to load 
 *	@param[out] None
 *	@return	    None 
 *	@note		1. if offset already exceeds the file content length, the function will do nothing
 *				2. if set param '_size' with -1, the function will load the entire file
 *
 *	@exception  "Const char *", file open error
 **/
void body::load(const char *file_path, string::size_type offset, long int _size)
{
	FILE *pFILE = fopen(file_path, "r");

	this->bodys->clear(); this->_size = 0;

	if (-1 == fseek(pFILE, offset, SEEK_SET)) {
		goto _EXIT;
	}

	if (NULL == pFILE) {
		throw ("Exception : 'body.cpp' - file open error!");
	}

	int ch;
	while ((EOF != (ch = fgetc(pFILE)) && (0 != _size)))
	{
		this->bodys->push_back(ch);
		this->_size++;     

		_size -= (-1 == _size)?0:1;
	}

_EXIT:
	return;
}

/**
 *	@brief	    Write body conent to file
 *	@param[in]  file_path - file path with name 
 *	@param[out] None
 *	@return	    None 
 *	@exception  "Const char *", file open error, file write error
 **/
void body::fill(const char *file_path)
{
	FILE *pFILE = fopen(file_path, "w");

	if (NULL == pFILE) {
		throw ("Exception : 'body.cpp' - file open error!" );
	}

	char *buff = new char[this->_size];

	for (string::size_type i = 0; i < _size; i++)
	{
		buff[i] = (*(this->bodys))[i];
	}

	if (1 != fwrite(buff, this->_size, 1, pFILE)) {
		throw ("Exception : 'body.cpp' - file write error!");
	}

	delete buff;
}

/**
 *	@brief	    Operator '=' overloading 
 *	@param[in]  _body
 *	@param[out] None
 *	@return	    Reference class body	
 **/
const class body &body::operator=(const class body &_body)
{
	this->bodys->assign(*(_body.bodys), 0, _body.size());
	this->_size = _body.size();

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
 *	@brief	    Get body size 
 *	@param[in]  None 
 *	@param[out] None
 *	@return		Size of the body	
 **/
string::size_type body::size(void) const noexcept
{
	return this->_size;
}

/**
 *	@brief	    Clear body 
 *	@param[in]  None 
 *	@param[out] None
 *	@return		None	
 **/
void body::clear(void) { this->bodys->clear(); }


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
 *	@param[in]  body  - string body 
 *	@param[in]  _size - size of body  
 *	@param[out] None
 *	@return		None
 *	@note		param '_size' is to prevent the 'body' not ending in '\0' 
 *				or 
 *				having '\0' truncated in binary data
 **/
void body::set(const string &body, string::size_type _size)
{ 
	this->bodys->assign(body, 0, _size);
	this->bodys->append("\r\n");

	return;	
}

body::body(const string &body, string::size_type _size)
{ 
	this->set(body, _size);
}

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

	this->bodys->clear();

	if (NULL == pFILE) { perror("Exception : file open error"); exit(-1); }

	if (-1 == fseek(pFILE, offset, SEEK_SET)){ goto _EXIT; }

	int ch;
	while ((EOF != (ch = fgetc(pFILE)) && (0 != _size)))
	{
		this->bodys->push_back(ch);
		_size -= (-1 == _size)?0:1;
	}

	fclose(pFILE);

_EXIT:
	return;
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
void body::load(const char *file_path, string::size_type offset, long int _size) const
{
	FILE *pFILE = fopen(file_path, "r");

	this->bodys->clear();

	if (NULL == pFILE) { perror("Exception : file open error"); exit(-1); }

	if (-1 == fseek(pFILE, offset, SEEK_SET)){ goto _EXIT; }

	int ch;
	while ((EOF != (ch = fgetc(pFILE)) && (0 != _size)))
	{
		this->bodys->push_back(ch);
		_size -= (-1 == _size)?0:1;
	}

	fclose(pFILE);

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

	string::size_type body_size = this->bodys->size();

	if (1 != fwrite(this->bodys->data(), body_size, 1, pFILE)) {
		throw ("Exception : 'body.cpp' - file write error!");
	}

	fflush(pFILE);
	fclose(pFILE); return;
}

/**
 *	@brief	    Write body conent to file
 *	@param[in]  file_path - file path with name 
 *	@param[out] None
 *	@return	    None 
 *	@exception  "Const char *", file open error, file write error
 **/
void body::fill(const char *file_path) const
{
	FILE *pFILE = fopen(file_path, "w");

	if (NULL == pFILE) {
		throw ("Exception : 'body.cpp' - file open error!" );
	}

	string::size_type body_size = this->bodys->size();

	if (1 != fwrite(this->bodys->data(), body_size, 1, pFILE)) {
		throw ("Exception : 'body.cpp' - file write error!");
	}

	fflush(pFILE);
	fclose(pFILE); return;
}

/**
 *	@brief	    Operator '=' overloading 
 *	@param[in]  _body
 *	@param[out] None
 *	@return	    Reference class body	
 **/
const class body &body::operator=(const class body &_body)
{
	this->bodys->assign(*(_body).bodys);

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
 *	@brief	    Get string body size
 *	@param[in]  None 
 *	@param[out] None
 *	@return		body size
 **/
ssize_t  body::size(void) const noexcept
{
	return this->bodys->size();
}

/**
 *	@brief	    Clear body 
 *	@param[in]  None 
 *	@param[out] None
 *	@return		None	
 **/
void body::clear(void) 
{ 
	if (NULL != this->bodys)
	{
		this->bodys->clear();
	}
}


/**-----------------------------------------------------------------------------------------------------------------
 * @file	codec.cpp
 * @brief	Multi-purpose mail extensions	
 * @ref		IETF-rfc2045, rfc2046, rfc2047, rfc2048, rfc2049 
 *
 * Copyright (c) 2019-2019 Jim Zhang 303683086@qq.com
 *------------------------------------------------------------------------------------------------------------------
*/

#include <libmime/codec/codec.hpp>

//using namespace NS_LIBMIME;


/*
--------------------------------------------------------------------------------------------------------------------
*
*			                                  FUNCTIONS IMPLEMENT
*
--------------------------------------------------------------------------------------------------------------------
*/

/**
 *	@brief	    Encode string with method 'code'
 *	@param[in]  code  
 *	@param[in]  src - source string 
 *	@param[out] des - destination string 
 *	@return		None
 *	@note		1. To be sure that param 'src' has exact size info 
 *				2. If no alternative encryption is availiable, the 'src' is assigned directly to the 'des'
 **/
void codec::encode(enum _codec code, const string &src, string &des)
{
	switch (code)
	{
		case BASE64:
			base64_encode(src,  des);
							   break;
		case QUOTED_PRINTABLE: break;
		case _7BIT:			   //break;
		case _8BIT:			   //break;
		case BINARY:		   //break;

		default:des.assign(src     ); /**< Assign source string directly */
	}

	return;
}

/**
 *	@brief	    Encode string with method 'code'
 *	@param[in]  code  
 *	@param[in]  src - source string 
 *	@param[out] des - destination string 
 *	@return		None
 *	@note		1. To be sure that param 'src' has exact size info 
 *				2. If no alternative encryption is availiable, the 'src' is assigned directly to the 'des'
 **/
void codec::encode(const string &code, const string &src, string &des)
{
	string method[] = {"base64", "quoted_printable", "7bit", "8bit", "binary"};

	string::size_type i = 0;
	while ((i != sizeof(method)) && (method[i] != code))
		i++;

	this->encode((enum _codec)i, src, des);

	return;
}

/**
 *	@brief	    Encode string with method 'code'
 *	@param[in]  code  
 *	@param[in]  src   - source string 
 *	@param[in]  _size - size of source string
 *	@param[out] des - destination string 
 *	@return		None
 *	@note		1. To be sure that param 'src' has exact size info 
 *				2. If no alternative encryption is availiable, the 'src' is assigned directly to the 'des'
 **/
void codec::encode(enum _codec code, const char *src, string::size_type _size, char *des)
{
	switch (code)
	{
		case BASE64:
			base64_encode(src, _size, des);
							   break;
		case QUOTED_PRINTABLE: break;
		case _7BIT:			   //break;
		case _8BIT:			   //break;
		case BINARY:		   //break;

		default:memcpy(des, src, _size); /**< Assign source string directly */
	}

	return;
}

/**
 *	@brief	    Encode string with method 'code'
 *	@param[in]  code  
 *	@param[in]  src   - source string 
 *	@param[in]  _size - size of source string
 *	@param[out] des - destination string 
 *	@return		None
 *	@note		1. To be sure that param 'src' has exact size info 
 *				2. If no alternative encryption is availiable, the 'src' is assigned directly to the 'des'
 **/
void codec::encode(const string &code, const char *src, string::size_type _size, char *des) 
{
	string method[] = {"base64", "quoted_printable", "7bit", "8bit", "binary"};

	string::size_type i = 0;
	while ((i != sizeof(method)) && (method[i] != code))
		i++;

	this->encode((enum _codec)i, src, _size, des);
	
	return;
}

/**
 *	@brief	    Decode string with method 'code'
 *	@param[in]  code  
 *	@param[in]  src - source string 
 *	@param[out] des - destination string 
 *	@return		None
 **/
void codec::decode(enum _codec code, const string &src, string &des)
{
	switch (code)
	{
		case BASE64:
			base64_decode(src, des );
							   break;
		case QUOTED_PRINTABLE: break;
		case _7BIT:			   //break;
		case _8BIT:			   //break;
		case BINARY:		   //break;

		default:des.assign(src     ); /**< Assign source string directly */
	}

	return;
}

/**
 *	@brief	    Decode string with method 'code'
 *	@param[in]  code  
 *	@param[in]  src - source string 
 *	@param[out] des - destination string 
 *	@return		None
 **/
void codec::decode(const string &code, const string &src, string &des)
{
	string method[] = {"base64", "quoted_printable", "7bit", "8bit", "binary"};

	string::size_type i = 0;
	while ((i != sizeof(method)) && (method[i] != code))
		i++;

	this->decode((enum _codec)i, src, des);

	return;
}

/**
 *	@brief	    Decode string with method 'code'
 *	@param[in]  code  
 *	@param[in]  src   - source string 
 *	@param[out] des	  - destination string 
 *	@param[out] _size - size of destination string 
 *	@return		None
 **/
void codec::decode(enum _codec code, const char *src, char *des, string::size_type &_size)
{
	switch (code)
	{
		case BASE64:
			base64_decode(src, des, _size);
							   break;
		case QUOTED_PRINTABLE: break;
		case _7BIT:			   //break;
		case _8BIT:			   //break;
		case BINARY:		   //break;

		default:memcpy(des, src, (_size = strlen(src))); /**< Assign source string directly */
	}

	return;
}

/**
 *	@brief	    Decode string with method 'code'
 *	@param[in]  code  
 *	@param[in]  src   - source string 
 *	@param[out] des	  - destination string 
 *	@param[out] _size - size of destination string 
 *	@return		None
 **/
void codec::decode(const string &code, const char *src, char *des, string::size_type &_size)
{
	string method[] = {"base64", "quoted_printable", "7bit", "8bit", "binary"};

	string::size_type i = 0;
	while ((i != sizeof(method)) && (method[i] != code))
		i++;

	this->decode((enum _codec)i, src, des, _size);
}


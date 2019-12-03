/**-----------------------------------------------------------------------------------------------------------------
 * @file	codec.cpp
 * @brief	Multi-purpose mail extensions	
 * @ref		IETF-rfc2045, rfc2046, rfc2047, rfc2048, rfc2049 
 *
 * Copyright (c) 2019-2019 Jim Zhang 303683086@qq.com
 *------------------------------------------------------------------------------------------------------------------
*/

#include <libMIME/src/codec/codec.hpp>

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
 *	@param[in]  len - length of source string 
 *	@return		None
 *	@note		Param 'len' is designed for source string that MAY contain '\0' 
 **/
void codec::encode(enum _codec code, const string &src, string &des, string::size_type len) 
{
	switch (code)
	{
		case BASE64:
			base64_encode(src, len, des);
							   break;
		case QUOTED_PRINTABLE: break;
		case _7BIT:			   break;
		case _8BIT:			   break;
		case BINARY:		   break;
		default:                    ;
	}

	return;
}

void codec::encode(const string &code, const string &src, string &des, string::size_type len) 
{
	string method[] = {"base64", "quoted_printable", "7bit", "8bit", "binary"};

	string::size_type i = 0;
	while ((i != sizeof(method)) && (method[i] != code))
		i++;

	this->encode((enum _codec)i, src, des, len);
}

/**
 *	@brief	    Decode string with method 'code'
 *	@param[in]  code  
 *	@param[in]  src - source string 
 *	@param[out] des - destination string 
 *	@param[out] len - length of string that has been decoded
 *	@return		None
 *	@note		Param 'len' is designed for destination string that MAY contain '\0' 
 **/
void codec::decode(enum _codec code, const string &src, string &des, string::size_type &len)
{
	switch (code)
	{
		case BASE64:
			base64_decode(src, des, len);
							   break;
		case QUOTED_PRINTABLE: break;
		case _7BIT:			   break;
		case _8BIT:			   break;
		case BINARY:		   break;
		default:                    ;
	}

	return;
}

void codec::decode(const string &code, const string &src, string &des, string::size_type &len)
{
	string method[] = {"base64", "quoted_printable", "7bit", "8bit", "binary"};

	string::size_type i = 0;
	while ((i != sizeof(method)) && (method[i] != code))
		i++;

	this->decode((enum _codec)i, src, des, len);

	return;
}


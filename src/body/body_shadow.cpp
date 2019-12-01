/**-----------------------------------------------------------------------------------------------------------------
 * @file	body_shadow.cpp
 * @brief	Multi-purpose mail extensions	
 * @ref		IETF-rfc2045, rfc2046, rfc2047, rfc2048, rfc2049 
 *
 * Copyright (c) 2019-2019 Jim Zhang 303683086@qq.com
 *------------------------------------------------------------------------------------------------------------------
*/

#include <libMIME/src/body/body_shadow.hpp>

using namespace NS_LIBMIME;


/*
--------------------------------------------------------------------------------------------------------------------
*
*			                                  FUNCTIONS IMPLEMENT
*
--------------------------------------------------------------------------------------------------------------------
*/

/**
 *	@brief	    Encode mime body
 *	@param[in]  code - codec method 
 *	@param[out] None 
 *	@return	    None 
 **/
void body_shadow::encode(enum codec code)
{
	string code_data;

	switch (code)
	{
		case BASE64:
			base64_encode((const unsigned char *)this->bodys->c_str(), code_data);
							   break;
		case QUOTED_PRINTABLE: break;
		case _7BIT:			   break;
		case _8BIT:			   break;
		case BINARY:		   break;
		default:                    ;
	}

	this->set(code_data); return;
}

/**
 *	@brief	    Decode mime body
 *	@param[in]  code - codec method 
 *	@param[out] None 
 *	@return	    None 
 **/
void body_shadow::decode(enum codec code)
{
	string code_data;

	switch (code)
	{
		case BASE64:
			base64_decode(this->bodys->c_str(), code_data);
							   break;
		case QUOTED_PRINTABLE: break;
		case _7BIT:			   break;
		case _8BIT:			   break;
		case BINARY:		   break;
		default:                    ;
	}

	this->set(code_data); return;
}


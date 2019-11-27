/**-----------------------------------------------------------------------------------------------------------------
 * @file	mime_body.cpp
 * @brief	Multi-purpose mail extensions	
 * @ref		IETF-rfc2045, rfc2046, rfc2047, rfc2048, rfc2049 
 *
 * Copyright (c) 2019-2019 Jim Zhang 303683086@qq.com
 *------------------------------------------------------------------------------------------------------------------
*/

#include <libMIME/src/body/mime_body.hpp>

using namespace NS_LIBMIME;


/*
--------------------------------------------------------------------------------------------------------------------
*
*			                                  FUNCTIONS IMPLEMENT
*
--------------------------------------------------------------------------------------------------------------------
*/

/**
 *	@brief	    Set mime body's preamble 
 *	@param[in]  _preamble 
 *	@param[out] None 
 *	@return	    None 
 **/
void mime_body::set_preamble(const string &_preamble)
{
	this->preamble = _preamble;
	return;
}

/**
 *	@brief	    Set mime body's preamble 
 *	@param[in]  _preamble 
 *	@param[in]  _size - size of _preamble
 *	@param[out] None 
 *	@return	    None 
 **/
void mime_body::set_preamble(const char *_preamble, string::size_type _size)
{
	string _preamble_(_preamble, _size);

	this->set(_preamble_);       return;
}

/**
 *	@brief	    Set mime body's preamble 
 *	@param[in]  _preamble 
 *	@param[out] None 
 *	@return	    None 
 *	@note		String param '_preamble' MUST end with '\0'
 **/
void mime_body::set_preamble(const char *_preamble)
{
	string _preamble_(_preamble, strlen(_preamble));

	this->set(_preamble_);                  return;
}

/**
 *	@brief	    Encode mime body
 *	@param[in]  code - codec method 
 *	@param[out] None 
 *	@return	    None 
 **/
void mime_body::encode(enum codec code)
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
 *	@brief	    Set mime body's epilogue 
 *	@param[in]  _epilogue 
 *	@param[out] None 
 *	@return	    None 
 **/
void mime_body::set_epilogue(const string &_epilogue)
{
	this->epilogue = _epilogue;
	return;
}

/**
 *	@brief	    Set mime body's epilogue 
 *	@param[in]  _epilogue 
 *	@param[in]  _size - size of _epilogue
 *	@param[out] None 
 *	@return	    None 
 **/
void mime_body::set_epilogue(const char *_epilogue, string::size_type _size)
{
	string _epilogue_(_epilogue, _size);

	this->set(_epilogue_);       return;
}

/**
 *	@brief	    Set mime body's epilogue 
 *	@param[in]  _epilogue 
 *	@param[out] None 
 *	@return	    None 
 *	@note		String param '_epilogue' MUST end with '\0'
 **/
void mime_body::set_epilogue(const char *_epilogue)
{
	string _epilogue_(_epilogue, strlen(_epilogue));

	this->set(_epilogue_);                  return;
}


/**
 *	@brief	    Get mime body's preamble 
 *	@param[in]  None 
 *	@param[out] None 
 *	@return	    preamble of the mime body 
 **/
const string &mime_body::get_preamble(void) const noexcept
{
	return this->preamble;
}

/**
 *	@brief	    Get mime body's epilogue 
 *	@param[in]  None 
 *	@param[out] None 
 *	@return	    epilogue of the mime body 
 **/
const string &mime_body::get_epilogue(void) const noexcept
{
	return this->epilogue;
}

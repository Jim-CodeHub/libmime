/**-----------------------------------------------------------------------------------------------------------------
 * @file	mime_message.cpp
 * @brief	Multi-purpose mail extensions	
 * @ref		IETF-rfc2045, rfc2046, rfc2047, rfc2048, rfc2049 
 *
 * Copyright (c) 2019-2019 Jim Zhang 303683086@qq.com
 *------------------------------------------------------------------------------------------------------------------
*/

#include <libmime/mime_message.hpp>

using namespace NS_LIBMIME;


/*
--------------------------------------------------------------------------------------------------------------------
*
*			                                  FUNCTIONS IMPLEMENT
*
--------------------------------------------------------------------------------------------------------------------
*/

/**
 *	@brief	    Set mime message preamble 
 *	@param[in]  _preamble 
 *	@param[out] None 
 *	@return	    None 
 **/
void mime_message::set_preamble(const string &_preamble)
{
	this->preamble = _preamble + "\r\n\r\n";
	return;
}

/**
 *	@brief	    Set mime message preamble 
 *	@param[in]  _preamble 
 *	@param[in]  _size - size of _preamble
 *	@param[out] None 
 *	@return	    None 
 **/
void mime_message::set_preamble(const char *_preamble, string::size_type _size)
{
	string _preamble_(_preamble, _size   );

	this->set_preamble(_preamble_); return;
}

/**
 *	@brief	    Set mime message epilogue 
 *	@param[in]  _epilogue 
 *	@param[out] None 
 *	@return	    None 
 **/
void mime_message::set_epilogue(const string &_epilogue)
{
	this->epilogue = "\r\n\r\n" + _epilogue;
	return;
}

/**
 *	@brief	    Set mime message epilogue 
 *	@param[in]  _epilogue 
 *	@param[in]  _size - size of _epilogue
 *	@param[out] None 
 *	@return	    None 
 **/
void mime_message::set_epilogue(const char *_epilogue, string::size_type _size)
{
	string _epilogue_(_epilogue, _size   );

	this->set_epilogue(_epilogue_); return;
}

/**
 *	@brief	    Get mime message preamble 
 *	@param[in]  None 
 *	@param[out] None 
 *	@return	    preamble of the mime body 
 **/
const string &mime_message::get_preamble(void) const noexcept
{
	return this->preamble;
}

/**
 *	@brief	    Get mime message epilogue 
 *	@param[in]  None 
 *	@param[out] None 
 *	@return	    epilogue of the mime body 
 **/
const string &mime_message::get_epilogue(void) const noexcept
{
	return this->epilogue;
}

/**
 *	@brief	    Make mime message
 *	@param[in]  None 
 *	@param[out] None 
 *	@return	    mime message 
 **/
const string mime_message::make(void)
{
	string message = mime_entity::make();

	string::size_type _inx = message.find("\r\n\r\n");

	message.insert(_inx + 4, this->preamble);
	message.append(this->epilogue);
	
	return message;
}


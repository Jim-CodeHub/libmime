/**-----------------------------------------------------------------------------------------------------------------
 * @file	body_shadow.cpp
 * @brief	Multi-purpose mail extensions	
 * @ref		IETF-rfc2045, rfc2046, rfc2047, rfc2048, rfc2049 
 *
 * Copyright (c) 2019-2019 Jim Zhang 303683086@qq.com
 *------------------------------------------------------------------------------------------------------------------
*/

#include <libmime/body/body_shadow.hpp>

using namespace NS_LIBMIME;


/*
--------------------------------------------------------------------------------------------------------------------
*
*			                                  FUNCTIONS IMPLEMENT
*
--------------------------------------------------------------------------------------------------------------------
*/

/**
 *	@brief	    Operator '=' overloading 
 *	@param[in]  _body
 *	@param[out] None
 *	@return	    _body
 **/
const class body_shadow &body_shadow::operator=(const class body_shadow &_body)
{
	this->bodys->assign(*(_body).bodys);

	return _body;
}


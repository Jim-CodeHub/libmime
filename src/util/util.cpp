/**-----------------------------------------------------------------------------------------------------------------
 * @file	util.cpp
 * @brief   util utility tool
 *
 * Copyright (c) 2019-2019 Jim Zhang 303683086@qq.com
 *------------------------------------------------------------------------------------------------------------------
*/

#include <libMIME/src/util/util.hpp>

using namespace NS_LIBMIME;


/*
--------------------------------------------------------------------------------------------------------------------
*
*			                                  FUNCTIONS IMPLEMENT
*
--------------------------------------------------------------------------------------------------------------------
*/

/**
 *	@brief	    Get CTLs (ASCII control character) 
 *	@param[in]  None 
 *	@param[out] None
 *	@return	    CTLs	
 *	@note		Actually, CTLs contain '\0', but it can not be place correctly at string
 **/
const string util::get_CTLs(void)
{
	string CTLs;

	for (int i = 1; i <= 31; i++)
	{ CTLs += i;			    }

	CTLs += 127; /**< 0 ~ 31 and 127 of ASCII control character*/

	return CTLs;
}

/**
 *	@brief	    Get tspecials
 *	@param[in]  None 
 *	@param[out] None
 *	@return	    tspecials	
 **/
const string util::get_tspecials(void)
{
	string tspecials = "()\\<>\"@,;:/[]?=";

	return tspecials;
}


/**-----------------------------------------------------------------------------------------------------------------
 * @file	util.cpp
 * @brief   util utility tool
 *
 * Copyright (c) 2019-2019 Jim Zhang 303683086@qq.com
 *------------------------------------------------------------------------------------------------------------------
*/

#include <libmime/util/util.hpp>

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

/**
 *	@brief	    Trans string to lower string 
 *	@param[in]  str   - source string 
 *	@param[in]  _size - size of string 
 *	@param[out] None
 *	@return	    lower string 
 **/
const string util::to_lower(const string &str, string::size_type _size)
{
	string _str;
	string::size_type i = 0;

	string::const_iterator _ori_inx = str.begin();

	while (i != _size)
	{
		_str.push_back(::tolower(_ori_inx[i]));

		i++;	
	}

	return _str;
}

/**
 *	@brief	    Trans string to lower string 
 *	@param[in]  str - source string 
 *	@param[out] None
 *	@return	    lower string 
 **/
const string util::to_lower(const string &str)
{
	return util::to_lower(str, str.size());
}

/**
 *	@brief	    Trans string to upper string 
 *	@param[in]  str   - source string 
 *	@param[in]  _size - size of string 
 *	@param[out] None
 *	@return	    upper string 
 **/
const string util::to_upper(const string &str, string::size_type _size)
{
	string _str;
	string::size_type i = 0;

	string::const_iterator _ori_inx = str.begin();

	while (i != _size)
	{
		_str.push_back(::toupper(_ori_inx[i]));

		i++;	
	}

	return _str;
}

/**
 *	@brief	    Trans string to upper string 
 *	@param[in]  str - source string 
 *	@param[out] None
 *	@return	    upper string 
 **/
const string util::to_upper(const string &str)
{
	return util::to_upper(str, str.size());
}


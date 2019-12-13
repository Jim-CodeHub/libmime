/**-----------------------------------------------------------------------------------------------------------------
 * @file	util.hpp
 * @brief   utility tools
 * @ref		IETF-rfc822, IETF-rfc2045, rfc2046, rfc2047, rfc2048, rfc2049 
 *
 * Copyright (c) 2019-2019 Jim Zhang 303683086@qq.com
 *------------------------------------------------------------------------------------------------------------------
*/


#ifndef __LIBMIME_UTIL_HPP__
#define __LIBMIME_UTIL_HPP__


/*------------------------------------------------------------------------------------------------------------------
 *
 *												UTIL INCLUDES
 *
 *------------------------------------------------------------------------------------------------------------------
*/

#include <string>


namespace NS_LIBMIME{

using namespace std ;


/*------------------------------------------------------------------------------------------------------------------
 *
 *												UTIL SHORT ALIAS 
 *
 *------------------------------------------------------------------------------------------------------------------
*/


/*------------------------------------------------------------------------------------------------------------------
 *
 *												UTIL DATA BLOCK
 *
 *------------------------------------------------------------------------------------------------------------------
*/

/**
 *	@brief util class and function set
 *	@note 
 *		Inheritance graph : None
 **/
class util{
	public:
		static const string get_CTLs(void										);
		static const string get_tspecials(void								    );
		static const string to_lower(const string &str							);
		static const string to_lower(const string &str, string::size_type _size );
		static const string to_upper(const string &str							);
		static const string to_upper(const string &str, string::size_type _size );
		
		static bool string_cmp_ci(const string &s1, const string &s2			);
};


} /* namespace NS_LIBMIME */


#endif /*__LIBMIME_UTIL_HPP__*/


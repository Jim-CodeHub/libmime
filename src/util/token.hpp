/**-----------------------------------------------------------------------------------------------------------------
 * @file	token.hpp
 * @brief   tokenity tools
 * @ref		IETF-rfc822, IETF-rfc2045, rfc2046, rfc2047, rfc2048, rfc2049 
 *
 * Copyright (c) 2019-2019 Jim Zhang 303683086@qq.com
 *------------------------------------------------------------------------------------------------------------------
*/


#ifndef __LIBMIME_TOKEN_HPP__
#define __LIBMIME_TOKEN_HPP__


/*------------------------------------------------------------------------------------------------------------------
 *
 *												TOKEN INCLUDES
 *
 *------------------------------------------------------------------------------------------------------------------
*/

#include <string>
#include <cstring>
#include <vector>


namespace NS_LIBMIME{

using namespace std ;


/*------------------------------------------------------------------------------------------------------------------
 *
 *												TOKEN SHORT ALIAS 
 *
 *------------------------------------------------------------------------------------------------------------------
*/


/*------------------------------------------------------------------------------------------------------------------
 *
 *												TOKEN DATA BLOCK
 *
 *------------------------------------------------------------------------------------------------------------------
*/

/**
 *	@brief string_token class and function set
 *	@note 
 *		Inheritance graph : None
 **/
class string_token{
	public:
		string_token(const string &str, const string &delim						   );
		string_token(const string &str, const char *delim, string::size_type _dSize);
		string_token(const string &str, const char *delim						   );

		const string get_stok(string::size_type pos = 0) const noexcept			    ;

	private:
		void set(const string &str, const string &delim							   );
		vector<string> stoks;
};


} /* namespace NS_LIBMIME */


#endif /*__LIBMIME_TOKEN_HPP__*/

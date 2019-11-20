/**-----------------------------------------------------------------------------------------------------------------
 * @file	field.hpp
 * @brief	Standrad for ARPA Ineternet text messages	
 * @ref		IETF-rfc822
 *
 * Copyright (c) 2019-2019 Jim Zhang 303683086@qq.com
 *------------------------------------------------------------------------------------------------------------------
*/


#ifndef __LIBMIME_FIELD_HPP__
#define __LIBMIME_FIELD_HPP__


/*------------------------------------------------------------------------------------------------------------------
 *
 *												FIELD INCLUDES
 *
 *------------------------------------------------------------------------------------------------------------------
*/

#include <string>


namespace NS_LIBMIME{

using namespace std ;


/*------------------------------------------------------------------------------------------------------------------
 *
 *												FIELD SHORT ALIAS 
 *
 *------------------------------------------------------------------------------------------------------------------
*/


/*------------------------------------------------------------------------------------------------------------------
 *
 *												FIELD DATA BLOCK
 *
 *------------------------------------------------------------------------------------------------------------------
*/

/**
 *	@brief field name class and function set
 *	@note 
 *		Inheritance graph : None
 **/
class field{
	public:
		void set(const string &field_name, const string &field_body												   );	
		void set(const char *field_name, string::size_type _nSize, const char *field_body, string::size_type _bSize);
		void set(const string &field_line																		   );	

		const string &get(void) const noexcept																	    ;

		static string get_name(const string &field_line)															;
		static string get_body(const string &field_line)															;

	private:
		string field_line;
};


} /* namespace NS_LIBMIME */


#endif /*__LIBMIME_FIELD_HPP__*/


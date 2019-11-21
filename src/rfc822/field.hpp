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


#include <libMIME/src/rfc822/field_name.hpp>
#include <libMIME/src/rfc822/field_body.hpp>

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
 *	@brief field class and function set
 *	@note 
 *		Inheritance graph : None
 **/
class field{
	public:
		field(){}; /**< Empty structure */
		field(const string &field_name, const string &field_body												   );
		field(const char *field_name, string::size_type _nSize, const char *field_body, string::size_type _bSize   );
		field(const string &field_line																		       );	
		field(const char *field_line, string::size_type _size													   );	
		field(class field_name &name_t, class field_body *pBody_t											       );
		field(const string &field_name, class field_body *pBody_t		    								       );
		field(const char *field_name, string::size_type _size, class field_body *pBody_t				   		   );

		bool operator==(const class field &field_line)																;

		void set(const string &field_name, const string &field_body												   );	
		void set(const char *field_name, string::size_type _nSize, const char *field_body, string::size_type _bSize);
		void set(const string &field_line																		   );	
		void set(const char *field_line, string::size_type _size												   );	
		void set(class field_name &name_t, class field_body *pBody_t											   );
		void set(const string &field_name, class field_body *pBody_t		    								   );
		void set(const char *field_name, string::size_type _size, class field_body *pBody_t				   		   );

		const string &get(void) const noexcept																	    ;

		const string get_name(void) const noexcept																    ;
		const string get_body(void) const noexcept																    ;

		static string get_name(const string &field_line)															;
		static string get_body(const string &field_line)															;

	private:
		string field_line;
};


} /* namespace NS_LIBMIME */


#endif /*__LIBMIME_FIELD_HPP__*/


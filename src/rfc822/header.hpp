/**-----------------------------------------------------------------------------------------------------------------
 * @file	header.hpp
 * @brief	Standrad for ARPA Ineternet text messages	
 * @ref		IETF-rfc822
 *
 * Copyright (c) 2019-2019 Jim Zhang 303683086@qq.com
 *------------------------------------------------------------------------------------------------------------------
*/


#ifndef __LIBMIME_HEADER_HPP__
#define __LIBMIME_HEADER_HPP__


/*------------------------------------------------------------------------------------------------------------------
 *
 *												HEADER INCLUDES
 *
 *------------------------------------------------------------------------------------------------------------------
*/

#include <deque>
#include <algorithm>
#include <libMIME/src/rfc822/field.hpp>


namespace NS_LIBMIME{

using namespace std ;


/*------------------------------------------------------------------------------------------------------------------
 *
 *												HEADER SHORT ALIAS 
 *
 *------------------------------------------------------------------------------------------------------------------
*/


/*------------------------------------------------------------------------------------------------------------------
 *
 *												HEADER DATA BLOCK
 *
 *------------------------------------------------------------------------------------------------------------------
*/

class findIFname;

/**
 *	@brief header class and function set
 *	@note 
 *		Inheritance graph : None
 **/
class header{
	public:
		header(){}; /**< Empty structure */
		header(const class field &field_line																	   );
		header(const class field_name &name_t, const class field_body *pBody_t									   );
		header(const string &field_name, const class field_body *pBody_t		    							   );
		header(const char *field_name, string::size_type _size, const class field_body *pBody_t					   );
		header(const char *field_name, const class field_body *pBody_t											   );

		const class header &operator=(const class header &_header												   );

		void set(const class field &field_line																	   );
		void set(const class field_name &name_t, const class field_body *pBody_t								   );
		void set(const string &field_name, const class field_body *pBody_t		    							   );
		void set(const char *field_name, string::size_type _size, const class field_body *pBody_t			   	   );
		void set(const char *field_name, const class field_body *pBody_t										   );

		const string get_field(const string &field_name) const noexcept												;
		const string get_field(const char *field_name, string::size_type _size) const noexcept						;

		const string get(void) const noexcept																		;

		friend class findIFname;

	protected:
		deque<field> headers;
};

class findIFname{
	public:	
		findIFname(const string &field_name																		   );
		findIFname(const char *field_name, string::size_type _size												   );
		findIFname(const class field_name &FName																   );

		bool operator()(const string &field_name																   );
		bool operator()(const class field &_field																   );

	private:
		string match_name;
};


} /* namespace NS_LIBMIME */


#endif /*__LIBMIME_HEADER_HPP__*/


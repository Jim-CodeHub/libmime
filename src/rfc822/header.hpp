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
#include <iostream> //TBD

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
		header(const class field &field_line)																		;
		header(const string &field_name, const string &field_body												   );	
		header(const char *field_name, string::size_type _nSize, const char *field_body, string::size_type _bSize  );
		header(const string &field_line																			   );	
		header(const char *field_line, string::size_type _size													   );	
		header(class field_name &name_t, class field_body *pBody_t											       );
		header(const string &field_name, class field_body *pBody_t		    								       );
		header(const char *field_name, string::size_type _size, class field_body *pBody_t				   		   );

		void set(const class field &field_line)																		;
		void set(const string &field_name, const string &field_body												   );	
		void set(const char *field_name, string::size_type _nSize, const char *field_body, string::size_type _bSize);
		void set(const string &field_line																		   );	
		void set(const char *field_line, string::size_type _size												   );	
		void set(class field_name &name_t, class field_body *pBody_t											   );
		void set(const string &field_name, class field_body *pBody_t		    								   );
		void set(const char *field_name, string::size_type _size, class field_body *pBody_t				   		   );

		const string get_field(const string &field_name) const noexcept												;
		const string get_field(const char *field_name, string::size_type _size) const noexcept						;

		friend class findIFname;
	void show(void)
		{
			deque<field>::iterator _big = headers.begin(), _end = headers.end();
			while(_big != _end)
			{
				std::cout << _big->get();
				_big++;
			}
		}

	private:
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


/**-----------------------------------------------------------------------------------------------------------------
 * @file	header.hpp
 * @brief	Standrad for ARPA Ineternet text messages	
 * @ref		IETF-rfc822
 * @note	Set an empty header with only default constructure
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
#include <libmime/rfc822/field.hpp>


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
		header(const class field &field_line								);		
		header(const string &field_name, const class field_body *pBody_t  	);
		header(const string &field_name, const string &field_body			);

		void set(const class field &field_line							  	);
		void set(const string &field_name, const class field_body *pBody_t	);
		void set(const string &field_name, const string &field_body			);

		const class header &operator=(const class header &_header		  	);

		class field &get_field(const string &field_name					  	);
		class field &get_field(size_t pos								  	);

		const class field &get_field(const string &field_name) const noexcept;

		const string get(void) const noexcept							     ;

		bool is_empty(void												    );
		bool exist_field(const string &field_name				            );

		void clear(void											            );

		friend class findIFname;

		void remove(const string &field_name					            );

	protected:
		deque<field> headers;
};

class findIFname{
	public:	
		findIFname(const string &field_name								    );
		findIFname(const char *field_name, string::size_type _size 		    );
		findIFname(const class field_name &FName				   		    );

		bool operator()(const string &field_name				   		    );
		bool operator()(const class field &_field				   		    );	

	private:
		string match_name;
};


} /* namespace NS_LIBMIME */


#endif /*__LIBMIME_HEADER_HPP__*/


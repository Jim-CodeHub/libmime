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
#include <libMIME/src/rfc822/field_body/string_body.hpp>


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
		static class field null_field											 ;

	public:
		field(){ pbody = NULL;}												     ;
		~field(){ if (NULL != pbody) { delete pbody; pbody = NULL;}	}			 ;
		field(const class field &_field) { *this = _field; }				     ;

		field(const class field_name &name_t, const class field_body *pBody_t   );

		void set(const class field_name &name_t, const class field_body *pBody_t);

		void set_name(const class field_name &rname_t							);
		void set_body(const class field_body *pBody_t							);

		bool operator==(const class field &_field								);
		const class field &operator=(const class field &_field					);

		const string get(void) const noexcept									 ;

		const string get_name(void) const noexcept								 ;
		const string get_body(void) const noexcept								 ;

		bool is_empty(void													    );

	private:
		class field_name  _name;
		class field_body *pbody;
};


} /* namespace NS_LIBMIME */


#endif /*__LIBMIME_FIELD_HPP__*/


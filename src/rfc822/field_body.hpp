/**-----------------------------------------------------------------------------------------------------------------
 * @file	field_body.hpp
 * @brief	Standrad for ARPA Ineternet text messages	
 * @ref		IETF-rfc822
 *
 * Copyright (c) 2019-2019 Jim Zhang 303683086@qq.com
 *------------------------------------------------------------------------------------------------------------------
*/


#ifndef __LIBMIME_FIELD_BODY_HPP__
#define __LIBMIME_FIELD_BODY_HPP__


/*------------------------------------------------------------------------------------------------------------------
 *
 *												FIELD_BODY INCLUDES
 *
 *------------------------------------------------------------------------------------------------------------------
*/

#include <string>


namespace NS_LIBMIME{

using namespace std ;


/*------------------------------------------------------------------------------------------------------------------
 *
 *												FIELD_BODY SHORT ALIAS 
 *
 *------------------------------------------------------------------------------------------------------------------
*/


/*------------------------------------------------------------------------------------------------------------------
 *
 *												FIELD_BODY DATA BLOCK
 *
 *------------------------------------------------------------------------------------------------------------------
*/

/**
 *	@brief field body class and function set
 *	@note 
 *		Inheritance graph : None
 **/
class field_body{
	public:
		virtual void set(const string &body			   ) = 0;
		virtual void set(const char *body, size_t _size) = 0;
		
		virtual const string &unfold(void) noexcept = 0		;

		virtual const string &get(void) const noexcept = 0  ;
};


} /* namespace NS_LIBMIME */


#endif /*__LIBMIME_FIELD_BODY_HPP__*/


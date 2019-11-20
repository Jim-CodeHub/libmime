/**-----------------------------------------------------------------------------------------------------------------
 * @file	field_name.hpp
 * @brief	Standrad for ARPA Ineternet text messages	
 * @ref		IETF-rfc822
 *
 * Copyright (c) 2019-2019 Jim Zhang 303683086@qq.com
 *------------------------------------------------------------------------------------------------------------------
*/


#ifndef __LIBMIME_FIELD_NAME_HPP__
#define __LIBMIME_FIELD_NAME_HPP__


/*------------------------------------------------------------------------------------------------------------------
 *
 *												FIELD_NAME INCLUDES
 *
 *------------------------------------------------------------------------------------------------------------------
*/

#include <string>


namespace NS_LIBMIME{

using namespace std ;


/*------------------------------------------------------------------------------------------------------------------
 *
 *												FIELD_NAME SHORT ALIAS 
 *
 *------------------------------------------------------------------------------------------------------------------
*/
#define  FIELD_NAME_ASCII_SCOPE_MIN		33
#define  FIELD_NAME_ASCII_SCOPE_MAX		126
#define  FIELD_NAME_ASCII_EXCLUDECH     ':' 


/*------------------------------------------------------------------------------------------------------------------
 *
 *												FIELD_NAME DATA BLOCK
 *
 *------------------------------------------------------------------------------------------------------------------
*/

/**
 *	@brief field name class and function set
 *	@note 
 *		Inheritance graph : None
 **/
class field_name{
	public:
		void set(const string &name			   );
		void set(const char *name, size_t _size);

		const string &get(void) const noexcept  ;

	private:
		string name;
};


} /* namespace NS_LIBMIME */


#endif /*__LIBMIME_FIELD_NAME_HPP__*/


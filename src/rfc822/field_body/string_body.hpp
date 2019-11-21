/**-----------------------------------------------------------------------------------------------------------------
 * @file	string_body.hpp
 * @brief	Standrad for ARPA Ineternet text messages	
 * @ref		IETF-rfc822
 *
 * Copyright (c) 2019-2019 Jim Zhang 303683086@qq.com
 *------------------------------------------------------------------------------------------------------------------
*/


#ifndef __LIBMIME_STRING_BODY_HPP__
#define __LIBMIME_STRING_BODY_HPP__


/*------------------------------------------------------------------------------------------------------------------
 *
 *												STRING_BODY INCLUDES
 *
 *------------------------------------------------------------------------------------------------------------------
*/

#include <libMIME/src/rfc822/field_body.hpp>


namespace NS_LIBMIME{

using namespace std ;


/*------------------------------------------------------------------------------------------------------------------
 *
 *												STRING_BODY SHORT ALIAS 
 *
 *------------------------------------------------------------------------------------------------------------------
*/


/*------------------------------------------------------------------------------------------------------------------
 *
 *												STRING_BODY DATA BLOCK
 *
 *------------------------------------------------------------------------------------------------------------------
*/

/**
 *	@brief string (unstructed) field body class and function set
 *	@note 
 *		Inheritance graph : string_body->field_body 
 **/
class string_body : public field_body{
	public:
		string_body(){}; /**< Empty structure */
		string_body(const string &body								  );
		string_body(const char *body, string::size_type _size		  );

		void set(const string &body									  );
		void set(const char *body, string::size_type _size			  );

		const string &unfold(void) noexcept							   ;

		static const void unfold(string &body					      );
		static string unfold(const char *body, string::size_type _size);

		const string &get(void) const noexcept					       ;

	private:
		string body;
};


} /* namespace NS_LIBMIME */


#endif /*__LIBMIME_STRING_BODY_HPP__*/


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

#include <libmime/rfc822/field_body.hpp>


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
		static const string lable												   ;

	public:
		string_body(){}; /**< Empty structure */
		string_body(const string &body											  );
		string_body(const char *body, string::size_type _size					  );

		void set(const string &body												  );
		void set(const char *body, string::size_type _size						  );

		const string &get_lable(void) const noexcept { return string_body::lable; };

		const string get(void) const noexcept { return this->body; }               ;

	protected:
		field_body *clone(void) const											   ; 

	private:
		string body;
};


} /* namespace NS_LIBMIME */


#endif /*__LIBMIME_STRING_BODY_HPP__*/


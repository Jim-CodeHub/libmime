/**-----------------------------------------------------------------------------------------------------------------
 * @file	body.hpp
 * @brief	Standrad for ARPA Ineternet text messages	
 * @ref		IETF-rfc822
 *
 * Copyright (c) 2019-2019 Jim Zhang 303683086@qq.com
 *------------------------------------------------------------------------------------------------------------------
*/


#ifndef __LIBMIME_BODY_HPP__
#define __LIBMIME_BODY_HPP__


/*------------------------------------------------------------------------------------------------------------------
 *
 *												BODY INCLUDES
 *
 *------------------------------------------------------------------------------------------------------------------
*/

#include <string>
#include <cstring>


namespace NS_LIBMIME{

using namespace std ;


/*------------------------------------------------------------------------------------------------------------------
 *
 *												BODY SHORT ALIAS 
 *
 *------------------------------------------------------------------------------------------------------------------
*/


/*------------------------------------------------------------------------------------------------------------------
 *
 *												BODY DATA BLOCK
 *
 *------------------------------------------------------------------------------------------------------------------
*/

/**
 *	@brief body class and function set
 *	@note 
 *		Inheritance graph : None
 **/
class body{
	public:
		body(){};					/**< Empty structure   */
		~body(){ delete bodys; }	/**< Destructure       */
		body(const class body &_body){ *this = _body; }	    ;
		body(const string &_body						   );
		body(const char *body, string::size_type _size	   );

		const class body &operator=(const class body &_body);

		void set(const string &body 					   );
		void set(const char *body, string::size_type _size );

		const string &get(void) const noexcept			    ;

		void clear(void									   );
		
	protected:
		string *bodys = new string;
};


} /* namespace NS_LIBMIME */


#endif /*__LIBMIME_BODY_HPP__*/


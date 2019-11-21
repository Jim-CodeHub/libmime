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
		body(){}; /**< Empty structure */
		body(const string &_body						  );
		body(const char *body, string::size_type _size	  );

		void set(const string &_body					  );
		void set(const char *body, string::size_type _size);

		const string &get(void) const noexcept			   ;
		
	private:
		string bodys;
};


} /* namespace NS_LIBMIME */


#endif /*__LIBMIME_BODY_HPP__*/


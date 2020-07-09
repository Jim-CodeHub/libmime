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
#include <cstdio>


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
		body() {this->clear();};	/**< Empty structure   */
		body(const class body &_body){ *this = _body; }									 ;

		body(const string &_body, string::size_type _size						   		);
		body(const char *body, string::size_type _size	   								);

		const class body &operator=(const class body &_body								);

		void set(const string &body, string::size_type _size							);
		void set(const char *body, string::size_type _size 								);

		const string &get(void) const noexcept											 ;
		ssize_t  get_size(void) const noexcept											 ;

		void load(const char *file_path, string::size_type offset,  long int _size		);
		void load(const char *file_path, string::size_type offset,  long int _size) const;
		void fill(const char *file_path													);
		void fill(const char *file_path) const											 ;

		void clear(void																	);
		
	protected:
		string *bodys = new string; /**< String will hold it's size info            	*/
};


} /* namespace NS_LIBMIME */


#endif /*__LIBMIME_BODY_HPP__*/


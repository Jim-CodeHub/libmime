/**-----------------------------------------------------------------------------------------------------------------
 * @file	version_body.hpp
 * @brief	Multi-purpose mail extensions	
 * @ref		IETF-rfc2045, rfc2046, rfc2047, rfc2048, rfc2049 
 *
 * Copyright (c) 2019-2019 Jim Zhang 303683086@qq.com
 *------------------------------------------------------------------------------------------------------------------
*/


#ifndef __LIBMIME_VERSION_BODY_HPP__
#define __LIBMIME_VERSION_BODY_HPP__


/*------------------------------------------------------------------------------------------------------------------
 *
 *												VERSION_BODY INCLUDES
 *
 *------------------------------------------------------------------------------------------------------------------
*/

#include <libMIME/src/rfc822/field_body.hpp>


namespace NS_LIBMIME{

using namespace std ;


/*------------------------------------------------------------------------------------------------------------------
 *
 *												VERSION_BODY SHORT ALIAS 
 *
 *------------------------------------------------------------------------------------------------------------------
*/


/*------------------------------------------------------------------------------------------------------------------
 *
 *												VERSION_BODY DATA BLOCK
 *
 *------------------------------------------------------------------------------------------------------------------
*/

/**
 *	@brief string (structed) field body class and function set
 *	@note 
 *		Inheritance graph : version_body->field_body 
 **/
class version_body : public field_body{
	public:
		version_body(){}; /**< Empty structure */
		version_body(const string &version						 );
		version_body(const char *version, string::size_type _size);
		version_body(const char *version						 );
		version_body(int v_major, int v_minor					 );

		void set(const string &version							 );
		void set(const char *version, string::size_type _size	 );
		void set(const char *version							 );
		void set(int v_major, int v_minor						 );

		const string get(void) const noexcept					  ;

	private:
		string body;
};


} /* namespace NS_LIBMIME */


#endif /*__LIBMIME_VERSION_BODY_HPP__*/

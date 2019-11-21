/**-----------------------------------------------------------------------------------------------------------------
 * @file	contenttype_body.hpp
 * @brief	Multi-purpose mail extensions	
 * @ref		IETF-rfc2045, rfc2046, rfc2047, rfc2048, rfc2049 
 *
 * Copyright (c) 2019-2019 Jim Zhang 303683086@qq.com
 *------------------------------------------------------------------------------------------------------------------
*/


#ifndef __LIBMIME_CONTENTTYPE_BODY_HPP__
#define __LIBMIME_CONTENTTYPE_BODY_HPP__


/*------------------------------------------------------------------------------------------------------------------
 *
 *												CONTENTTYPE_BODY INCLUDES
 *
 *------------------------------------------------------------------------------------------------------------------
*/

#include <libMIME/src/rfc822/field_body.hpp>


namespace NS_LIBMIME{

using namespace std ;


/*------------------------------------------------------------------------------------------------------------------
 *
 *												CONTENTTYPE_BODY SHORT ALIAS 
 *
 *------------------------------------------------------------------------------------------------------------------
*/


/*------------------------------------------------------------------------------------------------------------------
 *
 *												CONTENTTYPE_BODY DATA BLOCK
 *
 *------------------------------------------------------------------------------------------------------------------
*/

/**
 *	@brief string (structed) field body class and function set
 *	@note 
 *		Inheritance graph : contenttype_body->field_body 
 **/
class contenttype_body : public field_body{
	public:
		contenttype_body(){}; /**< Empty structure */
		contenttype_body(const string &contenttype							  );
		contenttype_body(const char *contenttype, string::size_type _size	  );
		contenttype_body(const char *contenttype							  );
		contenttype_body(int v_major, int v_minor							  );

		void set(const string &contenttype									  );
		void set(const char *contenttype, string::size_type _size		      );
		void set(const char *contenttype								      );

		const string &get(void) const noexcept					               ;

	private:
		string body;
};


} /* namespace NS_LIBMIME */


#endif /*__LIBMIME_CONTENTTYPE_BODY_HPP__*/


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

#include <list>
#include <random>
#include <chrono>
#include <sstream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <libMIME/src/rfc822/field_body.hpp>
#include <libMIME/src/util/token.hpp>
#include <libMIME/src/header/param.hpp>


namespace NS_LIBMIME{

using namespace std ;


/*------------------------------------------------------------------------------------------------------------------
 *
 *												CONTENTTYPE_BODY SHORT ALIAS 
 *
 *------------------------------------------------------------------------------------------------------------------
*/
#define	 CONTENTTYPE_BODY_BOUNDARY_MAX			69	
#define  CONTENTTYPE_LABLE						"Content-Type" 


/*------------------------------------------------------------------------------------------------------------------
 *
 *												CONTENTTYPE_BODY DATA BLOCK
 *
 *------------------------------------------------------------------------------------------------------------------
*/

/**
 *	@brief string (structed) field body class and function set
 *	@note 
 *		Inheritance graph : contenttype_body->field_body (rfc822)
 **/
class contenttype_body : public field_body{
	public:
		enum major_type{TEXT, IMAGE, AUDIO, VIDEO, APPLICATION, MESSAGE, MULTIPART};

	public:
		contenttype_body(){}; /**< Empty structure */
		contenttype_body(const string &contenttype_body																		   );
		contenttype_body(const char *contenttype_body, string::size_type _size												   );
		contenttype_body(const char *contenttype_body																		   );
		contenttype_body(const string &major_type, const string &minor_type												       );
		contenttype_body(const char *major_type, string::size_type _mjrSize, const char *minor_type, string::size_type _morSize);
		contenttype_body(const char *major_type, const char *minor_type														   );

		void set(const string &contenttype_body																				   );
		void set(const char *contenttype_body, string::size_type _size														   );
		void set(const char *contenttype_body																				   );
		void set(const string &major_type, const string &minor_type															   );
		void set(const char *major_type, string::size_type _mjrSize, const char *minor_type, string::size_type _morSize		   );
		void set(const char *major_type, const char *minor_type																   );

		void set_param(const class param &_param																			   );
		void set_param(const string &_param																					   );
		void set_param(const char *_param, string::size_type _size															   );
		void set_param(const char *_param																					   );
		void set_param(const string &attr, const string &value																   );
		void set_param(const char *attr, string::size_type _nSize, const char *value, string::size_type _vSize				   );
		void set_param(const char *attr, const char *value																	   );

		const string get(void) const noexcept																					;

		const string get_types(void) const noexcept																				;
		const string &get_major_type(void) const noexcept																		;
		const string &get_minor_type(void) const noexcept																		;

		const string get_param_value(const string &attr) const noexcept															;
		const string get_param_value(const char *attr, string::size_type _size) const noexcept									;
		const string get_param_value(const char *attr) const noexcept															;


		static const string construct_boundary(void																			   );

	private:
		string major_type, minor_type; 
		list<param> parameters       ;
};


} /* namespace NS_LIBMIME */


#endif /*__LIBMIME_CONTENTTYPE_BODY_HPP__*/


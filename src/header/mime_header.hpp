/**-----------------------------------------------------------------------------------------------------------------
 * @file	mime_header.hpp
 * @brief	Multi-purpose mail extensions	
 * @ref		IETF-rfc2045, rfc2046, rfc2047, rfc2048, rfc2049 
 *
 * Copyright (c) 2019-2019 Jim Zhang 303683086@qq.com
 *------------------------------------------------------------------------------------------------------------------
*/


#ifndef __LIBMIME_MIME_HEADER_HPP__
#define __LIBMIME_MIME_HEADER_HPP__


/*------------------------------------------------------------------------------------------------------------------
 *
 *												MIME_HEADER INCLUDES
 *
 *------------------------------------------------------------------------------------------------------------------
*/

#include <libMIME/src/rfc822/header.hpp>


namespace NS_LIBMIME{

using namespace std ;


/*------------------------------------------------------------------------------------------------------------------
 *
 *												MIME_HEADER SHORT ALIAS 
 *
 *------------------------------------------------------------------------------------------------------------------
*/


/*------------------------------------------------------------------------------------------------------------------
 *
 *												MIME_HEADER DATA BLOCK
 *
 *------------------------------------------------------------------------------------------------------------------
*/

/**
 *	@brief mime field nameenumeration list 
 **/
enum MIME_FNAME{MIME_VERSION, CONTENT_TYPE, CONTENT_ID, CONTENT_DISPOSITION, CONTENT_DESCRIPTION, 
			    CONTENT_TRANSFER_ENCODING}; 

/**
 *	@brief mime_header class and function set
 *	@note 
 *		Inheritance graph : mime_header -> header(rfc822) 
 **/
class mime_header : public header{
	public:
		mime_header(){}; /**< Empty structure */
		mime_header(const class field &field_line):header(field_line){}										;
		mime_header(const string &field_name, const class field_body *pBody_t):header(field_name, pBody_t){};
		mime_header(enum MIME_FNAME fname_t, const class field_body *pBody_t							   );

		void set(const class field &field_line					   			 							   );
		void set(const string &field_name, const class field_body *pBody_t	 							   );
		void set(enum MIME_FNAME fname_t, const class field_body *pBody_t	 							   );

		class field &get_field(enum MIME_FNAME fname_t						 							   );
};




} /* namespace NS_LIBMIME */


#endif /*__LIBMIME_MIME_HEADER_HPP__*/


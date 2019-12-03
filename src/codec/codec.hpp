/**-----------------------------------------------------------------------------------------------------------------
 * @file	codec.hpp
 * @brief   library codec header file set	
 *
 * Copyright (c) 2019-2019 Jim Zhang 303683086@qq.com
 *------------------------------------------------------------------------------------------------------------------
*/


#ifndef __LIBMIME_CODEC_HPP__
#define __LIBMIME_CODEC_HPP__


/*------------------------------------------------------------------------------------------------------------------
 *
 *												CODEC INCLUDES
 *
 *------------------------------------------------------------------------------------------------------------------
*/

#include <libMIME/src/codec/Base64.hpp>


/*------------------------------------------------------------------------------------------------------------------
 *
 *												CODEC SHORT ALIAS 
 *
 *------------------------------------------------------------------------------------------------------------------
*/

/*------------------------------------------------------------------------------------------------------------------
 *
 *												CODEC DATA BLOCK
 *
 *------------------------------------------------------------------------------------------------------------------
*/

enum _codec{BASE64 = 0, QUOTED_PRINTABLE, _7BIT, _8BIT, BINARY};

/**
 *	@brief encode and decode mime message 
 *	@note 
 *		Inheritance graph : None 
 **/
class codec{
	public:
		codec(){}; /**< Empty structure */

		void encode(enum _codec code, const string &src, string &des, string::size_type len   ); 
		void encode(const string &code, const string &src, string &des, string::size_type len ); 
		void decode(enum _codec code, const string &src, string &des, string::size_type &len  ); 
		void decode(const string &code, const string &src, string &des, string::size_type &len); 

};


#endif /*__LIBMIME_CODEC_HPP__*/


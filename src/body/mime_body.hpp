/**-----------------------------------------------------------------------------------------------------------------
 * @file	mime_body.hpp
 * @brief	Multi-purpose mail extensions	
 * @ref		IETF-rfc2045, rfc2046, rfc2047, rfc2048, rfc2049 
 *
 * Copyright (c) 2019-2019 Jim Zhang 303683086@qq.com
 *------------------------------------------------------------------------------------------------------------------
*/


#ifndef __LIBMIME_MIME_BODY_HPP__
#define __LIBMIME_MIME_BODY_HPP__


/*------------------------------------------------------------------------------------------------------------------
 *
 *												MIME_BODY INCLUDES
 *
 *------------------------------------------------------------------------------------------------------------------
*/

#include <list>
#include <libMIME/src/rfc822/body.hpp>
//#include <libMIME/src/body/mime_entity.hpp>


namespace NS_LIBMIME{

using namespace std ;


/*------------------------------------------------------------------------------------------------------------------
 *
 *												MIME_BODY SHORT ALIAS 
 *
 *------------------------------------------------------------------------------------------------------------------
*/


/*------------------------------------------------------------------------------------------------------------------
 *
 *												MIME_BODY DATA BLOCK
 *
 *------------------------------------------------------------------------------------------------------------------
*/

class mime_entity; /**< forward declaration */

/**
 *	@brief mime_body class and function set
 *	@note 
 *		Inheritance graph : mime_body -> body(rfc822) 
 **/
class mime_body : public body{
	public:
		mime_body(){}; /**< Empty structure */
		mime_body(const string &_body):body(_body){};
		mime_body(const char *_body, string::size_type _size):body(_body, _size){};

	private:
		//list<class mime_entity> main_entity; 
		//list<class mime_entity> part_entity; 
};


} /* namespace NS_LIBMIME */


#endif /*__LIBMIME_MIME_BODY_HPP__*/


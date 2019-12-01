/**-----------------------------------------------------------------------------------------------------------------
 * @file	body_shadow.hpp
 * @brief	Multi-purpose mail extensions	
 * @ref		IETF-rfc2045, rfc2046, rfc2047, rfc2048, rfc2049 
 *
 * Copyright (c) 2019-2019 Jim Zhang 303683086@qq.com
 *------------------------------------------------------------------------------------------------------------------
*/


#ifndef __LIBMIME_MIME_BODY_SHADOW_HPP__
#define __LIBMIME_MIME_BODY_SHADOW_HPP__


/*------------------------------------------------------------------------------------------------------------------
 *
 *												MIME_BODY_SHADOW INCLUDES
 *
 *------------------------------------------------------------------------------------------------------------------
*/

#include <list>
#include <libMIME/src/rfc822/body.hpp>
#include <libMIME/src/codec/codec.hpp>


namespace NS_LIBMIME{

using namespace std ;


/*------------------------------------------------------------------------------------------------------------------
 *
 *												MIME_BODY_SHADOW SHORT ALIAS 
 *
 *------------------------------------------------------------------------------------------------------------------
*/


/*------------------------------------------------------------------------------------------------------------------
 *
 *												MIME_BODY_SHADOW DATA BLOCK
 *
 *------------------------------------------------------------------------------------------------------------------
*/

class mime_entity; /**< Forward declaration */

/**
 *	@brief body_shadow class and function set
 *	@note 
 *		Inheritance graph : body_shadow -> body(rfc822) 
 **/
class body_shadow : public body{
	public: friend class mime_entity;
	public:
		body_shadow(){}; /**< Empty structure   */
		body_shadow(const class body_shadow &sdbody){ *this = sdbody;}				  ;
		body_shadow(const string &sdbody):body(sdbody){}							  ;
		body_shadow(const char *sdbody, string::size_type _size):body(sdbody, _size){};

		void encode(enum codec code												     );
		void decode(enum codec code												     );

	protected:
		list<class mime_entity*> part_entity;
};


} /* namespace NS_LIBMIME */


#endif /*__LIBMIME_MIME_BODY_SHADOW_HPP__*/

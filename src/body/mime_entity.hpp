/**-----------------------------------------------------------------------------------------------------------------
 * @file	mime_entity.hpp
 * @brief	Multi-purpose mail extensions	
 * @ref		IETF-rfc2045, rfc2046, rfc2047, rfc2048, rfc2049 
 *
 * Copyright (c) 2019-2019 Jim Zhang 303683086@qq.com
 *------------------------------------------------------------------------------------------------------------------
*/


#ifndef __LIBMIME_MIME_ENTITY_HPP__
#define __LIBMIME_MIME_ENTITY_HPP__


/*------------------------------------------------------------------------------------------------------------------
 *
 *												MIME_ENTITY INCLUDES
 *
 *------------------------------------------------------------------------------------------------------------------
*/

#include <libMIME/src/body/body_shadow.hpp>
#include <libMIME/src/header/mime_header.hpp>
#include <libMIME/src/header/field_body/contenttype_body.hpp>
#include <libMIME/src/util/token.hpp>

namespace NS_LIBMIME{

using namespace std ;


/*------------------------------------------------------------------------------------------------------------------
 *
 *												MIME_ENTITY SHORT ALIAS 
 *
 *------------------------------------------------------------------------------------------------------------------
*/


/*------------------------------------------------------------------------------------------------------------------
 *
 *												MIME_ENTITY DATA BLOCK
 *
 *------------------------------------------------------------------------------------------------------------------
*/

/**
 *	@brief mime_entity class and function set
 *	@note 
 *		Inheritance graph : None 
 *
 *	@note
 *		Operator '=' can not be overloading and copy structure will not work correctly 
 **/
class mime_entity{
	public: friend class body_shadow; 
	public:
		mime_entity(){} /**< Empty constructure */									   ;

		void set_node(const class mime_header &header, const class body_shadow &sdbody);
		class mime_entity *set_part(const class mime_header &header					  );

		//load
		
		const string make(void														  );	

	protected:
		class mime_header header;
		class body_shadow sdbody;
};


} /* namespace NS_LIBMIME */


#endif /*__LIBMIME_MIME_ENTITY_HPP__*/


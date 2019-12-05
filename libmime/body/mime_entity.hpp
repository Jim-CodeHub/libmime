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

#include <libmime/body/body_shadow.hpp>
#include <libmime/header/mime_header.hpp>
#include <libmime/header/field_body/contenttype_body.hpp>
#include <libmime/util/token.hpp>

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
		mime_entity(){ this->nest = true; } /**< Empty constructure */						 ;

		void set_node(class mime_header &header, const class body_shadow &sdbody			);
		void set_node(class mime_header &header, const string &body, string::size_type _size);
		class mime_entity *set_part(class mime_header &header								);

		bool load(string &_entity												 			);
		bool load(const char *entity, string::size_type _size					 			);
		const string make(void													 			);	

		static const class mime_header &check_header(class mime_header &_header	 			);

		const class mime_header &get_header(void) const noexcept                 			 ;
		const class body_shadow &get_sdbody(void) const noexcept				 			 ;

		const class mime_entity *get_part(string::size_type _inx) const noexcept 			 ;

	protected:
		void clear(void															 			);

	protected:
		bool nest; /**< Mark if the entity can be nested or not */ 

	protected:
		class mime_header header;
		class body_shadow sdbody;
};


} /* namespace NS_LIBMIME */


#endif /*__LIBMIME_MIME_ENTITY_HPP__*/


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

#include <libMIME/src/body/mime_body.hpp>
#include <libMIME/src/header/mime_header.hpp>

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
	public: friend class mime_body; 
	public:
		mime_entity(){}; /**< Empty structure */
		~mime_entity();  /**< Destructure     */
		
		void set_header(const class mime_header &header);
		class mime_entity *set_body(const class mime_body &_body);

		const class mime_header &get_header(void) const noexcept;
		const class mime_body &get_body(void) const noexcept;

		const string get(void) const noexcept;

	protected:
		class mime_header header;
		class mime_body   _body ;
};


} /* namespace NS_LIBMIME */


#endif /*__LIBMIME_MIME_ENTITY_HPP__*/


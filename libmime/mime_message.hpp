/**-----------------------------------------------------------------------------------------------------------------
 * @file	mime_message.hpp
 * @brief	Multi-purpose mail extensions	
 * @ref		IETF-rfc2045, rfc2046, rfc2047, rfc2048, rfc2049 
 *
 * Copyright (c) 2019-2019 Jim Zhang 303683086@qq.com
 *------------------------------------------------------------------------------------------------------------------
*/


#ifndef __LIBMIME_MIME_MESSAGE_HPP__
#define __LIBMIME_MIME_MESSAGE_HPP__


/*------------------------------------------------------------------------------------------------------------------
 *
 *												MIME_MESSAGE INCLUDES
 *
 *------------------------------------------------------------------------------------------------------------------
*/

#include <libmime/body/mime_entity.hpp>

namespace NS_LIBMIME{

using namespace std ;


/*------------------------------------------------------------------------------------------------------------------
 *
 *												MIME_MESSAGE SHORT ALIAS 
 *
 *------------------------------------------------------------------------------------------------------------------
*/


/*------------------------------------------------------------------------------------------------------------------
 *
 *												MIME_MESSAGE DATA BLOCK
 *
 *------------------------------------------------------------------------------------------------------------------
*/

/**
 *	@brief mime_message class and function set
 *	@note 
 *		Inheritance graph : None 
 **/
class mime_message : public mime_entity{
	public:
		mime_message(){}; /**< Empty structure */

		void set_preamble(const string &_preamble						 );
		void set_preamble(const char *_preamble, string::size_type _size );

		void set_epilogue(const string &_epilogue						 );
		void set_epilogue(const char *_epilogue, string::size_type _size );

		const string &get_preamble(void) const noexcept					  ;
		const string &get_epilogue(void) const noexcept					  ;

		const string make(void											 );

	protected:
		string preamble;	 string epilogue;
};


} /* namespace NS_LIBMIME */


#endif /*__LIBMIME_MIME_MESSAGE_HPP__*/


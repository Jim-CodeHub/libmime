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
#include <libMIME/src/codec/codec.hpp>


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

class mime_entity;  /**< Forward declaration */

/**
 *	@brief mime_body class and function set
 *	@note 
 *		Inheritance graph : mime_body -> body(rfc822) 
 **/
class mime_body : public body{
	public: friend class mime_entity;
	public:
		mime_body(){}; /**< Empty structure   */
		mime_body(const class mime_body &_body){ *this = _body;}				  ;
		mime_body(const string &_body):body(_body){}							  ;
		mime_body(const char *_body, string::size_type _size):body(_body, _size){};

		void set_preamble(const string &_preamble								 );
		void set_preamble(const char *_preamble, string::size_type _size		 );
		void set_preamble(const char *_preamble								     );

		void encode(enum codec code												 );
		void decode(enum codec code												 );

		void set_epilogue(const string &_epilogue								 );
		void set_epilogue(const char *_epilogue, string::size_type _size		 );
		void set_epilogue(const char *_epilogue									 );

		const string &get_preamble(void) const noexcept						      ;
		const string &get_epilogue(void) const noexcept							  ;

		const class mime_body &operator=(const class mime_body &_body			 );

		void clear(void															 );

	protected:
		string preamble;
		list<class mime_entity*> part_entity;
		string epilogue;
};


} /* namespace NS_LIBMIME */


#endif /*__LIBMIME_MIME_BODY_HPP__*/


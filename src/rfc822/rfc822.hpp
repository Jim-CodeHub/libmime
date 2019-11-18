/**-----------------------------------------------------------------------------------------------------------------
 * @file	rfc822.hpp
 * @brief	Standrad for ARPA Ineternet text messages	
 * @ref		IETF-RFC822
 *
 * Copyright (c) 2019-2019 Jim Zhang 303683086@qq.com
 *------------------------------------------------------------------------------------------------------------------
*/


#ifndef __LIBMIME_RFC822_HPP__
#define __LIBMIME_RFC822_HPP__


/*------------------------------------------------------------------------------------------------------------------
 *
 *												RFC822 INCLUDES
 *
 *------------------------------------------------------------------------------------------------------------------
*/

#include <libMIME/src/rfc822/rfc822.hpp>


namespace NS_LIBMIME{

/*------------------------------------------------------------------------------------------------------------------
 *
 *												RFC822 DATA BLOCK
 *
 *------------------------------------------------------------------------------------------------------------------
*/

/**
 *	@brief RFC822 (Header) Field class and function set
 **/
class rfc822_field{
	public:
		void set();

	protected:
		string field_name;
		string field_body;
};

#if 0
1. header CRLF 
   CRLF
   body

2. body fold and unfold
	fold : insert Y only if X exist

	X = 1*([CRLF] + SPACE/HTAB)	;	SPACE = ASCII_32, HTAB = ASCII_9
	Y = CRLF + 1*(SPACE/HTAB)

	unfold : Y -> SPACE/HTAB 

3. filed  

   filed-name:field-body+CRLF

   filed-name Consist of ASCII 33~126 exclude ":"

   field-body Consist of ANY ASCII exclude CRLF

   Note: An unfold action SHOULD BE done, before parse field-body

   Note: field body can be ignored

#endif

#if 0 //TBD
class message{};
class dateTime{};
class address{};
more for structrued field-body details
#endif


} /* namespace NS_LIBMIME */


#endif /*__LIBMIME_RFC822_HPP__*/


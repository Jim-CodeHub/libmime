/**-----------------------------------------------------------------------------------------------------------------
 * @file	rfc822.hpp
 * @brief	packetize and depacketize HTTP message
 *
 * Copyright (c) 2019-2019 Jim Zhang 303683086@qq.com
 *------------------------------------------------------------------------------------------------------------------
*/


#ifndef __LIBMIME_MESSAGE_HPP__
#define __LIBMIME_MESSAGE_HPP__


/*------------------------------------------------------------------------------------------------------------------
 *
 *										    MESSAGE INCLUDES
 *
 *------------------------------------------------------------------------------------------------------------------
*/

#include <libMIME/rfc822/rfc822.hpp>


namespace NS_LIBMIME{

/*------------------------------------------------------------------------------------------------------------------
 *
 *										    MESSAGE DATA BLOCK
 *
 *------------------------------------------------------------------------------------------------------------------
*/

/**
 *	@brief HTTP official request method
 **/

/**
 *	@brief HTTP message class and function set
 **/
class message : public mime{
	public:

	private:
		string message_line;
};


} /* namespace NS_LIBMIME */


#endif /*__LIBMIME_MESSAGE_HPP__*/


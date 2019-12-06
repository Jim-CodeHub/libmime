/**-----------------------------------------------------------------------------------------------------------------
 * @file	contentid_body.hpp
 * @brief	Multi-purpose mail extensions	
 * @ref		IETF-rfc2045, rfc2046, rfc2047, rfc2048, rfc2049 
 *
 * Copyright (c) 2019-2019 Jim Zhang 303683086@qq.com
 *------------------------------------------------------------------------------------------------------------------
*/


#ifndef __LIBMIME_CONTENTID_BODY_HPP__
#define __LIBMIME_CONTENTID_BODY_HPP__


/*------------------------------------------------------------------------------------------------------------------
 *
 *												CONTENTID_BODY INCLUDES
 *
 *------------------------------------------------------------------------------------------------------------------
*/

#include <list>
#include <random>
#include <chrono>
#include <sstream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <libmime/rfc822/field_body.hpp>
#include <libmime/util/token.hpp>
#include <libmime/header/param.hpp>


namespace NS_LIBMIME{

using namespace std ;


/*------------------------------------------------------------------------------------------------------------------
 *
 *												CONTENTID_BODY SHORT ALIAS 
 *
 *------------------------------------------------------------------------------------------------------------------
*/


/*------------------------------------------------------------------------------------------------------------------
 *
 *												CONTENTID_BODY DATA BLOCK
 *
 *------------------------------------------------------------------------------------------------------------------
*/

/**
 *	@brief string (structed) field body class and function set
 *	@note 
 *		Inheritance graph : contentid_body->field_body (rfc822)
 **/
class contentid_body : public field_body{
	public:
		static const string lable													  ;

	public:
		contentid_body(const string &host_name); /**< Contruct cid structure */

		void set(const string &cid													 );
		void set(const char *cid, string::size_type _size							 );

		const string &get_lable(void) const noexcept { return contentid_body::lable; };

		const string get(void) const noexcept										  ;

	
		static const string construct_id(const string &host_name					 );

	protected:
		class field_body *clone(void) const											  ;

	private:
		string cid_body; string host_name;
};


} /* namespace NS_LIBMIME */


#endif /*__LIBMIME_CONTENTID_BODY_HPP__*/


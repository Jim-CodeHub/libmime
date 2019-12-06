/**-----------------------------------------------------------------------------------------------------------------
 * @file	contentid_body.cpp
 * @brief	Multi-purpose mail extensions	
 * @ref		IETF-rfc2045, rfc2046, rfc2047, rfc2048, rfc2049 
 *
 * Copyright (c) 2019-2019 Jim Zhang 303683086@qq.com
 *------------------------------------------------------------------------------------------------------------------
*/


#include <libmime/header/field_body/contentid_body.hpp>

using namespace NS_LIBMIME;


/*
--------------------------------------------------------------------------------------------------------------------
*
*			                                  VARIABLES DECLARATION
*
--------------------------------------------------------------------------------------------------------------------
*/
const string contentid_body::lable = "Content-ID";


/*
--------------------------------------------------------------------------------------------------------------------
*
*			                                  FUNCTIONS IMPLEMENT
*
--------------------------------------------------------------------------------------------------------------------
*/

/**
 *	@brief	    Construct an unique content id 
 *	@param[in]  host_name - set a host name 
 *	@param[out] None
 *	@return	    None 
 **/
contentid_body::contentid_body(const string &host_name):host_name("unknown")
{
	this->host_name = host_name;	
	this->cid_body  = construct_id(host_name);
}

/**
 *	@brief	    Clone a heap instance for field_body
 *	@param[in]  None 
 *	@param[out] None
 *	@return	    Pointer to heap instance	
 **/
class field_body *contentid_body::clone(void) const
{
	return new contentid_body(*this);
}

/**
 *	@brief	    Set content id body
 *	@param[in]  cid content id
 *	@param[out] None
 *	@return		None
 *	@note		TO BE SURE THE STRING IS UNIQUE in entity OR use constructure / construct_id() only 
 **/
void contentid_body::set(const string &cid)
{
	string::const_iterator _big = cid.begin(), _end = cid.end();

	if ((*_big == '<') && (*(_end-1) == '>'))
	{
		this->cid_body = cid; goto _EXIT;
	}
	
	this->cid_body = "<" + cid + ">"    ;

_EXIT:
	return;
}

/**
 *	@brief	    Set content id body
 *	@param[in]  contentid_body 
 *	@param[in]  _size - size of contentid_body  
 *	@param[out] None
 *	@return		None
 **/
void contentid_body::set(const char *contentid_body, string::size_type _size)
{
	string cbody(contentid_body, _size);
	this->set(cbody);	         return;
}

/**
 *	@brief	    Get content_id body
 *	@param[in]  None 
 *	@param[out] None
 *	@return		content_id body	
 *	@note		The function will strip angle brackets "<"..">"
 **/
const string contentid_body::get(void) const noexcept
{
	string _cid_body;
	string::const_iterator _big = cid_body.begin(), _end = cid_body.end();

	if ((*_big == '<') && (*(_end-1) == '>'))
	{
		_cid_body = cid_body.substr(1, cid_body.size()-2);
		goto _EXIT;
	}

	return  cid_body;
_EXIT:
	return _cid_body; 
}

/**
 *	@brief	    Construct content unique id 
 *	@param[in]  host_name 
 *	@param[out] None
 *	@return	    Content id 
 **/
const string contentid_body::construct_id(const string &host_name)
{
	static uint8_t seed_count = 0;

	string unique_id;

	char   asciibet[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

	auto time_ms = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch());

	default_random_engine e(time_ms.count() + (seed_count++));

	stringstream ss;

	for (int i = 0 ; i < 10; i++)
	{
		ss << asciibet[e() % sizeof(asciibet)]; 
	}

	ss >> unique_id;

	string cid_body;
		   cid_body = "<" + unique_id + "@" + host_name + ".com>";

	return cid_body;
}


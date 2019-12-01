/**-----------------------------------------------------------------------------------------------------------------
 * @file	version_body.cpp
 * @brief	Multi-purpose mail extensions	
 * @ref		IETF-rfc2045, rfc2046, rfc2047, rfc2048, rfc2049 
 *
 * Copyright (c) 2019-2019 Jim Zhang 303683086@qq.com
 *------------------------------------------------------------------------------------------------------------------
*/


#include <libMIME/src/header/field_body/version_body.hpp>

using namespace NS_LIBMIME;


/*
--------------------------------------------------------------------------------------------------------------------
*
*			                                  VARIABLES DECLARATION
*
--------------------------------------------------------------------------------------------------------------------
*/
const string version_body::lable = "MIME_VERSION";


/*
--------------------------------------------------------------------------------------------------------------------
*
*			                                  FUNCTIONS IMPLEMENT
*
--------------------------------------------------------------------------------------------------------------------
*/

/**
 *	@brief	    Clone a heap instance for field_body
 *	@param[in]  None 
 *	@param[out] None
 *	@return	    Pointer to heap instance	
 **/
class field_body *version_body::clone(void) const
{
	return new version_body(*this);
}

/**
 *	@brief	    Set version body 
 *	@param[in]  version - version string
 *	@param[out] None
 *	@return		None
 *	@exception  "Const char *", MIME version format error
 **/
void version_body::set(const string &version)
{
	string::const_iterator _big = version.begin(), _end = version.end();

	while (_big != _end)
	{
		if (((*_big < '0') || (*_big > '9')) && ('.' != *_big))
		{
			throw ("Exception : 'version_body.cpp' MIME version format error - need x.x !");
		}

		_big++;
	}

	this->body.assign(version); return;
}

version_body::version_body(const string &version)
{
	this->set(version);
}

/**
 *	@brief	    Set version body 
 *	@param[in]  version - version string
 *	@param[in]  _size   - size of version  
 *	@param[out] None
 *	@return		None
 *	@exception  "Const char *", MIME version format error
 **/
void version_body::set(const char *version, string::size_type _size)
{
	string _version(version, _size);

	this->set(_version); return;
}

version_body::version_body(const char *version, string::size_type _size)
{
	this->set(version, _size);
}

/**
 *	@brief	    Set version body 
 *	@param[in]  v_major - major version number 
 *	@param[in]  v_minor - minor version number 
 *	@param[out] None
 *	@return		None
 *	@exception  "Const char *", MIME version format error
 **/
void version_body::set(int v_major, int v_minor)
{
	string _version = to_string(v_major) + "." + to_string(v_minor);

	this-> set(_version); return;
}

version_body::version_body(int v_major, int v_minor)
{
	this->set(v_major, v_minor);
}


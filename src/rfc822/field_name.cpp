/**-----------------------------------------------------------------------------------------------------------------
 * @file	field_name.cpp
 * @brief	Standrad for ARPA Ineternet text messages	
 * @ref		IETF-rfc822
 *
 * Copyright (c) 2019-2019 Jim Zhang 303683086@qq.com
 *------------------------------------------------------------------------------------------------------------------
*/

#include <libMIME/src/rfc822/field_name.hpp>

using namespace NS_LIBMIME;


/*
--------------------------------------------------------------------------------------------------------------------
*
*			                                  FUNCTIONS IMPLEMENT
*
--------------------------------------------------------------------------------------------------------------------
*/

/**
 *	@brief	    Set field name 
 *	@param[in]  name - field name 
 *	@param[out] None
 *	@return		None
 *	@exception  "const char *", rfc822 field name error
 **/
void field_name::set(const string &name)
{
	string::const_iterator _index = name.begin(), _end = name.end();

	while(_index != _end)
	{
		if ((*_index < FIELD_NAME_ASCII_SCOPE_MIN) || (*_index > FIELD_NAME_ASCII_SCOPE_MAX) 
				|| (*_index == FIELD_NAME_ASCII_EXCLUDECH))
		{
			throw("Exception : rfc822 field name error - Character out of range!");
		}

		_index++;
	}

	this->name = name;

	return;
}

field_name::field_name(const string &name) { this->set(name); }

/**
 *	@brief	    Set field name 
 *	@param[in]  name  - field name 
 *	@param[out] None
 *	@return		None
 *	@exception  "const char *", rfc822 field name error
 *	@note		The string param 'name' must end with '\0'
 **/
void field_name::set(const char *name)
{
	this->set(name, strlen(name));
	return;
}

field_name::field_name(const char *name) { this->set(name); }

/**
 *	@brief	    Set field name 
 *	@param[in]  name  - field name 
 *	@param[in]  _size - size of field name 
 *	@param[out] None
 *	@return		None
 *	@exception  "const char *", rfc822 field name error
 **/
void field_name::set(const char *name, size_t _size)
{
	const char *_index = name;

	this->name.clear();

	while((*_index != '\0') && (_size-- != 0))
	{
		if ((*_index < FIELD_NAME_ASCII_SCOPE_MIN) || (*_index > FIELD_NAME_ASCII_SCOPE_MAX)
				|| (*_index == FIELD_NAME_ASCII_EXCLUDECH))
		{
			this->name.clear();

			throw("Exception : rfc822 field name error!");
		}

		this->name.append(1, *_index);

		_index++;
	}

	if (*_index != '\0') {this->name.append(1, '\0');}

	return;
}

field_name::field_name(const char *name, size_t _size) { this->set(name, _size); }

/**
 *	@brief	    Get field name 
 *	@param[in]  None 
 *	@param[out] None
 *	@return		None
 *	@exception  "const char *", rfc822 field name error
 **/
const string &field_name::get(void) const noexcept 
{
	return name;
}


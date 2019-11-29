/**-----------------------------------------------------------------------------------------------------------------
 * @file	field.cpp
 * @brief	Standrad for ARPA Ineternet text messages	
 * @ref		IETF-rfc822
 *
 * Copyright (c) 2019-2019 Jim Zhang 303683086@qq.com
 *------------------------------------------------------------------------------------------------------------------
*/

#include <libMIME/src/rfc822/field.hpp>

using namespace NS_LIBMIME;


/*
--------------------------------------------------------------------------------------------------------------------
*
*			                                  FUNCTIONS IMPLEMENT
*
--------------------------------------------------------------------------------------------------------------------
*/

/**
 *	@brief	    Set field by string line 
 *	@param[in]  _field_line
 *	@param[out] None 
 *	@return	    None 
 *	@exception  "Const char *", rfc822 field line format error
 **/
void field::set(const string &field_line)
{
	string::size_type index_colon = field_line.find(':');

	if (string::npos == index_colon)
	{
		throw ("Exception : rfc822 field line format error!");
	}

	/**--------------------------------------------------------------------*/
	/**< Set field name */

	string field_name(field_line.begin(), field_line.begin() + index_colon);	

	this->_name.set(field_name);

	/**--------------------------------------------------------------------*/
	/**< Set field body */

	string::size_type i = 1 + index_colon;

	while ((i < field_line.length()-1) && (field_line[i] == ' '))
		i++;/**< Pass spaces before field-body */

	string::size_type j = field_line.find_last_of("\r\n");

	j = (field_line.length() - 1 == j)?2:0; /**< Cut '\r\n' */

	string str_body(field_line.begin() + i, field_line.end() - j);

	this->set_body(str_body);

	return;
}

field::field(const string &field_line):pbody(NULL)
{
	this->set(field_line);
}

/**
 *	@brief	    Set field by field_name and field_body instance 
 *	@param[in]  field_name
 *	@param[in]  pBody_t - field_body instance 
 *	@param[out] None 
 *	@return	    None 
 **/
void field::set(const class field_name &name_t, const class field_body *pBody_t)
{
	this->_name = name_t; this->set_body(pBody_t);
	return;
}

field::field(const class field_name &name_t, const class field_body *pBody_t):pbody(NULL)
{
	this->set(name_t, pBody_t);	
}

/**
 *	@brief	    Set field by field_name and field_body instance 
 *	@param[in]  field_name
 *	@param[in]  pBody_t - field_body instance 
 *	@param[out] None 
 *	@return	    None 
 **/
void field::set(const string &field_name, const class field_body *pBody_t)
{
	this->set_name(field_name); this->set_body(pBody_t);
	return;
}

field::field(const string &field_name, const class field_body *pBody_t):pbody(NULL)
{
	this->set(field_name, pBody_t);
}

/**
 *	@brief	    Set field by field_name and string field_body
 *	@param[in]  field_name
 *	@param[in]  field_body
 *	@param[out] None 
 *	@return	    None 
 **/
void field::set(const string &field_name, const string &field_body)
{
	this->set_name(field_name); this->set_body(field_body);
	return;
}

field::field(const string &field_name, const string &field_body):pbody(NULL)
{
	this->set(field_name, field_body);
}

/**
 *	@brief	    Operator '==' overloading 
 *	@param[in]  _field
 *	@param[out] None 
 *	@return	    ture/false 
 **/
bool field::operator==(const class field &_field)
{
	if ((NULL != this->pbody) && (NULL != _field.pbody))
	{
		if ((this->pbody->get() == _field.pbody->get()) && (this->_name.get() == _field._name.get()))
		{
			return true;
		}
	}

	return false;
}

/**
 *	@brief	    Operator '=' overloading 
 *	@param[in]  _field
 *	@param[out] None 
 *	@return	    ture/false 
 **/
const class field &field::operator=(const class field &_field)
{
	this->_name = _field._name;
	this->pbody = (NULL != _field.pbody)?_field.pbody->clone():NULL;

	return _field;
}

/**
 *	@brief	    Set field field_name 
 *	@param[in]  field_name 
 *	@param[out] None 
 *	@return	    None 
 *	@note		The body will be cleared when the function called
 **/
void field::set_name(const string &field_name)
{
	this->_name.set(field_name);

	if (NULL != this->pbody)
	{
		delete pbody; pbody = NULL;
	}

	return;
}

/**
 *	@brief	    Set field field_body
 *	@param[in]  pBody_t - field_body instance pointer
 *	@param[out] None 
 *	@return	    None 
 *	@note		Old value will be cover if the field body does not empty
 **/

void field::set_body(const class field_body *pBody_t)
{
	if (NULL != this->pbody)
	{
		delete pbody; pbody = NULL;
	}

	this->pbody = pBody_t->clone();

	return;
}

/**
 *	@brief	    Set field with string field_body
 *	@param[in]  field_body 
 *	@param[out] None 
 *	@return	    None 
 *	@note		Old value will be cover if the field body does not empty
 **/
void field::set_body(const string &field_body)
{
	string::size_type i = 0;

	while ((i < field_body.length()-1) && (field_body[i] == ' '))
		i++;/**< Pass spaces before field-body */

	string::size_type j = field_body.find_last_of("\r\n");

	j = (field_body.length() - 1 == j)?2:0; /**< Cut '\r\n' */

	string str_body(field_body.begin() + i, field_body.end() - j);

	if (NULL != this->pbody) { delete pbody; pbody = NULL;}

	this->pbody = new string_body(str_body);

	return;
}

/**
 *	@brief	    Get field
 *	@param[in]  None 
 *	@param[out] None 
 *	@return	    string of field 
 **/
const string field::get(void) const noexcept
{
	return (this->get_name() + ": " + this->get_body() + "\r\n");
}

/**
 *	@brief	    Get field name from field
 *	@param[in]  None 
 *	@param[out] None 
 *	@return	    string of field name
 **/
const string field::get_name(void) const noexcept
{
	return this->_name.get();
}

/**
 *	@brief	    Get field body from field
 *	@param[in]  None 
 *	@param[out] None 
 *	@return	    string of field body OR ""
 **/
const string field::get_body(void) const noexcept
{
	return (NULL == this->pbody)?"":this->pbody->get();
}

/**
 *	@brief	    Juge if the field is empty or not 
 *	@param[in]  None 
 *	@param[out] None 
 *	@return	    true/flase 
 **/
bool field::is_empty(void)
{
	return ((this->_name.get() == "") && (NULL == this->pbody));
}


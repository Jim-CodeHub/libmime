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
*			                                  VARIABLES DECLARATION
*
--------------------------------------------------------------------------------------------------------------------
*/
class field field::null_field;


/*
--------------------------------------------------------------------------------------------------------------------
*
*			                                  FUNCTIONS IMPLEMENT
*
--------------------------------------------------------------------------------------------------------------------
*/

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
 *	@brief	    Set field field_name 
 *	@param[in]  rname_t class field_name reference
 *	@param[out] None 
 *	@return	    None 
 *	@note		The body will be cleared when the function called
 **/
void field::set_name(const class field_name &rname_t)
{
	this->_name = rname_t;

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

	if ((NULL == this->pbody) && (NULL == _field.pbody))
	{
		if (this->_name.get() == _field._name.get()) /**< For null field comparation */
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


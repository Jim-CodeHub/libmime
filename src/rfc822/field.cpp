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

#if 0
/**
 *	@brief	    Set field by class field_name and class field_body
 *	@param[in]  field_name
 *	@param[in]  pBody_t - field (sub)body
 *	@param[out] None 
 *	@return	    None 
 **/
void field::set(const class field_name &name_t, const class field_body *pBody_t)
{
	string colon = ": "	 ; /**< Note : one SPACE left */
	string CRLF	 = "\r\n";

	this->field_line = name_t.get() + colon + pBody_t->get() + CRLF;

	return;
}

field::field(const class field_name &name_t, const class field_body *pBody_t)
{
	this->set(name_t, pBody_t);
}

/**
 *	@brief	    Set field by string field name and class field_body
 *	@param[in]  field name
 *	@param[in]  pBody_t - field (sub)body
 *	@param[out] None 
 *	@return	    None 
 **/
void field::set(const string &field_name, const class field_body *pBody_t)
{
	string colon = ": "	 ; /**< Note : one SPACE left */
	string CRLF	 = "\r\n";

	field_line = field_name + colon + pBody_t->get() + CRLF; 

	return;
}

field::field(const string &field_name, const class field_body *pBody_t)
{
	this->set(field_name, pBody_t);
}

/**
 *	@brief	    Set field by string field name and class field_body
 *	@param[in]  field name
 *	@param[in]  _size  - size of field_name 
 *	@param[in]  pBody_t - field (sub)body
 *	@param[out] None 
 *	@return	    None 
 **/
void field::set(const char *field_name, string::size_type _size, const class field_body *pBody_t)
{
	string colon = ": "	 ; /**< Note : one SPACE left */
	string CRLF	 = "\r\n";

	field_line.clear();
	field_line.append(field_name, _size); field_line.append(colon);
	field_line += pBody_t->get();   	  field_line.append(CRLF) ;

	return;
}

field::field(const char *field_name, string::size_type _size, const class field_body *pBody_t)
{
	this->set(field_name, _size, pBody_t);
}

/**
 *	@brief	    Set field by string field name and class field_body
 *	@param[in]  field name
 *	@param[in]  field_body
 *	@param[out] None 
 *	@return	    None 
 *	@note		String param 'field_name' must end with '\0'
 **/
void field::set(const char *field_name, const class field_body *pBody_t)
{
	string _field_name(field_name, strlen(field_name));

	this->set(_field_name, pBody_t);

	return;
}

field::field(const char *field_name, const class field_body *pBody_t)
{
	this->set(field_name, pBody_t);
}

#endif
/**
 *	@brief	    Operator '==' overloading 
 *	@param[in]  field_line 
 *	@param[out] None 
 *	@return	    ture/false 
 **/
bool field::operator==(const class field &field_line)
{
	return (field_line.get() == this->field_line);
}

/**
 *	@brief	    Get field_line
 *	@param[in]  None 
 *	@param[out] None 
 *	@return	    field_line 
 **/
const string &field::get(void) const noexcept
{
	return field_line;
}

/**
 *	@brief	    Juge if field is empty or not 
 *	@param[in]  None 
 *	@param[out] None
 *	@return	    true/flase 
 **/
bool field::is_empty(void) { return this->field_line.empty();}

/**
 *	@brief	    Get field name from a field line
 *	@param[in]  field_line 
 *	@param[out] None 
 *	@return	    The field name of field line OR ""	
 **/
string field::get_name(const string &field_line)
{
	string::size_type index_colon = field_line.find(':');

	if (index_colon != string::npos)
	{
		string field_name(field_line.begin(), field_line.begin() + index_colon);	

		return field_name;
	}

	return ""; 
}

/**
 *	@brief	    Get field body from a field line
 *	@param[in]  field_line 
 *	@param[out] None 
 *	@return	    The field body of field line OR ""	
 **/
string field::get_body(const string &field_line)
{
	string::size_type index_colon = field_line.find(':');
	
	if (index_colon != string::npos)
	{
		string::size_type i = 1 + index_colon;

		while ((i < field_line.length()-1) && (field_line[i] == ' '))
			i++;/**< Pass spaces before field-body */

		string::size_type j = field_line.find_last_of("\r\n");

		j = (field_line.length() - 1 == j)?2:0; /**< Cut '\r\n' */

		return string(field_line.begin() + i, field_line.end() - j);
	}

	return "";
}

/**
 *	@brief	    Get field name from field_line
 *	@param[in]  None 
 *	@param[out] None 
 *	@return	    The field name of field line OR ""	
 **/
const string field::get_name(void) const noexcept
{
	return this->get_name(field_line);
}

/**
 *	@brief	    Get field body from field_line
 *	@param[in]  None 
 *	@param[out] None 
 *	@return	    The field body of field line OR ""	
 **/
const string field::get_body(void) const noexcept
{
	return this->get_body(field_line);
}


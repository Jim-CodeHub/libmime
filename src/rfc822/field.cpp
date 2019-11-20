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
 *	@brief	    Set field by field_name and field_body
 *	@param[in]  filed_name
 *	@param[in]  filed_body
 *	@param[out] None 
 *	@return	    None 
 *	@note		The function do not parse the legality of param 'field_name'
 **/
void field::set(const string &field_name, const string &field_body)
{
	string colon = ":"	 ;
	string CRLF	 = "\r\n";

	field_line = field_name + colon + field_body + CRLF; 
	
	return;
}

/**
 *	@brief	    Set field by field_name and field_body
 *	@param[in]  filed_name
 *	@param[in]  filed_body
 *	@param[out] None 
 *	@return	    None 
 *	@note		The function do not parse the legality of param 'field_name'
 **/
void field::set(const char *field_name, string::size_type _nSize, const char *field_body, string::size_type _bSize)
{
	string colon = ":"	 ;
	string CRLF	 = "\r\n";

	field_line.clear();
	field_line.append(field_name, _nSize); field_line.append(colon);
	field_line.append(field_body, _nSize); field_line.append(CRLF);

	return;
}

/**
 *	@brief	    Set field by field_line
 *	@param[in]  filed_line
 *	@param[out] None 
 *	@return	    None 
 *	@exception	"const char *", rfc822 field line error! 
 **/
void field::set(const string &field_line)	
{
	string::size_type index_colon = field_line.find(':');
	string::size_type index_CR_LF = field_line.find("\r\n");

	if ((index_colon == string::npos) || (index_CR_LF == string::npos))
	{
		throw("Exception : rfc822 field line error!");
	}

	this->field_line = field_line;

	return;
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
 *	@brief	    Get field name from a field line
 *	@param[in]  filed_line 
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
 *	@param[in]  filed_line 
 *	@param[out] None 
 *	@return	    The field body of field line OR ""	
 **/
string field::get_body(const string &field_line)
{
	string::size_type index_colon = field_line.find(':');
	
	if (index_colon != string::npos)
	{
		string::size_type i = 1 + index_colon;

		while((i < field_line.length()-1) && (field_line[i] == ' '))
			i++;/**< Pass spaces before filed-body */

		string::size_type j = field_line.find_last_of("\r\n");

		j = (field_line.length() - 1 == j)?2:0; /**< Cut '\r\n' */

		return string(field_line.begin() + i, field_line.end() - j);
	}

	return "";
}


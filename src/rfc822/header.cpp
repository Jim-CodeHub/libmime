/**-----------------------------------------------------------------------------------------------------------------
 * @file	header.cpp
 * @brief	Standrad for ARPA Ineternet text messages	
 * @ref		IETF-rfc822
 *
 * Copyright (c) 2019-2019 Jim Zhang 303683086@qq.com
 *------------------------------------------------------------------------------------------------------------------
*/

#include <libMIME/src/rfc822/header.hpp>

using namespace NS_LIBMIME;


/*
--------------------------------------------------------------------------------------------------------------------
*
*			                                  FUNCTIONS IMPLEMENT
*
--------------------------------------------------------------------------------------------------------------------
*/

/**
 *	@brief	    Structure, set match string 
 *	@param[in]  field_name 
 *	@param[out] None
 *	@return		None
 **/
findIFname::findIFname(const string &field_name)
{
	match_name = field_name;
}

/**
 *	@brief	    Structure, set match string 
 *	@param[in]  field_name 
 *	@param[in]  _size - size of field_name 
 *	@param[out] None
 *	@return		None
 **/
findIFname::findIFname(const char *field_name, string::size_type _size)
{
	match_name.assign(field_name, _size);
}

/**
 *	@brief	    Structure, set match string 
 *	@param[in]  FName - class field_name obj reference
 *	@param[out] None
 *	@return		None
 **/
findIFname::findIFname(const class field_name &FName)
{
	match_name = FName.get();
}

/**
 *	@brief	    Operator () overloading, set match condition for 'find_if()' 
 *	@param[in]  field_name 
 *	@param[out] None
 *	@return	    true/false	
 **/
bool findIFname::operator()(const string &field_name)
{
	return (field_name == match_name)?true:false;
}

/**
 *	@brief	    Operator () overloading, set match condition for 'find_if()' 
 *	@param[in]  _field - class field obj reference
 *	@param[out] None
 *	@return	    true/false	
 **/
bool findIFname::operator()(const class field &_field)
{
	return (_field.get_name() == match_name)?true:false;
}

/**
 *	@brief	    Set header with field_line (push at the end of header)
 *	@param[in]  name - field name 
 *	@param[out] None
 *	@return		None
 *	@exception	"Const char *", 
 **/
void header::set(const class field &field_line)
{
	class field separate_line("\r\n", 2); /**< A line seperate from body */

	if (true == headers.empty()) { headers.assign(1, separate_line); }

	if (separate_line == field_line) /**< If header is't empty */
	{
		throw("Exception : rfc822 header error - Overmuch CRLF field!");
	}

	headers.insert(headers.end() - 1, 1, field_line); 

	return;
}

header::header(const class field &field_line)
{
	this->set(field_line);
}

/**
 *	@brief	    Set header by field_name and field_body
 *	@param[in]  field_name
 *	@param[in]  field_body
 *	@param[out] None 
 *	@return	    None 
 *	@note		The function do not parse the legality of param 'field_name'
 **/
void header::set(const string &field_name, const string &field_body)
{
	class field _field(field_name, field_body);

	this->set(_field); return;
}

header::header(const string &field_name, const string &field_body)
{
	this->set(field_name, field_body);
}

/**
 *	@brief	    Set header by field_name and field_body
 *	@param[in]  field_name
 *	@param[in]  field_body
 *	@param[in]  _nSize  - size of field_name 
 *	@param[in]  _bSize  - size of field_body
 *	@param[out] None 
 *	@return	    None 
 *	@note		The function do not parse the legality of param 'field_name'
 **/
void header::set(const char *field_name, string::size_type _nSize, const char *field_body, string::size_type _bSize)
{
	class field _field(field_name, _nSize, field_body, _bSize);

	this->set(_field); return;
}

header::header(const char *field_name, string::size_type _nSize, const char *field_body, string::size_type _bSize)
{
	this->set(field_name, _nSize, field_body, _bSize);
}

/**
 *	@brief	    Set header by field_line
 *	@param[in]  field_line
 *	@param[out] None 
 *	@return	    None 
 *	@exception	"const char *", rfc822 field line error! 
 **/
void header::set(const string &field_line)	
{
	class field _field(field_line);

	this->set(_field); return;
}
		
header::header(const string &field_line)
{
	this->set(field_line);
}

/**
 *	@brief	    Set field by field_line
 *	@param[in]  field_line
 *	@param[out] None 
 *	@return	    None 
 *	@exception	"const char *", rfc822 field line error! 
 **/
void header::set(const char *field_line, string::size_type _size)
{
	class field _field(field_line, _size);

	this->set(_field); return;
}

header::header(const char *field_line, string::size_type _size)
{
	this->set(field_line, _size);
}

/**
 *	@brief	    Set header by class field_name and class field_body
 *	@param[in]  field_name
 *	@param[in]  field_body
 *	@param[out] None 
 *	@return	    None 
 **/
void header::set(class field_name &name_t, class field_body *pBody_t)
{
	class field _field(name_t, pBody_t);

	this->set(_field); return;
}

header::header(class field_name &name_t, class field_body *pBody_t)
{
	this->set(name_t, pBody_t);
}

/**
 *	@brief	    Set header by string field name and class field_body
 *	@param[in]  field name
 *	@param[in]  field_body
 *	@param[out] None 
 *	@return	    None 
 **/
void header::set(const string &field_name, class field_body *pBody_t)
{
	class field _field(field_name, pBody_t);

	this->set(_field); return;
}

header::header(const string &field_name, class field_body *pBody_t)
{
	this->set(field_name, pBody_t);
}

/**
 *	@brief	    Set field by string field name and class field_body
 *	@param[in]  field name
 *	@param[in]  _size  - size of field_name 
 *	@param[in]  field_body
 *	@param[out] None 
 *	@return	    None 
 **/
void header::set(const char *field_name, string::size_type _size, class field_body *pBody_t)
{
	class field _field(field_name, _size, pBody_t);

	this->set(_field); return;
}

header::header(const char *field_name, string::size_type _size, class field_body *pBody_t)
{
	this->set(field_name, _size, pBody_t);
}

/**
 *	@brief	    Get header by field name from header container
 *	@param[in]  field_name
 *	@param[out] None
 *	@return	    field name OR ""
 **/
const string header::get_field(const string &field_name) const noexcept
{
	deque<field>::const_iterator _inx;

	_inx = find_if(headers.begin(), headers.end(), findIFname(field_name));

	return (_inx != headers.end())?((*_inx).get()):"";
}

/**
 *	@brief	    Get header by field name from header container
 *	@param[in]  field_name
 *	@param[in]  _size - size of field name
 *	@param[out] None
 *	@return	    field name OR ""
 **/
const string header::get_field(const char *field_name, string::size_type _size) const noexcept
{
	string _field_name(field_name, _size);

	return get_field(_field_name);
}


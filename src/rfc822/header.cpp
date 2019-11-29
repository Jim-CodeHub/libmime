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
 *	@param[in]  field_line
 *	@param[out] None
 *	@return		None
 **/
void header::set(const class field &field_line)
{
	headers.push_back(field_line);
	return;
}

header::header(const class field &field_line)
{
	this->set(field_line);
}

/**
 *	@brief	    Set header with string field_line
 *	@param[in]  field_line
 *	@param[out] None
 *	@return		None
 **/
void header::set(const string &field_line)
{
	class field _field(field_line);

	this->set(_field);
}

header::header(const string &field_line)
{
	this->set(field_line);
}

/**
 *	@brief	    Set header by class field_name and class field_body
 *	@param[in]  field_name
 *	@param[in]  field_body
 *	@param[out] None 
 *	@return	    None 
 **/
void header::set(const class field_name &name_t, const class field_body *pBody_t)
{
	class field _field(name_t, pBody_t);

	this->set(_field); return;
}
header::header(const class field_name &name_t, const class field_body *pBody_t)
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
void header::set(const string &field_name, const class field_body *pBody_t)
{
	class field _field(field_name, pBody_t);

	this->set(_field); return;
}

header::header(const string &field_name, const class field_body *pBody_t)
{
	this->set(field_name, pBody_t);
}

/**
 *	@brief	    Set header by string field name and string field_body
 *	@param[in]  field name
 *	@param[in]  field_body
 *	@param[out] None 
 *	@return	    None 
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
 *	@brief	    Operator '=' overloading 
 *	@param[in]  _header 
 *	@param[out] None 
 *	@return	    Reference class header 
 **/
const class header &header::operator=(const class header &_header)
{
	this->headers = _header.headers;

	return _header;
}

/**
 *	@brief	    Get field by field name from header container
 *	@param[in]  field_name
 *	@param[out] None
 *	@return	    class field OR ""
 **/
class field header::get_field(const string &field_name) const noexcept
{
	deque<field>::const_iterator _inx;

	_inx = find_if(headers.begin(), headers.end(), findIFname(field_name));

	return (_inx != headers.end())?(*_inx):field("");
}

/**
 *	@brief	    Get header(s)
 *	@param[in]  None 
 *	@param[out] None
 *	@return	    header(s) 
 **/
const string header::get(void) const noexcept
{
	string headers_str;

	deque<field>::const_iterator _big = headers.begin(), _end = headers.end();

	while (_big != _end)
	{
		headers_str += _big->get();
		_big++;
	}

	return headers_str + "\r\n";
}

/**
 *	@brief	    Juge if header is empty or not 
 *	@param[in]  None 
 *	@param[out] None
 *	@return	    true/flase 
 **/
bool header::is_empty(void) { return headers.empty(); }

/**
 *	@brief	    Juge the header name exists whether or not
 *	@param[in]  field_name
 *	@param[out] None
 *	@return	    true/flase 
 **/
bool header::exist_field(const string &field_name)
{
	return (!get_field(field_name).is_empty());
}

/**
 *	@brief	    Clear header 
 *	@param[in]  None 
 *	@param[out] None
 *	@return	    None 
 **/
void header::clear(void) { headers.clear(); }


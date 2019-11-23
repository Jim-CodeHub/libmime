/**-----------------------------------------------------------------------------------------------------------------
 * @file	contenttype_body.cpp
 * @brief	Multi-purpose mail extensions	
 * @ref		IETF-rfc2045, rfc2046, rfc2047, rfc2048, rfc2049 
 *
 * Copyright (c) 2019-2019 Jim Zhang 303683086@qq.com
 *------------------------------------------------------------------------------------------------------------------
*/


#include <libMIME/src/field_body/contenttype_body.hpp>

using namespace NS_LIBMIME;


/*
--------------------------------------------------------------------------------------------------------------------
*
*			                                  FUNCTIONS IMPLEMENT
*
--------------------------------------------------------------------------------------------------------------------
*/

/**
 *	@brief	    Set content_type body
 *	@param[in]  contenttype_body 
 *	@param[out] None
 *	@return		None
 *	@exception  "Const char *", MIME field content_type error
 **/
void contenttype_body::set(const string &contenttype_body)
{
	string_token _tok_sem(contenttype_body, ";");
	string types;

	if ("" == (types = _tok_sem.get_stok(0)))
	{
		throw("Exception : MIME field content_type body error - wrong format!");
	}

	/**< Parse content type - major_type and minor_type */

	string_token _tok_sla(types, "/");

	if ("" == _tok_sla.get_stok(0))
	{
		throw("Exception : MIME field content type error - wrong format!");
	}

	this->major_type = _tok_sla.get_stok(0);
	this->minor_type = _tok_sla.get_stok(1);

	/**< Parse content type - parameter list */
	string param_tok;

	for (string::size_type i = 1; ("" != (param_tok = _tok_sem.get_stok(i))); i++)
	{
		class param _param(param_tok);
		parameters.push_back(_param);
	}

	return;
}

contenttype_body::contenttype_body(const string &contenttype_body)
{
	this->set(contenttype_body);
}

/**
 *	@brief	    Set content_type body
 *	@param[in]  contenttype_body 
 *	@param[in]  _size - size of contenttype_body  
 *	@param[out] None
 *	@return		None
 *	@exception  "Const char *", MIME field content_type error
 **/
void contenttype_body::set(const char *contenttype_body, string::size_type _size)
{
	string cbody(contenttype_body, _size);
	this->set(cbody);	           return;
}

contenttype_body::contenttype_body(const char *contenttype_body, string::size_type _size)
{
	this->set(contenttype_body, _size);
}

/**
 *	@brief	    Set content_type body
 *	@param[in]  contenttype_body 
 *	@param[out] None
 *	@return		None
 *	@exception  "Const char *", MIME field content_type error
 *	@note		The string param 'contenttype_body' must end with '\0'
 **/
void contenttype_body::set(const char *contenttype_body)
{
	string cbody(contenttype_body, strlen(contenttype_body));
	this->set(cbody);								  return;
}

contenttype_body::contenttype_body(const char *contenttype_body)
{
	this->set(contenttype_body);
}

/**
 *	@brief	    Get content_type body
 *	@param[in]  None 
 *	@param[out] None
 *	@return		content_type body	
 **/
const string contenttype_body::get(void) const noexcept
{
	string contenttype_body = this->major_type + "/" + this->minor_type; 

	list<param>::const_iterator _big = parameters.begin(), _end = parameters.end();

	while(_big != _end)
	{
		contenttype_body += "; " + _big->get();
		_big++;
	}

	return contenttype_body; 
}

/**
 *	@brief	    Set major_type and minor_type of content_type body
 *	@param[in]  major_type 
 *	@param[in]  minor_type 
 *	@param[out] None
 *	@return		None
 *	@exception  "Const char *", MIME field major/minor type error
 **/
void contenttype_body::set(const string &major_type, const string &minor_type)
{
	if ((string::npos != major_type.find_first_of(" ")) || (string::npos != minor_type.find_first_of(" ")))
	{
		throw("Exception : MIME field major/minor type error - wrong format!");
	}

	this->major_type = major_type;
	this->minor_type = minor_type;

	return;
}

contenttype_body::contenttype_body(const string &major_type, const string &minor_type)
{
	this->set(major_type, minor_type);
}

/**
 *	@brief	    Set major_type and minor_type of content_type body
 *	@param[in]  major_type 
 *	@param[in]  _mjrSize  - size of major_type 
 *	@param[in]  minor_type
 *	@param[in]  _morSize  - size of minor_type
 *	@param[out] None
 *	@return		None
 *	@exception  "Const char *", MIME field major/minor type error
 **/
void contenttype_body::set(const char *major_type, string::size_type _mjrSize, const char *minor_type, string::size_type _morSize)
{
	string _major_type(major_type, _mjrSize);
	string _minor_type(minor_type, _morSize);

	this->set(_major_type, _minor_type);
	return;
}

contenttype_body::contenttype_body(const char *major_type, string::size_type _mjrSize, const char *minor_type, string::size_type _morSize)
{
	this->set(major_type, _mjrSize, minor_type, _morSize);
}

/**
 *	@brief	    Set major_type and minor_type of content_type body
 *	@param[in]  major_type 
 *	@param[in]  minor_type
 *	@param[out] None
 *	@return		None
 *	@note		The string param 'major_type' and 'minor_type' must end with '\0'
 *	@exception  "Const char *", MIME field major/minor type error
 **/
void contenttype_body::set(const char *major_type, const char *minor_type)
{
	string _major_type(major_type, strlen(major_type));
	string _minor_type(minor_type, strlen(minor_type));

	this->set(_major_type, _minor_type);
	return;
}

contenttype_body::contenttype_body(const char *major_type, const char *minor_type)
{
	this->set(major_type, minor_type);
}

/**
 *	@brief	    Set parameter of content_type body
 *	@param[in]  _param 
 *	@param[out] None
 *	@return		None
 **/
void contenttype_body::set_param(const class param &_param)
{
	this->parameters.push_back(_param);
	return;
}

/**
 *	@brief	    Set parameter of content_type body
 *	@param[in]  _param 
 *	@param[out] None
 *	@return		None
 **/
void contenttype_body::set_param(const string &_param)
{
	class param _param_(_param);

	this->parameters.push_back(_param_);
	return;
}

/**
 *	@brief	    Set parameter of content_type body
 *	@param[in]  _param 
 *	@param[in]  _size - size of _param 
 *	@param[out] None
 *	@return		None
 **/
void contenttype_body::set_param(const char *_param, string::size_type _size)
{
	class param _param_(_param, _size);

	this->parameters.push_back(_param_);
	return;
}

/**
 *	@brief	    Set parameter of content_type body
 *	@param[in]  _param 
 *	@param[out] None
 *	@return		None
 **/
void contenttype_body::set_param(const char *_param)
{
	class param _param_(_param);

	this->parameters.push_back(_param_);
	return;
}

/**
 *	@brief	    Set parameter of content_type body
 *	@param[in]  attr  - param's attribute
 *	@param[in]  value - param's value 
 *	@param[out] None
 *	@return		None
 **/
void contenttype_body::set_param(const string &attr, const string &value)
{
	class param _param_(attr, value);

	this->parameters.push_back(_param_);
	return;
}

/**
 *	@brief	    Set parameter of content_type body
 *	@param[in]  attr   - param's attribute
 *	@param[in]  _nSize - size of atrr
 *	@param[in]  value  - param's value 
 *	@param[in]  _vSize - size of value 
 *	@param[out] None
 *	@return		None
 **/
void contenttype_body::set_param(const char *attr, string::size_type _nSize, const char *value, string::size_type _vSize)
{
	class param _param_(attr, _nSize, value, _vSize);

	this->parameters.push_back(_param_);
	return;
}

/**
 *	@brief	    Set parameter of content_type body
 *	@param[in]  attr   - param's attribute
 *	@param[in]  _nSize - size of atrr
 *	@param[in]  value  - param's value 
 *	@param[in]  _vSize - size of value 
 *	@param[out] None
 *	@return		None
 *	@note		The string param 'attr' and 'value' must end with '\0'
 **/
void contenttype_body::set_param(const char *attr, const char *value)
{
	class param _param_(attr, value);

	this->parameters.push_back(_param_);
	return;
}

/**
 *	@brief	    Get major_type/minor_type pair string
 *	@param[in]  None 
 *	@param[out] None
 *	@return		major_type/minor_type pair string
 **/
const string contenttype_body::get_types(void) const noexcept
{
	return this->major_type + "/" + this->minor_type;
}

/**
 *	@brief	    Get major_type
 *	@param[in]  None 
 *	@param[out] None
 *	@return		major_type string
 **/
const string &contenttype_body::get_major_type(void) const noexcept
{
	return this->major_type;
}

/**
 *	@brief	    Get minor_type
 *	@param[in]  None 
 *	@param[out] None
 *	@return		minor_type string
 **/
const string &contenttype_body::get_minor_type(void) const noexcept
{
	return this->minor_type;
}

/**
 *	@brief	    Get parameters value by it's attribute 
 *	@param[in]  attr 
 *	@param[out] None
 *	@return	    parameters value that match attr OR "" if not match	
 **/
const string contenttype_body::get_param_value(const string &attr) const noexcept
{
	list<param>::const_iterator _big = parameters.begin(), _end = parameters.end();

	while (_big != _end)
	{
		if (_big->get_attr() == attr) { return _big->get_value(); }

		_big++;
	}

	return "";
}

/**
 *	@brief	    Get parameters value by it's attribute 
 *	@param[in]  attr 
 *	@param[in]  _size - size of attr 
 *	@param[out] None
 *	@return	    parameters value that match attr OR "" if not match	
 **/
const string contenttype_body::get_param_value(const char *attr, string::size_type _size) const noexcept
{
	string _attr(attr, _size		  );

	return this->get_param_value(_attr);
}

/**
 *	@brief	    Get parameters value by it's attribute 
 *	@param[in]  attr 
 *	@param[out] None
 *	@return	    parameters value that match attr OR "" if not match
 *	@note		The string param 'attr' must end with '\0'
 **/
const string contenttype_body::get_param_value(const char *attr) const noexcept
{
	string _attr(attr, strlen(attr)	  );

	return this->get_param_value(_attr);
}

/**
 *	@brief	    Construct content type boundary
 *	@param[in]  None 
 *	@param[out] None
 *	@return	    Content type boundary 
 **/
const string contenttype_body::construct_boundary(void)
{
	static uint8_t seed_count = 0;

	string boundary;
	char   asciibet[] = "abcdefghijklmnopqrstuvwxyz_()+/=,:?'ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	auto time_ms = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch());

	default_random_engine e(time_ms.count() + (seed_count++));

	stringstream ss;

	for (int i = 0 ; i < CONTENTTYPE_BODY_BOUNDARY_MAX; i++)
	{
		ss << asciibet[e() % sizeof(asciibet)]; 
	}

	ss >> boundary;

	boundary = "\"" + boundary.substr(0, CONTENTTYPE_BODY_BOUNDARY_MAX) + "\""; /**< Set quoting */

	return boundary;
}


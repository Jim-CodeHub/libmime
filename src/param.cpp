/**-----------------------------------------------------------------------------------------------------------------
 * @file	param.cpp
 * @brief	Multi-purpose mail extensions	
 * @ref		IETF-rfc2045, rfc2046, rfc2047, rfc2048, rfc2049 
 *
 * Copyright (c) 2019-2019 Jim Zhang 303683086@qq.com
 *------------------------------------------------------------------------------------------------------------------
*/

#include <libMIME/src/param.hpp>

using namespace NS_LIBMIME;


/*
--------------------------------------------------------------------------------------------------------------------
*
*			                                  FUNCTIONS IMPLEMENT
*
--------------------------------------------------------------------------------------------------------------------
*/

/**
 *	@brief	    Set parameter 
 *	@param[in]  param 
 *	@param[out] None
 *	@return		None
 *	@exception  "Const char *", MIME field param error 
 **/
void param::set(const string &param)
{
	string::size_type _index = param.find("=", 0);

	if (string::npos == _index)
	{
		throw("Exception : MIME field param error - wrong format!");
	}

	this->params = param;
	return;
}

param::param(const string &param) { this->set(param); }

/**
 *	@brief	    Set parameter 
 *	@param[in]  param 
 *	@param[in]  _size  - size of param
 *	@param[out] None
 *	@return		None
 *	@exception  "Const char *", MIME field param error 
 **/
void param::set(const char *param, string::size_type _size)
{
	string _param(param, _size);

	this->params.assign(param); return;
}

param::param(const char *param, string::size_type _size)
{
	this->set(param, _size);
}

/**
 *	@brief	    Set parameter 
 *	@param[in]  param 
 *	@param[out] None
 *	@return		None
 *	@exception  "Const char *", MIME field param error 
 *	@note		The string param 'param' must end with '\0'
 **/
void param::set(const char *param)
{
	string _param(param, strlen(param));

	this->params.assign(param); return;
}

param::param(const char *param) { this->set(param); }
	
/**
 *	@brief	    Set attr and value of parameter 
 *	@param[in]  attr  
 *	@param[in]  value 
 *	@param[out] None
 *	@return		None
 *	@exception  "Const char *", MIME field param attr/value error
 **/
void param::set(const string &attr, const string &value)
{
	string invalid_attr  = util::get_CTLs() + " " + util::get_tspecials();
	string invalid_value = util::get_CTLs() + " ";

	string::size_type _vIndex = attr .find_first_of(invalid_attr , 0);
	string::size_type _vValue = value.find_first_of(invalid_value, 0);

	if ((string::npos != _vIndex) || (string::npos != _vValue))
	{
		throw("Exception : MIME field param attr/value error - wrong format!");
	}

	string _value = value;

	if ((*(value.begin()) != '"') || (*(value.end() - 1) != '"'))
	{
		if (string::npos != value.find_first_of("()\\<>\"@,;:/[]?="))
		{
			_value = "\""+ value + "\""; 
		}
	}

	this->params = attr + "=" + _value;
	return;
}

param::param(const string &attr, const string &value)
{
	this->set(attr, value);
}

/**
 *	@brief	    Set attr and value of parameter 
 *	@param[in]  attr  
 *	@param[in]  _nSize - size of attr 
 *	@param[in]  value 
 *	@param[in]  _vSize - size of value 
 *	@param[out] None
 *	@return		None
 *	@exception  "Const char *", MIME field param attr/value error
 **/
void param::set(const char *attr, string::size_type _nSize, const char *value, string::size_type _vSize)
{
	string _attr (attr,  _nSize);
	string _value(value, _vSize);

	this->set(_attr, _value); return;
}

param::param(const char *attr, string::size_type _nSize, const char *value, string::size_type _vSize)
{
	this->set(attr, _nSize, value, _vSize);
}

/**
 *	@brief	    Set attr and value of parameter 
 *	@param[in]  attr  
 *	@param[in]  value 
 *	@param[out] None
 *	@return		None
 *	@note		The string param 'param' must end with '\0'
 *	@exception  "Const char *", MIME field param attr/value error
 **/
void param::set(const char *attr, const char *value)
{
	string _attr (attr,  strlen(attr ));
	string _value(value, strlen(value));

	this->set(_attr, _value); return;
}

param::param(const char *attr, const char *value)
{
	this->set(attr, value);
}

/**
 *	@brief	    Get parameter 
 *	@param[in]  None 
 *	@param[out] None
 *	@return	    parameter	
 **/
const string &param::get(void) const noexcept
{
	return this->params;
}

/**
 *	@brief	    Get attr of parameter 
 *	@param[in]  None 
 *	@param[out] None
 *	@return	    The attr of parameter or ""
 **/
const string param::get_attr(void) const noexcept
{
	return param::get_attr(params);
}

/**
 *	@brief	    Get value of parameter 
 *	@param[in]  None 
 *	@param[out] None
 *	@return	    The attr of parameter or ""
 **/
const string param::get_value(void) const noexcept
{
	return param::get_value(params);
}

/**
 *	@brief	    Get attr of parameter 
 *	@param[in]  param 
 *	@param[out] None
 *	@return	    The attr of parameter or ""
 **/
const string param::get_attr(const string &param)
{
	string _attr = "";
	string _param = field_body::unfold(param);

	string::size_type i = 0, j = 0, _index = _param.find("=", 0);  

	if (string::npos != _index)
	{
		string::iterator _big = _param.begin(), _end = _param.begin() + _index - 1;

		while(_end != _big)
		{
			if ((*_end == ' ') || (*_end == '\t'))
			{ i++; /**< Skip LWSP before '=' */	 }
			else
			{ break;							 }

			_end--;
		}

		while(_big != _end)
		{
			if ((*_big == ' ') || (*_big == '\t'))
			{ j++; /**< Skip LWSP before attr */ }
			else
			{ break;							 }
				
			_big++;
		}

		_attr.assign(_param.begin() + j, _param.begin() + _index - i);	
	}

	return _attr;
}

/**
 *	@brief	    Get attr of parameter 
 *	@param[in]  param 
 *	@param[in]  _size - size of param 
 *	@param[out] None
 *	@return	    The attr of parameter or ""
 **/
const string param::get_attr(const char *param, string::size_type _size)
{
	const string _param(param, _size);

	return param::get_attr(_param);
}

/**
 *	@brief	    Get attr of parameter 
 *	@param[in]  param 
 *	@param[out] None
 *	@return	    The attr of parameter or ""
 *	@note		The string param 'param' must end with '\0'
 **/
const string param::get_attr(const char *param)
{
	string _param(param, strlen(param));

	return param::get_attr(_param);
}

/**
 *	@brief	    Get value of parameter 
 *	@param[in]  param
 *	@param[out] None
 *	@return	    The value of parameter or ""
 **/
const string param::get_value(const string &param)
{
	string _value = "";
	string _param = field_body::unfold(param);

	string::size_type i = 0, j = 0, _index = _param.find("=", 0);  

	if (string::npos != _index)
	{
		string::iterator _big = _param.begin() + _index + 1, _end = _param.end() - 1;

		while(_big != _end)
		{
			if ((*_big == ' ') || (*_big == '\t'))
			{ i++; /**< Skip LWSP before '=' */	 }
			else
			{ break;							 }

			_big++;
		}

		while(_end != _big)
		{
			if ((*_end == ' ') || (*_end == '\t'))
			{ j++; /**< Skip LWSP after value */ }
			else
			{ break;							 }
		
			_end--;
		}

		if ((*_big == '"') && (*_end == '"'))
		{ i++; j++; /**< Remove duo '"' */  }

		_value.assign(_param.begin() + _index + 1 + i, _param.end() - j);
	}

	return _value;
}

/**
 *	@brief	    Get value of parameter 
 *	@param[in]  param
 *	@param[in]  _size - size of param
 *	@param[out] None
 *	@return	    The value of parameter or ""
 **/
const string param::get_value(const char *param, string::size_type _size)
{
	string _param(param, _size);

	return param::get_value(_param);
}

/**
 *	@brief	    Get value of parameter 
 *	@param[in]  param
 *	@param[out] None
 *	@return	    The value of parameter or ""
 *	@note		The string param 'param' must end with '\0'
 **/
const string param::get_value(const char *param)
{
	string _param(param, strlen(param));

	return param::get_value(_param);
}


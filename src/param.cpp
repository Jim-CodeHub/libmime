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

	if (string::npos != _index)
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
 *	@brief	    Set name and value of parameter 
 *	@param[in]  name  
 *	@param[in]  value 
 *	@param[out] None
 *	@return		None
 *	@exception  "Const char *", MIME field param name/value error
 **/
void param::set(const string &name, const string &value)
{
	string::size_type _vIndex = name .find("=", 0);
	string::size_type _vValue = value.find("=", 0);

	if ((string::npos == _vIndex) || (string::npos == _vValue))
	{
		throw("Exception : MIME field param name/value error - wrong format!");
	}

	this->params = name + "=" + value;
	return;
}

param::param(const string &name, const string &value)
{
	this->set(name, value);
}

/**
 *	@brief	    Set name and value of parameter 
 *	@param[in]  name  
 *	@param[in]  _nSize - size of name 
 *	@param[in]  value 
 *	@param[in]  _vSize - size of value 
 *	@param[out] None
 *	@return		None
 *	@exception  "Const char *", MIME field param name/value error
 **/
void param::set(const char *name, string::size_type _nSize, const char *value, string::size_type _vSize)
{
	string _name (name,  _nSize);
	string _value(value, _vSize);

	this->set(_name, _value); return;
}

param::param(const char *name, string::size_type _nSize, const char *value, string::size_type _vSize)
{
	this->set(name, _nSize, value, _vSize);
}

/**
 *	@brief	    Set name and value of parameter 
 *	@param[in]  name  
 *	@param[in]  value 
 *	@param[out] None
 *	@return		None
 *	@note		The string param 'param' must end with '\0'
 *	@exception  "Const char *", MIME field param name/value error
 **/
void param::set(const char *name, const char *value)
{
	string _name (name,  strlen(name ));
	string _value(value, strlen(value));

	this->set(_name, _value); return;
}

param::param(const char *name, const char *value)
{
	this->set(name, value);
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
 *	@brief	    Get name of parameter 
 *	@param[in]  None 
 *	@param[out] None
 *	@return	    The name of parameter or ""
 **/
const string param::get_name(void) const noexcept
{
	return param::get_name(params);
}

/**
 *	@brief	    Get value of parameter 
 *	@param[in]  None 
 *	@param[out] None
 *	@return	    The name of parameter or ""
 **/
const string param::get_value(void) const noexcept
{
	return param::get_value(params);
}

/**
 *	@brief	    Get name of parameter 
 *	@param[in]  param 
 *	@param[out] None
 *	@return	    The name of parameter or ""
 **/
const string param::get_name(const string &param)
{
	string _name = "";
	string _param = field_body::unfold(param);

	string::size_type i = 0, _index = _param.find("=", 0);  

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

		_name.assign(_param.begin(), _param.begin() + _index - i);	
	}

	return _name;
}

/**
 *	@brief	    Get name of parameter 
 *	@param[in]  param 
 *	@param[in]  _size - size of param 
 *	@param[out] None
 *	@return	    The name of parameter or ""
 **/
const string param::get_name(const char *param, string::size_type _size)
{
	const string _param(param, _size);

	return param::get_name(_param);
}

/**
 *	@brief	    Get name of parameter 
 *	@param[in]  param 
 *	@param[out] None
 *	@return	    The name of parameter or ""
 *	@note		The string param 'param' must end with '\0'
 **/
const string param::get_name(const char *param)
{
	string _param(param, strlen(param));

	return param::get_name(_param);
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

	string::size_type i = 0, _index = _param.find("=", 0);  

	if (string::npos != _index)
	{
		string::iterator _big = _param.begin() + _index + 1, _end = _param.end();

		while(_big != _end)
		{
			if ((*_big == ' ') || (*_big == '\t'))
			{ i++; /**< Skip LWSP before '=' */	 }
			else
			{ break;							 }

			_big++;
		}

		_value.assign(_param.begin() + _index + i, _param.end());
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


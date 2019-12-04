/**-----------------------------------------------------------------------------------------------------------------
 * @file	mime_header.cpp
 * @brief	Multi-purpose mail extensions	
 * @ref		IETF-rfc2045, rfc2046, rfc2047, rfc2048, rfc2049 
 *
 * Copyright (c) 2019-2019 Jim Zhang 303683086@qq.com
 *------------------------------------------------------------------------------------------------------------------
*/

#include <libmime/header/mime_header.hpp>

using namespace NS_LIBMIME;


/*
--------------------------------------------------------------------------------------------------------------------
*
*			                                  FUNCTIONS IMPLEMENT
*
--------------------------------------------------------------------------------------------------------------------
*/

/**
 *	@brief	    Set mime header with official field name (and body)
 *	@param[in]  fname_t - official field name enumeration 
 *	@param[in]  pBody_t - field_body instance 
 *	@param[out] None 
 *	@return	    None 
 *	@exception  "Const char *", field body IS NOT MATCH the field name
 **/
void mime_header::set(enum MIME_FNAME fname_t, const class field_body *pBody_t)
{
	string _FNAME[] = {"MIME-Version", "Content-Type", "Content-Id", "Content-Disposition", "Content-Description",
		               "Content-Transfer-Encoding"}; 

	if ((pBody_t->get_lable() != string_body::lable) && (pBody_t->get_lable() != _FNAME[fname_t]))
	{
		throw ("Exception : 'mime_header.cpp' - field body IS NOT MATCH the field name");
	}

	class field_name name_t(_FNAME[fname_t]);

	class field _field(name_t, pBody_t	   );
	header::set(_field);              return;
}

mime_header::mime_header(enum MIME_FNAME fname_t, const class field_body *pBody_t)
{
	this->set(fname_t, pBody_t);
}

/**
 *	@brief	    Set mime header with class field 
 *	@param[in]  field_line 
 *	@param[out] None 
 *	@return	    None 
 **/
void mime_header::set(const class field &field_line)
{
	this->header::set(field_line);
	return;
}

/**
 *	@brief	    Set extension mime header with string 
 *	@param[in]  _name	- string name 
 *	@param[in]  pBody_t - field_body instance 
 *	@param[out] None 
 *	@return	    None 
 **/
void mime_header::set(const string &field_name, const class field_body *pBody_t)
{
	this->header::set(field_name, pBody_t);
	return;
}

/**
 *	@brief	    Get mime header field with official field name
 *	@param[in]  MIME_FNAME - official field name enumeration 
 *	@param[out] None 
 *	@return	    Reference class field 
 **/
class field &mime_header::get_field(enum MIME_FNAME fname_t)
{
	string _FNAME[] = {"MIME-Version", "Content-Type", "Content-Id", "Content-Disposition", "Content-Description",
		               "Content-Transfer-Encoding"}; 

	return header::get_field(_FNAME[fname_t]);
}


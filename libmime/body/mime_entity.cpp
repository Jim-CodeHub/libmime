/**-----------------------------------------------------------------------------------------------------------------
 * @file	mime_entity.cpp
 * @brief	Multi-purpose mail extensions	
 * @ref		IETF-rfc2045, rfc2046, rfc2047, rfc2048, rfc2049 
 *
 * Copyright (c) 2019-2019 Jim Zhang 303683086@qq.com
 *------------------------------------------------------------------------------------------------------------------
*/

#include <libmime/body/mime_entity.hpp>

using namespace NS_LIBMIME;


/*
--------------------------------------------------------------------------------------------------------------------
*
*			                                  FUNCTIONS IMPLEMENT
*
--------------------------------------------------------------------------------------------------------------------
*/

/**
 *	@brief	    Set a basic (ancestor) entity header 
 *	@param[in]  header - class mime_header 
 *	@param[out] None 
 *	@return	    None 
 **/
mime_entity::mime_entity(class mime_header &header)
{
	this->nest   = true	 ;
	this->header = header;
}

/**
 *	@brief	    Delete the header field, if it's not belong to the mime entity
 *	@param[in]  _header 
 *	@param[out] None 
 *	@return	    Reference class mime_header which has been filtered 
 **/
const class mime_header &mime_entity::check_header(class mime_header &_header)
{
	long unsigned int i = 0;

	while (!(field::null_field == (_header.header::get_field(i))))
	{
		if (string::npos == (_header.header::get_field(i)).get_name().find("Content-", 0))
		{
			_header.remove((_header.header::get_field(i)).get_name());
			continue;
		}

		i++;
	}

	return _header;
}

/**
 *	@brief	    Set mime entity leaf node 
 *	@param[in]  header - mime entity header 
 *	@param[in]  sdbody - mime entity shadow body 
 *	@param[out] None 
 *	@return	    None 
 *	@note		The function can be called repeatedly, but only to save the last settings 
 *	@note		The function SHOULD BE used as a leaf node setting 
 *	@note		The header will be filtered when set an non-mime-entity header
 *	@note		Base64 encoding will be used as default
 **/
void mime_entity::set_node(class mime_header &header, const class body_shadow &sdbody)
{
	this->header = check_header(header);

	class codec _codec;

	string encode = this->header.get_field(Content_Transfer_Encoding).get_body();

	class string_body str_body("base64");

	_codec.encode((encode == "")
			?(this->header.set(Content_Transfer_Encoding, &str_body), "base64")
			:util::to_lower(encode) 
			
			, sdbody.get(), *(this->sdbody.bodys));

	return;
}

/**
 *	@brief	    Set mime entity leaf node 
 *	@param[in]  header - mime entity header 
 *	@param[in]  body   - string body 
 *	@param[in]  _size  - size of string body 
 *	@param[out] None 
 *	@return	    None 
 *	@note		1. The function can be called repeatedly, but only to save the last settings 
 *				2. The function SHOULD BE used as a leaf node setting 
 *				3. The header will be filtered when set an non-mime-entity header
 *			    4. Base64 encoding will be used as default
 *
 *			    5. NOTE THAT IF '\0' IS A VALID MESSAGE, TO USE THE EXACT _SIZE VALUE
 *				   , OR Param '_size' default value is 0 AND 'body.size()' will be used. 
 **/
void mime_entity::set_node(class mime_header &header, const string &body, string::size_type _size)
{
	class body_shadow sdbody(body, (0 == _size)?body.size():_size);

	this->set_node(header, sdbody); return;
}

/**
 *	@brief	    Set mime enity part which under the param 'header' 
 *	@param[in]  header - mime entity (part father's) header
 *	@param[out] None 
 *	@return		mime entity part pointer OR NULL if subtype 'mixed' does not exsists
 *
 *	@note		*Param 'header'
 *					1. belong to the part father
 *					2. will be filtered when an non-mime-entity header setted 
 *					3. only to save the first settings when set mutil times
 *
 *	@note		*Multi part depth
 *					1. The function can be called repeatedly, to set sub-part with return pointer OR
 *					   to set brother-part under the same object 
 *					2. Only 'Content-Type' with major-type 'multipart' and subtype 'mixed' can be nested deeply, 
 *					   if not in this case, NULL will be returned
 *
 *	@exception  "Const char *" 'multipart' type does not exsits & 'mixed' subtyp lose
 **/
class mime_entity *mime_entity::set_part(class mime_header &header)
{
	/**----------------------------------------------------------------------------*/
	/**< Nesting check */

	if (false == this->nest) 
	{
		throw("Exception : 'mime_entity.cpp' - 'mixed' subtype lose, connot continue nesting!");
	}

	/**----------------------------------------------------------------------------*/
	/**< Set header */

	if (this->header.is_empty()) {
		this->header = check_header(header);
	}

	/**----------------------------------------------------------------------------*/
	/**< Multi-part check */

	contenttype_body cb(this->header.get_field(Content_Type).get_body());

	if (cb.get_major_type() != "multipart")
	{
		throw("Exception : 'mime_entity.cpp' - 'multipart' type does not exsits!");
	}

	this->sdbody.clear();

	/**----------------------------------------------------------------------------*/
	/**< Make part instance */

	class mime_entity *pEntity = new class mime_entity();

	pEntity->nest = (cb.get_minor_type() == "mixed")?true:false;

	this->sdbody.part_entity.push_back(pEntity);
	
	return pEntity;
}

/**
 *	@brief	    Set mime enity part which under FATHER header
 *	@param[in]  None 
 *	@param[out] None 
 *	@return		mime entity part pointer OR NULL if subtype 'mixed' does not exsists
 *
 *	@note		Use this funtion when FATHER HEADER already has been setted
 *
 *	@note		*Multi part depth
 *					1. The function can be called repeatedly, to set sub-part with return pointer OR
 *					   to set brother-part under the same object 
 *					2. Only 'Content-Type' with major-type 'multipart' and subtype 'mixed' can be nested deeply, 
 *					   if not in this case, NULL will be returned
 *
 *	@exception  "Const char *" 'multipart' type does not exsits & 'mixed' subtyp lose
 **/
class mime_entity *mime_entity::set_part(void)
{
	class mime_header	  header ;

	return this->set_part(header);
}

/**
 *	@brief	    Get mime entity
 *	@param[in]  None 
 *	@param[out] None 
 *	@return	    mime entity 
 *	@note		Base64 encoding will be used as default
 **/
const string mime_entity::make(void)
{
	string _mime_entity, boundary;
	list<class mime_entity*>::const_iterator _big = this->sdbody.part_entity.begin(),
											 _end = this->sdbody.part_entity.  end();
	class contenttype_body cb;

	/**----------------------------------------------------------------------------*/
	/**< Mult-part does not exsits (End recursive) */

	if (_big == _end) {_mime_entity = this->header.get(); goto _ADD_NODE_BODY; }

	/**----------------------------------------------------------------------------*/
	/**< Construct AND set boundary AND set header */

	cb.set(this->header.get_field(Content_Type).get_body());

	if ("" == (boundary = cb.get_param_value("boundary")))
	{
		boundary = contenttype_body::construct_boundary();
		cb.set_param("boundary", boundary);

		this->header.get_field(Content_Type).set_body(&cb);
	}

	_mime_entity  = this->header.get();

	if (('\"' == *(boundary.begin())) && ('\"' == *(boundary.rbegin())))
	{
		boundary.erase(0, 1);
		boundary.erase(boundary.size() - 1, 1);
	}

	/**----------------------------------------------------------------------------*/
	/**< Recursive sub multi-part */

	while ((_big != _end) && (NULL != *_big))
	{
		_mime_entity += "--" + boundary + "\r\n";

		_mime_entity += (*_big)->make() + "\r\n"; _big++;
	}

	_mime_entity.erase(_mime_entity.size()-2, 2); /**< Delete '\r\n' that end of the last part */

	_mime_entity += "\r\n--" + boundary + "--"  ;

_ADD_NODE_BODY:
	_mime_entity += *(this->sdbody.bodys);

	/**----------------------------------------------------------------------------*/
	/**< Release entity */

	this->clear();

	return _mime_entity; 
}

/**
 *	@brief	    Load mime entity from some string buffer 
 *	@param[in]  entity  - entity buffer 
 *	@param[in]  _size   - size of entity buffer
 *	@param[out] None 
 *	@return     true/flase
 *	@note		*** TO BE SURE param 'entity' has certain size info, If entity contain '\0' 
 **/
bool mime_entity::load(string &entity)
{
	/**============================= BASIC HANDLER ================================*/

	/**----------------------------------------------------------------------------*/
	/**< Clear mime entity */ 

	this->clear();

	/**----------------------------------------------------------------------------*/
	/**< Implicitly typed plain US-ASCII text handler */

	if (entity.find("\r\n", 0) == 0)  
	{ 
		this->sdbody.set(entity.substr(2, entity.size()), entity.size()-2);
		return true;
	}	

	/**----------------------------------------------------------------------------*/
	/**< Get header string and body string */

	class string_token stok_entity; stok_entity.cut(entity, "\r\n\r\n");

	string header  = stok_entity.get_stok(0); /**< Get header		*/
		   header += "\r\n"; /**< Add '\r\n' which has benn cut off */

	string sdbody  = stok_entity.get_stok(1); /**< Get body			*/

	/**============================= HEADER HANDLER ===============================*/

	/**----------------------------------------------------------------------------*/
	/**< Write header */
	
	header = field_body::unfold(header);

	class string_token stok_header; stok_header.set(header, "\r\n");

	string field_line;
	string::size_type i = 0;

	while ("" != (field_line = stok_header.get_stok(i)))
	{
		class string_token stok_line;
						   stok_line.cut(field_line, ":");

		class field_name  fname(stok_line.get_stok(0));
		class string_body sbody(stok_line.get_stok(1));

		class field _field(fname, &sbody);
		this->header.set(_field);

		i++;
	}

	/**============================= BODY HANDLER ==================================*/

	string contenttype_body, boundary, _big_boundary, _end_boundary;
	string::size_type				   _big_inx,      _end_inx	   ;
	class  contenttype_body cb;

	/**----------------------------------------------------------------------------*/
	/**< Write body */

	if (("" == sdbody) 
			|| ("" == (contenttype_body = this->header.get_field(Content_Type).get_body()))
			|| (cb.set(contenttype_body), cb.get_major_type() != "multipart")
			|| ("" == (boundary = cb.get_param_value("boundary"))) /**< Duo \" stripped  */
			)
	{
		goto _ADD_NODE_BODY;
	}

	/**----------------------------------------------------------------------------*/
	/**< Boundary handler */

	_big_boundary = "--" + boundary;
	_end_boundary = "--" + boundary + "--";

	/**----------------------------------------------------------------------------*/
	/**< Multi-part handler */

	_big_inx = 0;
	_end_inx = sdbody.find(_end_boundary, 0);

	while (_end_inx != (_big_inx = sdbody.find(_big_boundary, _big_inx)))
	{
		_big_inx  = sdbody.find("\r\n", _big_inx); /**< Skip boundary and LWSP */

		_big_inx += 2; /**< Skip '\r\n' */

		string::size_type _ovr_inx = sdbody.find(_big_boundary, _big_inx);

		string entity = sdbody.substr(_big_inx, _ovr_inx - _big_inx);

		class mime_entity *pEntity = new class mime_entity;

		this->sdbody.part_entity.push_back(pEntity);

		pEntity->load(entity);

		if (_ovr_inx == _end_inx)
			break; /**< End of this entity */

		_big_inx = _ovr_inx;
	}

	return true;

_ADD_NODE_BODY:

	/**----------------------------------------------------------------------------*/
	/**< Delete '\r\n' after the body */ 

	string::size_type _inx;

	while (string::npos != (_inx = sdbody.find("\r\n", sdbody.size()-2)))
	{
		sdbody.erase(sdbody.size()-2, 2);
	}

	/**----------------------------------------------------------------------------*/
	/**< Decode and set body */

	string decode; class codec _codec;

	if ("" == (decode = this->header.get_field(Content_Transfer_Encoding).get_body()))
	{
		this->sdbody.bodys->assign(sdbody); goto _EXIT;
	}

	_codec.decode(util::to_lower(decode), sdbody, *(this->sdbody.bodys));

_EXIT:
	return true;
}

/**
 *	@brief	    Load mime entity from some string buffer 
 *	@param[in]  entity  - entity buffer 
 *	@param[in]  _size   - size of entity buffer
 *	@param[out] None 
 **/
bool mime_entity::load(const char *entity, string::size_type _size)
{
	string _entity(entity, _size);

	return this->load(_entity   );
}

/**
 *	@brief	    Clear mime entity 
 *	@param[in]  None 
 *	@param[out] None 
 *	@return	    None 
 **/
void mime_entity::clear(void)
{
	this->header.clear();
	this->sdbody.clear();

	list<class mime_entity*>::const_iterator _big_ = this->sdbody.part_entity.begin(),
											 _end_ = this->sdbody.part_entity.  end();
	while (_big_ != _end_)
	{
		delete *_big_; _big_++;
	}

	this->sdbody.part_entity.clear();

	return;
}

/**
 *	@brief	    Get mime entity header 
 *	@param[in]  None 
 *	@param[out] None 
 *	@return	    mime header 
 **/
const class mime_header &mime_entity::get_header(void) const noexcept
{
	return this->header;
}

/**
 *	@brief	    Get mime entity body 
 *	@param[in]  None 
 *	@param[out] None 
 *	@return	    mime entity body 
 **/
const class body_shadow &mime_entity::get_sdbody(void) const noexcept
{
	return this->sdbody;
}

/**
 *	@brief	    Get mime entity part 
 *	@param[in]  _inx - part index 
 *	@param[out] None 
 *	@return	    mime entity part OR NULL 
 *	@note		The function only get the brother part,
 *				to use the return pointer, if deeper part should be get
 **/
const class mime_entity *mime_entity::get_part(string::size_type _inx) const noexcept
{
	list<class mime_entity*>::const_iterator _big_ = this->sdbody.part_entity.begin(),
											 _end_ = this->sdbody.part_entity.  end();

	string::size_type i = 0;
	while ((_big_ != _end_) && (*_big_ != NULL))
	{
		if (i == _inx) { return *_big_; }	

		i++; _big_++;
	}

	return NULL;
}


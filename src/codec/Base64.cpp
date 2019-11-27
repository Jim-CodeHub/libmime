/**-----------------------------------------------------------------------------------------------------------------
 * @file	Base64.cpp
 * @brief   Base64 encoding and decoding
 *
 * Copyright (c) 2019-2019 Jim Zhang 303683086@qq.com
 *------------------------------------------------------------------------------------------------------------------
*/


#include <libMIME/src/codec/Base64.hpp>


/*-----------------------------------------------------------------------------------------------------------------
 * 
 *                                          FUNCTION PROTOTYPES
 *
 *------------------------------------------------------------------------------------------------------------------
*/
static void encode_block(const unsigned char *binIn, char *base64Out);
static void decode_block(const char *base64In, unsigned char *binOut);


/*-----------------------------------------------------------------------------------------------------------------
 * 
 *                                          FUNCTIONS IMPLEMENT
 *
 *------------------------------------------------------------------------------------------------------------------
*/

/**
 *	@brief	    Encode '8-bit' binary bytes into base64 ASCII 
 *	@param[in]  binIn 
 *	@param[out] base64Out 
 *	@return		None
 *	@note		The function does no param checking for out
 *	@warning	Note the use of the escape character '\'
 **/
void base64_encode(const unsigned char *binIn, char *base64Out)
{
	unsigned char bufCom[3], i = 0, j = 0;
	char		  bufOut[4];

	while('\0' != binIn[i])
	{
		for (unsigned char k = 0; k < 3; k++, i++) /**< Set buffer in for encode block */
		{
			bufCom[k] = binIn[i];

			if ('\0' == binIn[i]) {break;}			
		}

		encode_block(bufCom, bufOut);

		for (unsigned char k = 0; k < 4; k++, j++) /**< Set buffer out for base64 str */
		{
			base64Out[j] = bufOut[k];
		}
	}

	base64Out[j] = '\0';

	return;
}

/**
 *	@brief	    Encode '8-bit' binary bytes into base64 ASCII 
 *	@param[in]  binIn 
 *	@param[out] _base64Out 
 *	@return		None
 *	@note		The function does no param checking for out
 *	@warning	Note the use of the escape character '\'
 **/
void base64_encode(const unsigned char *binIn, string &_base64Out)
{
	unsigned char bufCom[3], i = 0, j = 0;
	char		  bufOut[4];

	string::iterator base64Out = _base64Out.begin();

	while('\0' != binIn[i])
	{
		for (unsigned char k = 0; k < 3; k++, i++) /**< Set buffer in for encode block */
		{
			bufCom[k] = binIn[i];

			if ('\0' == binIn[i]) {break;}			
		}

		encode_block(bufCom, bufOut);

		for (unsigned char k = 0; k < 4; k++, j++) /**< Set buffer out for base64 str */
		{
			base64Out[j] = bufOut[k];
		}
	}

	base64Out[j] = '\0';

	return;
}

/**
 *	@brief	    Decode base64 ASCII into '8-bit' binary bytes 
 *	@param[in]	base64In
 *	@param[out] binOut
 *	@return		None
 *	@note		The function does no param checking for out
 **/
void base64_decode(const char *base64In, unsigned char *binOut)
{
	unsigned char bufOut[3], i = 0, j = 0;
	char		  bufCom[4];

	while('\0' != base64In[i])
	{
		for (unsigned char k = 0; k < 4; k++, i++) /**< Set buffer in for base64 str */
		{
			bufCom[k] = base64In[i];

			if ('\0' == base64In[i]) {break;}
		}

		decode_block(bufCom, bufOut);

		for (unsigned char k = 0; k < 3; k++, j++) /**< Set buffer out for 8-bit bin */
		{
			binOut[j] = bufOut[k];
		}
	}

	binOut[j] = '\0';

	return;
}

/**
 *	@brief	    Decode base64 ASCII into '8-bit' binary bytes 
 *	@param[in]	base64In
 *	@param[out] _binOut
 *	@return		None
 *	@note		The function does no param checking for out
 **/
void base64_decode(const char *base64In, string &_binOut)
{
	unsigned char bufOut[3], i = 0, j = 0;
	char		  bufCom[4];

	string::iterator binOut = _binOut.begin();

	while('\0' != base64In[i])
	{
		for (unsigned char k = 0; k < 4; k++, i++) /**< Set buffer in for base64 str */
		{
			bufCom[k] = base64In[i];

			if ('\0' == base64In[i]) {break;}
		}

		decode_block(bufCom, bufOut);

		for (unsigned char k = 0; k < 3; k++, j++) /**< Set buffer out for 8-bit bin */
		{
			binOut[j] = bufOut[k];
		}
	}

	binOut[j] = '\0';

	return;
}

/**
 *	@brief	    Decode 3 '8-bit' binary bytes as 4 '6-bit' data
 *	@param[in]  binIn
 *	@param[out]	base64Out
 *	@return		None
 *	@note		The function does no param checking for out
 *	@warning	Note the use of the escape character '\'
 **/
static void encode_block(const unsigned char *binIn, char *base64Out)
{
	unsigned char i = 0; while('\0' != binIn[i]) i++; /**< Calculate data size			*/

	switch (i)
	{
		case 0: break;
		case 1:
			base64Out[0] = base64_encode_table[  binIn[0] >> 2						     ];
			base64Out[1] = base64_encode_table[ (binIn[0] & 0X03) << 4				     ];
			base64Out[2] = base64_encode_table[64										 ];
			base64Out[3] = base64_encode_table[64                                        ];
			break;
		case 2:
			base64Out[0] = base64_encode_table[  binIn[0] >> 2							 ]; 
			base64Out[1] = base64_encode_table[((binIn[0] & 0x03) << 4) | (binIn[1] >> 4)];
			base64Out[2] = base64_encode_table[ (binIn[1] & 0x0F) << 2					 ];
			base64Out[3] = base64_encode_table[64										 ];
			break;
		default:
			base64Out[0] = base64_encode_table[  binIn[0] >> 2						     ]; 
			base64Out[1] = base64_encode_table[((binIn[0] & 0x03) << 4) | (binIn[1] >> 4)];
			base64Out[2] = base64_encode_table[((binIn[1] & 0x0F) << 2) | (binIn[2] >> 6)];
			base64Out[3] = base64_encode_table[  binIn[2] & 0X3F						 ];
	}

	return;
}

/**
 *	@brief	    Decode 4 '6-bit' data as 3 '8-bit' binary bytes 
 *	@param[in]	base64In
 *	@param[out] binOut
 *	@return		None
 *	@note		The function does no param checking for out
 **/
static void decode_block(const char *base64In, unsigned char *binOut)
{
	unsigned char i = 0; while('\0' != base64In[i]) i++; /**< Calculate data size                         */

	const unsigned char * _base64In = (const unsigned char *)base64In;

	switch (i) /*< Case 1,2,3 is to be compatible with the base64 variant schema of omitted '='		      */
	{
		case 0: break;
		case 1: 
			binOut[0] = (base64_decode_table[_base64In[0]] << 2											  ); 
			break;
		case 2: 
			binOut[0] = (base64_decode_table[_base64In[0]] << 2) | (base64_decode_table[_base64In[1]] >> 4); 
			binOut[1] = (base64_decode_table[_base64In[1]] << 4											  ); 
			break;
		case 3:
			binOut[0] = (base64_decode_table[_base64In[0]] << 2) | (base64_decode_table[_base64In[1]] >> 4); 
			binOut[1] = (base64_decode_table[_base64In[1]] << 4) | (base64_decode_table[_base64In[2]] >> 2); 
			binOut[2] = (base64_decode_table[_base64In[2]] << 6											  ); 
			break;
		default:
			binOut[0] = (base64_decode_table[_base64In[0]] << 2) | (base64_decode_table[_base64In[1]] >> 4); 
			binOut[1] = (base64_decode_table[_base64In[1]] << 4) | (base64_decode_table[_base64In[2]] >> 2); 
			binOut[2] = (base64_decode_table[_base64In[2]] << 6) | (base64_decode_table[_base64In[3]]     ); 
	}

	return;
}


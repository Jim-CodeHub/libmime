#include <libMIME/src/mime.hpp>

#include <iostream>

using namespace std;
using namespace NS_LIBMIME;

int main(void)
{
	string string_name   = "string_name"					 ;
	string _char__name   = "__char_name"					 ;
	char   array__name[] = "array__name"					 ;
	string seprated_name = "sep ___name"					 ;

	class field_name fn1(string_name						);
	cout <<	fn1.get() << endl								 ;

	class field_name fn2(_char__name						);
	cout <<	fn2.get() << endl								 ;

	class field_name fn3(array__name, sizeof(array__name)	);
	cout <<	fn3.get() << endl								 ;

	try
	{

	class field_name fn4(seprated_name						);
	cout <<	fn4.get() << endl								 ;

	}
	catch(const char *str) { cout << str << endl; }			 ;

	//Function set 'set' are called by field_name constructure

	return 0;
}

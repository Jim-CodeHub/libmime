#include <libMIME/src/mime.hpp>

#include <iostream>

using namespace std;
using namespace NS_LIBMIME;

int main(void)
{
	string string_str_body   = "This_is_my_string_str_body"  ;
	string char___str_body   = "This_is_my_char___str_body"  ; 
	char   array__str_body[] = "This_is_my_array__str_body"  ;
	string sep____str_body	 = "This is my sep ___str_body"  ;

	string_body sb1(string_str_body							);
	cout << sb1.get() << endl;

	string_body sb2(char___str_body							);
	cout << sb2.get() << endl								 ;

	string_body sb3(array__str_body, sizeof(array__str_body));
	cout << sb3.get() << endl								 ;

	string_body sb4(sep____str_body							);
	cout << sb4.get() << endl								 ;

	//Function set 'set' are called by string_body constructure

	return 0;
}

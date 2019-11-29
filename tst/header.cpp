#include <libMIME/src/mime.hpp>

#include <iostream>

using namespace std;
using namespace NS_LIBMIME;


int main(void)
{ 
	string_body sb("stringbody");
	
	header h("name1", &sb);

	cout << h.get();

	return 0;
}

#include <libMIME/src/mime.hpp>

#include <iostream>

using namespace std;
using namespace NS_LIBMIME;

int main(void)
{
	string string_fold_body   = "This is \r\n my \r\n             string fold  \r\n \r\n \r\n  body";
	string char___fold_body   = "This is \r\n my \r\n             char   fold  \r\n \r\n \r\n  body";
	char   array__fold_body[] = "This is \r\n my \r\n             array  fold  \r\n \r\n \r\n  body";


	cout << field_body::unfold(string_fold_body) << endl											;
	cout << field_body::unfold(char___fold_body) << endl											;
	cout << field_body::unfold(array__fold_body, sizeof(array__fold_body)) << endl					;


	//Function set 'set' are called by field_name constructure

	return 0;
}

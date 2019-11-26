#include <libMIME/src/mime.hpp>

#include <iostream>

using namespace std;
using namespace NS_LIBMIME;

int main(void)
{
	mime_header mh;

	string_body sb("fbody");

	mh.set("hname1", &sb);
	mh.set("hname2", &sb);
	mh.set("hname3", &sb);
	mh.set("hname4", &sb);
	mh.set("hname5", &sb);

	try{
	contenttype_body cb("thisismy/cbody;");
	cb.set_param("boundary="+contenttype_body::construct_boundary());
	mh.set(CONTENTTYPE_LABLE, &cb);
	}catch (const char *str)
	{
		cout <<str <<endl;
	}

	mime_body mb("this is my body", 15);

	mime_entity me(mh, mb);

	cout << me.get() << endl;

	return 0;
}

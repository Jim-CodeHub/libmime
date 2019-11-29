#include <libMIME/src/mime.hpp>

#include <iostream>

using namespace std;
using namespace NS_LIBMIME;

int main(void)
{
	mime_body mb;

	mb.set_preamble("preamble");
	mb.set("this is my string");
	mb.set_epilogue("epliogue");

	cout << mb.get() <<endl;

	return 0;
}

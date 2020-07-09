#include <libmime/mime.hpp>

#include <iostream>

using namespace std;
using namespace NS_LIBMIME;

int main(void)
{
	class contentid_body cid("myhost");	

	cout << cid.get() << endl;

	return 0;
}

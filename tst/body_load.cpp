#include <libmime/mime.hpp>

#include <iostream>

using namespace std;
using namespace NS_LIBMIME;

int main(void)
{
	try{
	class body_shadow bs;
	
	bs.load("/home/jim/Project/bika.jpg", 0, -1);

	bs.fill("./a.jpg");
	}catch(const char *str)
	{
		cout << str<<endl;
	}

	return 0;
}

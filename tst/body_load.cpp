#include <libmime/mime.hpp>

#include <iostream>

using namespace std;
using namespace NS_LIBMIME;

int main(void)
{
	class body b;

	b.load("/home/jim/Project/bika.jpg", 0, -1);

	b.fill("./a.jpg");

	return 0;
}

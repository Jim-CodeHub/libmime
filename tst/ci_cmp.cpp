#include <libmime/mime.hpp>

#include <iostream>

using namespace std;
using namespace NS_LIBMIME;

int main(void)
{
	cout << util::string_cmp_ci("ABC", "aBc");

	return 0;
}

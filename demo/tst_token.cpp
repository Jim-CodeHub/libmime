#include <libmime/mime.hpp>

#include <iostream>

using namespace std;
using namespace NS_LIBMIME;

int main(void)
{
	class string_token st("abcd\0ef\0gcdFFFF", 15, "d");

	cout << st.get_stok(0) << endl;
	cout << st.get_stok(1) << endl;
	cout << st.get_stok(2) << endl;

	return 0;
}

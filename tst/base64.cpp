#include <libmime/mime.hpp>

#include <iostream>

using namespace std;
using namespace NS_LIBMIME;

int main(void)
{
	char src[   ] = "abc\0deasdfa\0dwdcxs"; /**< NOTE : It's a binary simulation, set '\0', DIFF FROM "abc\\0deasdfa\\0dwdcxs"*/
	char des[100];

	class codec code;

	code.encode(BASE64, src, 18, des);

	cout << "-----------DES------------"<< endl;
	cout << des << endl;





	char des2[100];
	string::size_type _size;
	code.decode(BASE64, des, des2, _size);

	cout << "-----------DES2------------"<< endl;

	string::size_type i = 0;
	while (i != _size)
	{
		if ('\0' == des2[i])
			cout << "NULL";
		else
			cout <<des2[i];
		i++;
	}
	cout << endl;

	return 0;
}

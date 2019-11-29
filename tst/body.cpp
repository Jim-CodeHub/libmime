#include <libMIME/src/mime.hpp>

#include <iostream>

using namespace std;
using namespace NS_LIBMIME;

class x:public body{
	public:
		void set_s(string &ss){
			this->s = ss;
		}
	protected:
		string s;
};

int main(void)
{
#if 0
	body b;

	b.set("this is my string body");

	cout << b.get() <<endl;
#endif

	string ss = "ss";
	x xx;
	xx.set("this is xx body");
	xx.set_s(ss);

	cout << xx.get() <<endl;

	return 0;
}

#include <libMIME/src/mime.hpp>

#include <iostream>

using namespace std;
using namespace NS_LIBMIME;

int main(void)
{
#if 0

	string_body sb1("stringbody1111");
	mime_header mh1("mh1111", &sb1);
	mime_body   mb1("mb1111", 6);
	mb1.set_preamble("pre1111");
	mb1.set_epilogue("epi1111");

	string_body sb2("stringbody2222");
	mime_header mh2("mh2222", &sb2);
	mime_body   mb2("mb2222", 6);
	mb2.set_preamble("pre2222");
	mb2.set_epilogue("epi2222");

	string_body sb3("stringbody3333");
	mime_header mh3("mh3333", &sb3);
	mime_body   mb3("mb3333", 6);
	mb3.set_preamble("pre3333");
	mb3.set_epilogue("epi3333");

	string_body sb4("stringbody4444");
	mime_header mh4("mh4444", &sb4);
	mime_body   mb4("mb4444", 6);
	mb4.set_preamble("pre4444");
	mb4.set_epilogue("epi4444");

	string_body sb5("stringbody5555");
	mime_header mh5("mh5555", &sb5);
	mime_body   mb5("mb5555", 6);
	mb5.set_preamble("pre5555");
	mb5.set_epilogue("epi5555");

	string_body sb6("stringbody6666");
	mime_header mh6("mh6666", &sb6);
	mime_body   mb6("mb6666", 6);
	mb6.set_preamble("pre6666");
	mb6.set_epilogue("epi6666");

	string_body sb7("stringbody7777");
	mime_header mh7("mh7777", &sb7);
	mime_body   mb7("mb7777", 7);
	mb7.set_preamble("pre7777");
	mb7.set_epilogue("epi7777");

	string_body sb8("stringbody8888");
	mime_header mh8("mh8888", &sb8);
	mime_body   mb8("mb8888", 8);
	mb8.set_preamble("pre8888");
	mb8.set_epilogue("epi8888");

	class mime_entity me(mh1);

	me.part()->node(mh2, mb2);
	me.part()->node(mh3, mb3);
	class mime_entity *p = me.part();
	p->part(mh5)->node(mh4, mb4);
	p->part(mh5)->node(mh6, mb6);


	

	cout << me.get() << endl; 
#endif

	string_body sb1("stringbody1111");
	mime_header mh1("mh1111", &sb1);
	mime_body   mb1("mb1111", 6);
	mb1.set_preamble("pre1111");
	mb1.set_epilogue("epi1111");

	class mime_entity me(mh1, mb1);

	string entity = "thisi is entity head\r\n\r\nthisi is body";
	me.set(entity);

	return 0;
}

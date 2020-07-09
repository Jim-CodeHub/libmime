#include <libmime/mime.hpp>

#include <iostream>

using namespace std;
using namespace NS_LIBMIME;

int main(void)
{
	const class body_shadow b;

	b.load("TharstenCaseStudy_ESP_FINAL.pdf", 0, -1);

	b.fill("./1.pdf");
	

	return 0;
}

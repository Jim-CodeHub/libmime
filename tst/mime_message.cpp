#include <libmime/mime.hpp>

#include <iostream>

using namespace std;
using namespace NS_LIBMIME;

int main(void)
{

	mime_message msg;

	class mime_header message_header;
					  message_header.set(Content_Type, "multipart/related");
					  message_header.set(Content_Transfer_Encoding, "7bit");


	try{

	class mime_header part_1_header;
					  part_1_header.set(Content_Type, "application/vnd.cip4 - jmf + xml");
					  part_1_header.set(Content_Transfer_Encoding, "8bit");

	msg.set_part(message_header)->set_node(part_1_header, "PART 1 TEST BODY ... ...");

	class mime_header part_2_header;
					  part_2_header.set(Content_Type, "application/vnd.cip4 - jdf + xml");
					  part_2_header.set(Content_Transfer_Encoding, "8bit");

	msg.set_part(message_header)->set_node(part_2_header, "PART 2 TEST BODY ... ...");

	class mime_header part_3_header;
					  part_3_header.set(Content_Type, "application/pdf");
					  part_3_header.set(Content_Transfer_Encoding, "binary");

	class body_shadow sdbody;
					  sdbody.load("./TharstenCaseStudy_ESP_FINAL.pdf", 0, -1);

	msg.set_part(message_header)->set_node(part_3_header, sdbody);

	string _message = msg.make();

	cout << _message <<endl;

	}catch(const char *str) { cout << str << endl; }

	return 0;
}

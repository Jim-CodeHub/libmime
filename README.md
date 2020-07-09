# libMIME
MIME C++ library that reference RFC822, RFC2045, RFC2046, RFC2047, RFC2048 and RFC2049 as IETF definition

### Now VS Future
Currently only the parts that might be relevant to HTTP are implemented and int the future implement mail parts, such as 'Message', 'Data and time', 'Address' etc.

### Known-Bug
funciton "class field &operator=(const class &field);" will cause little heep leak, but almost negligible

### Usage
	//Preamble : HEAD and BODY set by class mime_header and class body_shadow etc.

1. 
	`class mime_message message;`
	`message.set_node(HEAD, BODY);`
	`message.make();` //Return a string message, which you has been set

	This code only set a BODY under HEAD
2.

	`class mime_message message;`
	`message.set_part(HEAD)->set_node(HEAD1, BODY1);`
	`message.set_part(HEAD)->set_node(HEAD2, BODY2);`
	...
	`message.make();` //Return a string message, which you has been set
	
	This code set N part under HEAD, and each part has it's own HEADx and BODYx 

3. 

	`class mime_message message;`
	`message.set_part(HEAD)->set_node(HEAD1, BODY1);`
	`message.set_part(HEAD)->set_node(HEAD2, BODY2);`

	class mime_entity *p;
	p = message.set_part(HEAD);
		p->set_part(HEAD3)->set_node(HAED4, BODY4);
		p->set_part(HEAD3)->set_node(HAED5, BODY6);

	`message.set_part(HEAD)->set_node(HEAD7, BODY7);`

	`message.make();` //Return a string message, which you has been set
	
	This code set N part under HEAD, and each part has it's own HEADx and BODYx 
	AND, the part with header HEAD3 is a nest one,
		it's part is the part with HEAD4 and BODY4
				 and the part with HEAD5 and BODY5

4.

	`class mime_message message;`
	`message.load(xxx);` //This function can load an string into message, so you can parse it 
						 //by libMIME at next step


5.
	NEXT:
		THE LIBRARY IS ONLY DESIGNED FOR HTTP PARSE FOR NOW, 

		FULL FUNCTON (OF MIME) WILL BE ADDED at next time

6.
	More usages and matters need attention to set the source code


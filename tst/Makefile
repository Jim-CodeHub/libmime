
OBJS    = mime_entity mime_message
SUBDIRS = 
 
 
#-------------------------------------------------------------------------------------------------------
#																									   #
#										  Make rules 									   		   	   #
#																									   #
#-------------------------------------------------------------------------------------------------------


.PHONY: all clean $(SUBDIRS)

all:
	@for i in $(OBJS);													   				\
	do															    	   				\
		g++ -Werror -std=c++11 -Wall "$$i".cpp -L$(shell dirname `pwd`) -lMIME -Wl,-rpath=$(shell dirname `pwd`) -o "$$i".out;   \
	done

.PHONY:clean
clean:
	rm -rf *.out



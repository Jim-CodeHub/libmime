
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
		g++ $(CXXFLAGS) "$$i".cpp -L$(shell dirname `pwd`) -lmime -Wl,-rpath=$(shell dirname `pwd`) -o "$$i".out;   \
	done

.PHONY:clean
clean:
	rm -rf *.out



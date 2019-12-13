
OBJS    = tst_token body_load mime_message base64 cid ci_cmp
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



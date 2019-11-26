

OBJS    = param.o  mime_header.o
SUBDIRS = field_body 
 
 
#-------------------------------------------------------------------------------------------------------
#																									   #
#										  Make rules 									   		   	   #
#																									   #
#-------------------------------------------------------------------------------------------------------


.PHONY: all clean $(SUBDIRS)

all:$(SUBDIRS) $(OBJS)

$(SUBDIRS):ECHO
	$(MAKE) -C $@

ECHO:

%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

.PHONY:clean
clean:
	rm -rf *.o



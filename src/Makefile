
OBJS    = mime_body.o mime_entity.o
SUBDIRS = codec header rfc822 util
 
 
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




OBJS    = version_body.o contenttype_body.o  contentid_body.o
SUBDIRS =
 
 
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



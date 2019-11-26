
OBJS    = field_body.o field.o field_name.o header.o body.o
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



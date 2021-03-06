#-------------------------------------------------------------------------------------------------------
#																									   #
#								Makefile for LIBMIME source file 									   #
#																									   #
#-------------------------------------------------------------------------------------------------------


PROJECT			   =    libmime
TARGET			   =    $(PROJECT)

--PREFIX		   =    ./install

CXX				   = 	g++	

CXXFLAGS		   =	-Werror -std=c++11
CXXFLAGS       	  += 	-Wall
CXXFLAGS		  +=	-I$(CURDIR)
#CXXFLAGS		  +=    -g

SUBDIRS 		   =    $(TARGET) 

export CXX CXXFLAGS

#-------------------------------------------------------------------------------------------------------
#																									   #
#											    Make rules 								   		   	   #
#																									   #
#-------------------------------------------------------------------------------------------------------


.PHONY: all clean install demo $(SUBDIRS)

all:$(SUBDIRS)
	ar -rcs $(PROJECT).a $(shell find ./$(TARGET) -name "*.o")
	$(CXX) -fPIC -shared $(CXXFLAGS) $(shell find ./$(TARGET) -name "*.cpp") -o $(PROJECT).so

$(SUBDIRS):
	$(MAKE) -C $@	

install:
	$(shell if [ ! -d $(--PREFIX) ]; then mkdir $(--PREFIX); fi;)
	$(shell if [ ! -d $(--PREFIX)/include ]; then mkdir $(--PREFIX)/include; fi;)
	$(shell if [ ! -d $(--PREFIX)/lib ]; then mkdir $(--PREFIX)/lib; fi;)
	@cp $(TARGET) $(--PREFIX)/include -rf
	@mv ./$(PROJECT).a ./$(PROJECT).so $(--PREFIX)/lib 
	rm -rf `find ./$(--PREFIX)/include -name "*.o"`
	rm -rf `find ./$(--PREFIX)/include -name "*.cpp"`
	rm -rf `find ./$(--PREFIX)/include -name "Makefile"`

demo:
	$(MAKE) -C demo 
 
tags:
	@rm -rf ./tags
	ctags --exclude="docs"			\
		  --exclude="*.o"			\
		  --exclude="*.a"			\
		  --exclude="*.so"			\
		  --exclude="*.elf"			\
		  --exclude="*.map"			\
		  --exclude="*.lss" -R .

clean:
	for dir in $(SUBDIRS); do 		\
		$(MAKE) -C $$dir clean;		\
	done
	@rm -rf $(shell find ./ -name "*.o")


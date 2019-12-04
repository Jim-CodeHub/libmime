#-------------------------------------------------------------------------------------------------------
#																									   #
#								Makefile for LIBMIME source file 									   #
#																									   #
#-------------------------------------------------------------------------------------------------------


PROJECT			   =    libMIME

CXX				   =	g++

CXXFLAGS		   =	-Werror -std=c++11
CXXFLAGS       	  += 	-Wall
#CXXFLAGS		  +=    -g

SUBDIRS 		   =    src

CPLUS_INCLUDE_PATH = $(shell dirname `pwd`)

export CXX CXXFLAGS LD_FLAGS CPLUS_INCLUDE_PATH

#-------------------------------------------------------------------------------------------------------
#																									   #
#											    Make rules 								   		   	   #
#																									   #
#-------------------------------------------------------------------------------------------------------


.PHONY: all clean install tst $(SUBDIRS)

all:$(SUBDIRS)
	ar -rcs $(PROJECT).a $(shell find ./src -name "*.o")
	$(CXX) -fPIC -shared $(shell find ./src -name "*.cpp") -o $(PROJECT).so

$(SUBDIRS):
	$(MAKE) -C $@	

install:.ONSHELL
.ONSHELL:
	@make
	@if [ ! -d libMIME ]; then mkdir libMIME; fi;
	@cp -rf src ./libMIME
	@rm -rf `find ./libMIME/src -name "*.o"`
	@rm -rf `find ./libMIME/src -name "*.cpp"`
	@rm -rf `find ./libMIME/src -name "Makefile"`
	@mv ./libMIME.a libMIME
	@mv ./libMIME.so libMIME 

tst:
	$(MAKE) -C tst
 
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


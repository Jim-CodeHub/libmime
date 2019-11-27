#-------------------------------------------------------------------------------------------------------
#																									   #
#								Makefile for LIBMIME source file 									   #
#																									   #
#-------------------------------------------------------------------------------------------------------


PROJECT			=   libMIME

CXX				=	g++

CXXFLAGS		=	-Werror -std=c++11
CXXFLAGS       += 	-Wall
#CXXFLAGS		+=  -g

SUBDIRS 		=   src

export CXX CXXFLAGS LD_FLAGS


#-------------------------------------------------------------------------------------------------------
#																									   #
#											    Make rules 								   		   	   #
#																									   #
#-------------------------------------------------------------------------------------------------------


.PHONY: all clean install tst $(SUBDIRS)

all:$(SUBDIRS)
	ar -rcs $(PROJECT).a $(shell find ./ -name "*.o")

$(SUBDIRS):
	$(MAKE) -C $@	

install:

tst:
	$(CXX) $(CXXFLAGS) tst/main.cpp libMIME.a
 
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


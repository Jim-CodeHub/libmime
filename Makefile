#-------------------------------------------------------------------------------------------------------
#																									   #
#								Makefile for LIBMIME source file 									   #
#																									   #
#-------------------------------------------------------------------------------------------------------


PROJECT			   =    libMIME
TARGET			   =    $(PROJECT)

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

install:
	@make
	$(shell if [ ! -d $(TARGET) ]; then `mkdir $(TARGET)`; fi;)
	$(shell cp -rf src/* ./$(TARGET)/ )
	@rm -rf `find ./$(TARGET) -name "*.o"`
	@rm -rf `find ./$(TARGET) -name "*.cpp"`
	@mv ./$(PROJECT).a ./$(PROJECT).so $(TARGET) 

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


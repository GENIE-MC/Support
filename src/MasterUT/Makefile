#
# GENIE-UT Makefile 
#
# Author: Julia Yarba, Fermilab 
#

SHELL = /bin/sh
NAME = all
MAKEFILE = Makefile

# Include machine specific flags and locations (inc. files & libs)
include $(GENIE)/src/make/Make.include

#INCLUDES += -I$(BOOST_INC)
ifdef CPP_INCLUDES
INCLUDES := $(CPP_INCLUDES) -I$(BOOST_INC) -I../Common -I../SynthEvent
else
INCLUDES := $(INCLUDES) -I$(BOOST_INC) -I../Common -I../SynthEvent
endif

# Add extra libraries needed for these executables
GENIE_GENERATOR_LIBS   = $(shell $(GENIE)/src/scripts/setup/genie-config --libs)
GENIE_RW_LIBS = $(shell $(GENIE_REWEIGHT)/src/scripts/setup/genie-reweight-config --libs)
BOOST_UT_LIBS = -L$(BOOST_LIB) -lboost_unit_test_framework
LIBRARIES := $(GENIE_GENERATOR_LIBS) $(GENIE_RW_LIBS) $(LIBRARIES)  

UT_SRC := $(wildcard *.cxx)
UT_OBJ  = $(addsuffix .$(ObjSuf), $(basename $(UT_SRC))) 
# --> old structure of dirs --> EXTRA_SRC = $(shell ls ../*UT/*.cxx | grep -v Master) $(wildcard ../SynthEvent/*.cxx) 
EXTRA_SRC = $(shell ls ../GenieUT/*/*/*.cxx) $(wildcard ../ReWeiUT/*.cxx) $(wildcard ../SynthEvent/*.cxx) 
EXTRA_OBJ = $(addsuffix .$(ObjSuf), $(basename $(EXTRA_SRC)))

all: master_ut 

master_ut: FORCE
	$(CXX) $(CXXFLAGS) -c $(UT_SRC) $(INCLUDES) 
	$(LD) $(LDFLAGS) $(UT_OBJ) $(EXTRA_OBJ) $(LIBRARIES) $(BOOST_UT_LIBS) -o master_ut 


purge: FORCE
	$(RM) *.o *~ core 

clean: FORCE
	$(RM) *.o *~ core 
	$(RM) master_ut


FORCE:

# DO NOT DELETE

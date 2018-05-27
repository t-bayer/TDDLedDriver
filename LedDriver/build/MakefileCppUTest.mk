CPPUTEST_HOME = /home/timo/tools/cpputest

SILENCE = @

#---- Outputs ----#
COMPONENT_NAME = LedDriver

#--- Inputs ----#
CPP_PLATFORM = Gcc
PROJECT_HOME_DIR = .

SRC_DIRS = \
	src\

TEST_SRC_DIRS = \
	.\
	tests/mocks\
	tests\
	
INCLUDE_DIRS =\
  .\
  $(CPPUTEST_HOME)/include\
  tests/mocks\
  includes\
  
MOCKS_SRC_DIRS = \
	tests/mocks\
	
CPPUTEST_WARNINGFLAGS = -Wswitch-default 
CPPUTEST_CFLAGS += -Wstrict-prototypes -pedantic
LD_LIBRARIES = -lpthread
  
include $(CPPUTEST_HOME)/build/MakefileWorker.mk
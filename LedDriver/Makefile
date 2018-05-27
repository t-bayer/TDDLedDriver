#***************INDIVIDUAL INFORMATIONS***************
TARGET = MyApplication

#***************DIRECTORY INFORMATION***************
SRCDIR = src
INCLUDES = includes
BIN = bin
DOCS = doc

#***************COMPILER INFORMATIONS***************
LIBS = -lm
CC = gcc
CFLAGS = -g -Wall -I $(INCLUDES)

#***************FILE SPECIFICATIONS***************
OBJECTS = $(patsubst %.c, %.o, $(wildcard $(SRCDIR)/*.c))
HEADERS = $(wildcard $(INCLUDES)/*.h)

#***************BUILT TARGETS***************
default: $(TARGET)
	
all: default
	
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $(BIN)/$(subst src/,,$@)

$(TARGET): bin/$(OBJECTS)
	$(CC) $(subst src/,bin/,$(OBJECTS)) -Wall $(LIBS) -o $(BIN)/$@

clean:
	$(info ************ Cleaning Build Artefacts ************)
	-rm -f $(BIN)/*.o
	-rm -f $(BIN)/$(TARGET)

#***************UNIT TEST TARGETS***************
test: 
	$(info ************ Executing Unit Tests ************)
	make -i -f build/MakefileCppUTest.mk 
	
test-clean:
	$(info ************ Cleaning Test Artefacts ************)
	-rm -r -f $(BIN)/src $(BIN)/tests 
	-rm -r lib/tests


#***************DOXYGEN TARGETS***************
docs:
	cd $(DOCS); doxygen Doxyfile

docs-clean:
	-rm -r -f $(DOCS)/output/*

#***************GENERAL TARGETS***************
dist-clean:
	$(info ************ Cleaning All Artefacts ************)
	-rm -f $(BIN)/*.o
	-rm -f $(BIN)/$(TARGET)
	-rm -r -f $(BIN)/src $(BIN)/tests 
	-rm -r lib/tests
	-rm -r -f $(DOCS)/output/* 

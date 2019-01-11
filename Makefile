# Shell
SHELL=/bin/bash
# Compiler
CC=g++
CFLAGS=-c
OFLAG=-o
# CppUnit
CPPUNIT_FLAGS=-I$CPPUNIT_HOME/include -L$CPPUNIT_HOME/lib -lcppunit
PCRE_FLAG=-lpcrecpp
# Source folders
OBJ=obj
TEST=test
SRC=src
BIN=bin
TEMP=temp
# Test file
TEST_FILE=test1.txt
# Binary 
OFILE=HeaderCount
TEST_OFILE=HeaderCountTests

all: $(OFILE)

test: $(TEST_OFILE)
	./$(BIN)/$(TEST_OFILE) < $(TEST_FILE)

$(OFILE): $(OBJ)/main.o $(OBJ)/HeaderCount.o 
	$(CC) $(OBJ)/main.o $(OBJ)/HeaderCount.o $(PCRE_FLAG) $(CPPUNIT_FLAGS) $(CPPFLAGS) $(OFLAG) $(BIN)/$(OFILE)
	
$(TEST_OFILE): $(OBJ)/HeaderCount.o $(OBJ)/HeaderCountTest.o $(OBJ)/tests.o
	$(CC) $(OBJ)/HeaderCount.o $(OBJ)/HeaderCountTest.o $(OBJ)/tests.o $(PCRE_FLAG) $(CPPUNIT_FLAGS) $(CPPFLAGS) $(OFLAG) $(BIN)/$(TEST_OFILE)
	
$(OBJ)/main.o: $(SRC)/main.cpp
	$(CC) $(CFLAGS) $(SRC)/main.cpp $(CPPFLAGS) $(OFLAG) $(OBJ)/main.o
	
$(OBJ)/HeaderCount.o: $(SRC)/HeaderCount.cpp
	$(CC) $(CFLAGS) $(SRC)/HeaderCount.cpp $(CPPFLAGS) $(OFLAG) $(OBJ)/HeaderCount.o
	
$(OBJ)/HeaderCountTest.o: $(TEST)/HeaderCountTest.cpp
	$(CC) $(CFLAGS) $(TEST)/HeaderCountTest.cpp $(CPPFLAGS) $(OFLAG) $(OBJ)/HeaderCountTest.o
	
$(OBJ)/tests.o: $(TEST)/main.cpp
	$(CC) $(CFLAGS) $(TEST)/main.cpp $(CPPFLAGS) $(OFLAG) $(OBJ)/tests.o
	
compare: $(OFILE)
	chmod +x $(BIN)/main.sh
	./$(BIN)/main.sh < $(TEST_FILE) > $(TEMP)/temp1
	./$(BIN)/$(OFILE) < $(TEST_FILE) | sort > $(TEMP)/temp2
	diff $(TEMP)/temp1 $(TEMP)/temp2

clean:
	rm -rf $(BIN)/$(OFILE) $(BIN)/$(TEST_OFILE) $(OBJ)/* $(TEMP)/*
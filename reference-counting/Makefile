##### Makefile Sample #####

# This is what we want to make
TARGET = main

# What needs to make target program
OBJ_COMMON =
OBJ = main.o String.o RCObject.o RCPtr.o

# Compiler
CC = g++

# If you want to add additional header or library
USER_INC_PATH = .
USER_LIB_PATH = .

C_FLAGS_DEFS =  
C_FLAGS_OPTS =  -g -O0
C_FLAGS_INC = -I$(USER_INC_PATH)/include
C_FLAGS = $(C_FLAGS_DEFS) $(C_FLAGS_OPTS) $(C_FLAGS_INC)

LD_FLAGS_DEFS = -L$(USER_LIB_PATH)/lib
LD_FLAGS_OPTS = -lrt -ldl -lpthread
LD_FLAGS_AR =  
LD_FLAGS = $(LD_FLAGS_DEFS) $(LD_FLAGS_OPTS) $(LD_FLAGS_AR)

.cpp.o:
	$(CC) -c $(C_FLAGS) $<

all : $(TARGET)

$(TARGET) : $(OBJ_COMMON) $(OBJ)
	$(CC) -o $(TARGET) $(OBJ_COMMON) $(OBJ) $(LD_FLAGS)

clean :
	rm -r -f *.o $(TARGET)


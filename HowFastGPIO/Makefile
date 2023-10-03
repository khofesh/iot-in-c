CC = gcc
CFLAGS = -Iinclude -Wall -g -fdiagnostics-color=always -std=c17 -fsanitize=address
BCM2835 = -l bcm2835
SRC = src
OBJ = obj
BIN = bin
LDLIBS = -fsanitize=address 

# List all the source files
SOURCES = $(wildcard $(SRC)/*.c)
# Replace the .c extension with .o to get the object files
OBJECTS = $(SOURCES:$(SRC)/%.c=$(OBJ)/%.o)

# The name of the executable
EXECUTABLE = main

all: $(BIN)/$(EXECUTABLE)

# Compile all the object files and link them to create the executable
$(BIN)/$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) $(BCM2835) ${LDLIBS} -o $@

# Compile each source file into an object file
$(OBJECTS): $(OBJ)/%.o : $(SRC)/%.c
	$(CC) $(CFLAGS) $(BCM2835) -c $< -o $@

# Clean up the object files and the executable
clean:
	rm -f $(OBJECTS) $(BIN)/$(EXECUTABLE)

# Set the compiler

CC = clang++

# Set the compiler flag

CFLAGS = -Wall -Wextra -pedantic -g

# Get the name of the all C files in the Directory

CSRC ?= $(wildcard*.c)
EXECUTABLE = $(patsubst %.c,%,$(CSRC))


# Build Rules

all: $(EXECUTABLE)

$(EXECUTABLE): %.c
	$(CC) $(CFLAGS) -o $@ $<

run_%: %
	./$<

clean:
	rm -f $(EXECUTABLE)

.PHONY: all clean

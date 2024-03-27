# Define compiler
CC=g++

CFLAGS=-Wall -g -fsanitize=address
INCLUDES=
LFLAGS=
#LIBS=-lcrypto

SRCS=$(wildcard *.cpp)

OBJS=$(SRCS:.cpp=.o)

# Define the executable file 
MAIN=crypto-utility

.PHONY: clean

all: $(MAIN)
	@echo  Simple compiler named $(MAIN) has been compiled

$(MAIN): $(OBJS) 
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

clean:
	$(RM) *.o *~ $(MAIN)
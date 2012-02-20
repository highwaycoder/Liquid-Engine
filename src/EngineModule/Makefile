CC = g++

SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

all: $(OBJS)

.cpp.o:
	$(CC) -fpic -c $*.cpp -I../../include

clean:
	rm -rf *.o


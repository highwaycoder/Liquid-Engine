CC = g++

SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

PARENTDIRECTORY = ..

all: $(OBJS)

.cpp.o:
	$(CC) -fpic -c $*.cpp -I$(PARENTDIRECTORY)

clean:
	rm -rf *.o


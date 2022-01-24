CC = g++
CFLAGS = -Wall -O -fPIC -std=c++17 -pedantic -g

.PHONY: default
default: LinkedList.x

%.o : %.cxx
	$(CC) $(CFLAGS) $< -c

generator: generator.o
	$(CC) -o $@ $^ $(LDFLAGS)

CursorList.x: CursorList.o
	$(CC) -o $@ $^ $(LDFLAGS)

LinkedList.x: LinkedList.o
	$(CC) -o $@ $^ $(LDFLAGS)

ArrayList.x: ArrayList.o
	$(CC) -o $@ $^ $(LDFLAGS)

.PHONY : clean
clean :
	-rm -f *.o *.x
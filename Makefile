CC=gcc
CFLAGS= -Wall -g

all: TestList TestStack TestQueue

TestList: TestList.o
	$(CC) $(CFLAGS) TestList.o List.o -o TestList

TestList.o: TestList.c List.o
	$(CC) $(CFLAGS) -c TestList.c

List.o: List.h List.c
	$(CC) $(CFLAGS) -c List.c

TestStack: TestStack.o
	$(CC) $(CFLAGS) TestStack.o Stack.o List.o -o TestStack

TestStack.o: TestStack.c Stack.o
	$(CC) $(CFLAGS) -c TestStack.c

Stack.o: Stack.h Stack.c List.o
	$(CC) $(CFLAGS) -c Stack.c

TestQueue: TestQueue.o
	$(CC) $(CFLAGS) TestQueue.o Queue.o List.o -o TestQueue

TestQueue.o: TestQueue.c Queue.o
	$(CC) $(CFLAGS) -c TestQueue.c

Queue.o: Queue.h Queue.c List.o
	$(CC) $(CFLAGS) -c Queue.c

.PHONY: clean

clean:
	rm core vgcore.* *.o TestList TestStack TestQueue

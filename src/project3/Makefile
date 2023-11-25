DEBUG = -g
OPTS = $(DEBUG) -Wall -ansi -pedantic -std=c++20

CC=g++ $(OPTS) -c
LN=g++

OBJS = numberFiveHuffmanCodes.o TreeNode.o

proj3: $(OBJS)
	$(LN) -o proj3 $(OBJS)

numberFiveHuffmanCodes.o: TreeNode.hpp
	$(CC) numberFiveHuffmanCodes.cpp

TreeNode.o: TreeNode.cpp TreeNode.hpp
	$(CC) TreeNode.cpp


clean:
	/bin/rm -rf *~ $(OBJS) proj1

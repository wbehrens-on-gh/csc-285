DEBUG = -g
OPTS = $(DEBUG) -Wall -ansi -pedantic -std=c++20

CXX=g++ $(OPTS) -c
LN=g++

BINS = numberOneAndTwo numberFiveHuffmanCodes 
TREE_OBJS = Tree.o TreeNode.o
TREE_OBJS2 = TreeHuf.o TreeNodeHuf.o

default: $(BINS)

#Question 1 & 2
numberOneAndTwo: numberOneAndTwo.o $(TREE_OBJS)
	$(LN) -o numberOneAndTwo numberOneAndTwo.o $(TREE_OBJS) 

numberOneAndTwo.o: numberOneAndTwo.cpp
	$(CXX) numberOneAndTwo.cpp

#Question 3

#Question 4

# Question 5
numberFiveHuffmanCodes: numberFiveHuffmanCodes.o $(TREE_OBJS2)
	$(LN) -o numberFiveHuffmanCodes numberFiveHuffmanCodes.o $(TREE_OBJS2) 

numberFiveHuffmanCodes.o: numberFiveHuffmanCodes.cpp
	$(CXX) numberFiveHuffmanCodes.cpp
TreeHuf.o: TreeHuf.cpp TreeHuf.hpp
	$(CXX) TreeHuf.cpp

TreeNodeHuf.o: TreeNodeHuf.cpp TreeNodeHuf.hpp
	$(CXX) TreeNodeHuf.cpp


# DO NOT TOUCH, COMPILES TREE CLASS
Tree.o: Tree.cpp Tree.hpp
	$(CXX) Tree.cpp

TreeNode.o: TreeNode.cpp TreeNode.hpp
	$(CXX) TreeNode.cpp

clean:
	rm -rf *~ *.o *.out $(BINS)

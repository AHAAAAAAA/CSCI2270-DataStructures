EXPENDABLES = question22.o question22 bintree.o 

all:
	@make $(EXPENDABLES)

bintree.o: bintree.cpp bintree.h
	g++ -Wall -std=c++0x -g -c bintree.cpp -o bintree.o

# this compiles your test program and your binary_search_tree classes together
question22: question22.o binary_search_tree.o bintree.o
	g++ -Wall -std=c++0x -g question22.o bintree.o binary_search_tree.o -o question22

question22.o: binary_search_tree.h binary_search_tree.o bintree.h question22.cpp
	g++ -Wall -std=c++0x -g -c question22.cpp -o question22.o

# this deletes all the output files
clean:
	rm $(EXPENDABLES)

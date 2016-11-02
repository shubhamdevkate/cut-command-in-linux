all: project

project: cut.o
	gcc cut.o -o project

cut.o: cut.c functions.h
	gcc -c cut.c

clean:
	rm -rf *o project

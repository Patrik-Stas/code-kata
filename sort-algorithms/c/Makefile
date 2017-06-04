CFLAGS=-Wall
LIBS=-lcheck

prepare-structure:
	mkdir -p ./bin
	mkdir -p ./lib

build: main.o
	gcc main.c -o main

build: prepare-structure main.o kataSort.o common.o
	gcc -o ./bin/main main.o kataSort.o common.o

main.o: main.c kataSort.h common.h
	gcc $(CFLAGS) -c main.c 

kataSort.o: kataSort.c kataSort.h
	gcc $(CFLAGS) -c kataSort.c

common.o: common.c common.h
	gcc $(CFLAGS) -c common.c

sortTests.o: sortTests.c sortTests.h
	gcc $(CFLAGS) -c sortTests.c


generate-test:
	checkmk kataSort-test.check > kataSort-test.c



test: generate-test kataSort-test 
	./bin/kataSort-test

kataSort-test.o: kataSort-test.c kataSort.h 
	gcc $(CFLAGS) -c kataSort-test.c

kataSort-test: prepare-structure kataSort-test.o sortTests.o kataSort.o common.o logUtils.o
	gcc -o ./bin/kataSort-test sortTests.o kataSort-test.o kataSort.o common.o logUtils.o $(LIBS)

logUtils.o: logUtils.c logUtils.h
	gcc $(CFLAGS) -c logUtils.c


run: build
	./bin/main

delete-object-files:
	rm *.o || true

delete-executables:
	rm kataSort kataSort-test || true

clear: delete-object-files delete-executables


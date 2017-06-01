CFLAGS=-Wall
LIBS=-lcheck

prepare-structure:
	mkdir -p ./bin

build: main.o
	gcc main.c -o main

build: prepare-structure main.o bubbleSort.o common.o
	gcc -o ./bin/main main.o bubbleSort.o common.o

main.o: main.c bubbleSort.h common.h
	gcc $(CFLAGS) -c main.c 

bubbleSort.o: bubbleSort.c bubbleSort.h
	gcc $(CFLAGS) -c bubbleSort.c

common.o: common.c common.h
	gcc $(CFLAGS) -c common.c


generate-test:
	checkmk bubbleSort-test.check > bubbleSort-test.c



test: generate-test bubbleSort-test 
	./bin/bubbleSort-test

bubbleSort-test.o: bubbleSort-test.c bubbleSort.h common.h
	gcc $(CFLAGS) -c bubbleSort-test.c

bubbleSort-test: prepare-structure bubbleSort-test.o bubbleSort.o common.o logUtils.o
	gcc -o ./bin/bubbleSort-test bubbleSort-test.o bubbleSort.o common.o logUtils.o $(LIBS)

logUtils.o: logUtils.c logUtils.h
	gcc $(CFLAGS) -c logUtils.c


run: build
	./bin/main

delete-object-files:
	rm *.o || true

delete-executables:
	rm bubbleSort bubbleSort-test || true

clear: delete-object-files delete-executables


CFLAGS=-Wall
LIBS=-lcheck

prepare-structure:
	mkdir -p ./bin
	mkdir -p ./lib

build: main.o myTestRunner.o
	gcc -v -o main main.o myTestRunner.o

main.o: main.c myTestRunner.h
	gcc $(CFLAGS) -c main.c 

myTestRunner.o: myTestRunner.c myTestRunner.h
	gcc $(CFLAGS) -c myTestRunner.c

run: build
	./main



delete-object-files:
	rm *.o || true

delete-executables:
	rm -r bin/ || true

clear: delete-object-files delete-executables


#include <stdio.h>
#include <stdlib.h>
#include "bubbleSort.h"
#include "common.h"


void printPerson(const void* p);
void printNumber(const void* n);
void printArray (const void* arrStart, int length, int elemBytes, void (printElem)(const void*));

void printArray (
    const void* arrStart, 
    int length, 
    int elemBytes, 
    void (printElem)(const void*))
{
    for (int i = 0; i < length; i++)
    {
        int positionBytes = i*elemBytes;
        printElem(arrStart + positionBytes);
    }
}

void printPerson(const void* p)
{
    printf("Person; Name:%s, Age:%d.\n", ((struct person*)p)->name, ((struct person*)p)->age);
}

void printNumber(const void* n)
{
    printf("Number: %d", (*((int*)n)));
}


int main(int argc, char* argv[]) 
{
    struct person p1 = {"foo", 12};
    printf("Person p1: \nName:%s\n%d", p1.name, p1.age);
    struct person ppl[] = {{"Josh",54}, {"Josh", 24}, {"Tibor",22}, {"Captain", 19}, {"Marshall", 30}, {"Sara", 500}};

    printf("\nPeople before sort.\n");
    printArray(ppl, sizeof(ppl)/sizeof(*ppl), sizeof(*ppl), printPerson);

    bubbleSort(ppl, sizeof(ppl)/sizeof(*ppl), sizeof(*ppl), compPerson);

    printf("\nPeople after sort.\n");
    printArray(ppl, sizeof(ppl)/sizeof(*ppl), sizeof(*ppl), printPerson);
}
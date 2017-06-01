#include "logUtils.h"
#include "common.h"

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
    printf("Number: %d\n", (*((int*)n)));
}

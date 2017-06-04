#include <stdio.h>
#include <stdlib.h>
#include "bubbleSort.h"
#include "common.h"

void personDemo() 
{
    struct person p1 = {"foo", 12};
    printf("Person p1: \nName:%s\n%d", p1.name, p1.age);
    struct person ppl[] = {{"Josh",54}, {"Josh", 24}, {"Tibor",22}, {"Captain", 19}, {"Marshall", 30}, {"Sara", 500}};

    printf("\nPeople before sort.\n");
    printArray(ppl, sizeof(ppl)/sizeof(*ppl), sizeof(*ppl), printPerson);

    bubbleSort(ppl, sizeof(ppl)/sizeof(*ppl), sizeof(*ppl), personComparator);

    printf("\nPeople after sort.\n");
    printArray(ppl, sizeof(ppl)/sizeof(*ppl), sizeof(*ppl), printPerson);
}

void qsortDemo()
{
    int nums[] = {1,6,3,77,4,66,413,3,10};

    printf("\nNums before sort.\n");
    printArray(nums, sizeof(nums)/sizeof(*nums), sizeof(*nums), printNumber);

    quickSort(nums, sizeof(nums)/sizeof(*nums));

    printf("\nNums after sort.\n");
    printArray(nums, sizeof(nums)/sizeof(*nums), sizeof(*nums), printNumber);
}


int main(int argc, char* argv[]) 
{
    qsortDemo();
}
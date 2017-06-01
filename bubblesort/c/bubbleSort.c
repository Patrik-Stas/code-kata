
#include <string.h>
#include "common.h"

void bubbleSort (
    void* arrStart, 
    int length, 
    int elemBytes, 
    int (comparator)(const void* elem1, const void* elem2))
{
    // printf("Starting bubble sort array with length %d, elem size in bytes: %d.....", length, elemBytes);
    void* swap = malloc(elemBytes);
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length - i - 1; j++) 
        {
            char* e1 = (char*)arrStart + j*elemBytes;
            char* e2 = e1 + elemBytes;
            if (1 == comparator(e1, e2)) // e1 > e2? e1 is heavy, bubble down
            {
                memcpy(swap, e1,   elemBytes);
                memcpy(e1,   e2,   elemBytes);
                memcpy(e2,   swap, elemBytes);
            }
        }
    }
}

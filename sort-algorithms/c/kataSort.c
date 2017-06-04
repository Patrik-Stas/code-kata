
#include <string.h>
#include "common.h"
#include <stdlib.h>
#include "logUtils.h"




void swapInt(int* val1, int* val2)
{
    int tmp = *val1;
    *val1 = *val2;
    *val2 = tmp;
}

void swapMemory(char* p1, char* p2, int bytes, char* swap)
{
    memcpy(swap, p1,   bytes);
    memcpy(p1,   p2,   bytes);
    memcpy(p2,   swap, bytes);
}


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
    free(swap);
}



int qsortPartitionInt(int* arr, int len) {
    int pivotIndex = len-1;
    int pivotVaue = arr[pivotIndex];
    int swapIndex = -1;
    // printf("qsort len::%d. Pivot index=%d, pivot value=%d\n", len, pivotIndex, pivotVaue);
    for (int i=0; i < len; i++) 
    {
        if (arr[i] <= pivotVaue)
        {
            swapIndex++;
            if (i != swapIndex) {
                // printf("swapping [%d]=%d with [%d]=%d\n", swapIndex, *(arr+swapIndex),  i, *(arr+i));
                swapInt(arr+swapIndex, arr+i);
            }
        }
        // printArray(arr, len, sizeof(int), printNumber);
    }
    return swapIndex;
}

int qsortPartition(
    void* arr,
    int len,
    int elemBytes,
    int (comparator)(const void* e1, const void* e2))
{
    int pivotIndex = len-1;
    void* pivotVaue = arr+(pivotIndex*elemBytes);
    int swapIndex = -1;

    void* tmpSwap = malloc(elemBytes);

    for (int i=0; i < len; i++) 
    {
        if ( comparator((void*)((char*)arr+(i*elemBytes)), pivotVaue) <= 0 ) // ith element is smaller or equal pivot
        {
            swapIndex++;
            if (i != swapIndex) {
                char* e1 = ((char*) arr)+(swapIndex*elemBytes);
                char* e2 = ((char*) arr)+(i*elemBytes);
                swapMemory(e1, e2, elemBytes, tmpSwap);
            }
        }
    }
    // free(tmpSwap);
    return swapIndex;
}

void quickSortInt(int* arr, int len)
{
    if (len > 1)
    {
        int pivotIndex = qsortPartitionInt(arr, len);
        quickSortInt(arr, pivotIndex);
        quickSortInt(arr+pivotIndex, len-pivotIndex);
    }
    return;
}

void quickSort (
    void* arr, 
    int len, 
    int elemBytes, 
    int (comparator)(const void* e1, const void* e2))
{
    if (len > 1)
    {
        int pivotIndex = qsortPartition(arr, len, elemBytes, comparator);
        quickSort(arr, pivotIndex, elemBytes, comparator);
        quickSort(arr+pivotIndex*elemBytes, len-pivotIndex, elemBytes, comparator);
    }
    return;
}






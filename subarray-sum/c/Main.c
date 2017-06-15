#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "myTestRunner.h"

#define VERIFY_EXPRESSION(EXPRESSION, out_char_pt, out_text) ({if (EXPRESSION) {} else { *out_char_pt=out_text; return 1;}})
#define ARR_SIZE(arr) (sizeof(arr)/sizeof(arr[0]))

int compareInt(const void* n1, const void* n2)
{
    if (*((int*)n1) > *((int*)n2)) {
        return 1;
    }
    else if (*((int*)n1) < *((int*)n2)) {
        return -1;
    }
    else return 0;
}

struct SumPair {
    int n1;
    int n2;
};

int findMaxSubArray_naive(int* arr, int len, int* out_ilow, int* out_ihigh)
{
    int maxSum = -999999;
    int max_ilow=0;
    int max_ihigh=0;

    for (int high=0; high<len; high++)
    {
        int sum = 0;
        for (int low=high; low>=0; low--)
        {
            sum+=arr[low];
            if (sum>maxSum)
            {
                maxSum = sum;
                max_ilow  = low;
                max_ihigh = high;
            }
        }
    }
    *out_ilow = max_ilow;
    *out_ihigh = max_ihigh;
    return maxSum;
}

int max(int n1, int n2)
{
    return (n1>n2) ? n1 : n2;
}

int findMaxSubArray_divideAndConquer(int* arr, int len)
{
    if (len==1)
    {
        return *arr;
    }
    int center = len / 2;
    int subLeftMax  = findMaxSubArray_divideAndConquer(arr, center);
    int subRightMax = findMaxSubArray_divideAndConquer(arr+center, len-center);

    int leftIndex  = -1;
    int leftSumMax =  0;
    int tmpSum = 0;
    for (int i=center-1; i>=0; i--)
    {
        tmpSum+=arr[i];
        if (tmpSum>leftSumMax) 
        {
            leftSumMax = tmpSum;
            leftIndex = i;
        }
    }
    int rightIndex  = -1;
    int rightSumMax =  0;
    tmpSum = 0;
    for (int i=center; i<len; i++)
    {
        tmpSum+=arr[i];
        if (tmpSum>rightSumMax) 
        {
            rightSumMax = tmpSum;
            rightIndex = i;
        }
    }
    return max(max(subLeftMax, subRightMax), leftSumMax+rightSumMax);
}

int test_it_should_find_max_sub_array_rec(char** outputPtr)
{
    //prepare
    int arr[] = {2, -4, 1, 9, -6, 7 , -3}; // 11 = {1, 9, -6, 7}
    int low_index=0;
    int high_index=0;

    //exercise
    int topSum = findMaxSubArray_naive(arr, ARR_SIZE(arr), &low_index, &high_index);

    //verify
    printf("Found min=%d, max=%d, topSum=%d\n", low_index, high_index, topSum);
    VERIFY_EXPRESSION(11 == topSum , outputPtr, "Expected to find sum == 11.");
    VERIFY_EXPRESSION(2 == low_index, outputPtr, "Expected to find low_index == 2.");
    VERIFY_EXPRESSION(5 == high_index , outputPtr, "Expected to find high_index == 5.");

    return 0;
}

int test_it_should_find_max_sub_subarray(char** outputPtr)
{
    //prepare
    int arr[] = {2, -4, 1, 9, -6, 7 , -3}; // 11 = {1, 9, -6, 7}

    //exercise
    int topSum = findMaxSubArray_divideAndConquer(arr, ARR_SIZE(arr));

    //verify
    VERIFY_EXPRESSION(11 == topSum , outputPtr, "Expected to find sum == 11.");

    return 0;
}

int test_it_should_find_max_sub_subarray_small(char** outputPtr)
{
    //prepare
    int arr[] = {3, -4}; 

    //exercise
    int topSum = findMaxSubArray_divideAndConquer(arr, ARR_SIZE(arr));

    //verify
    VERIFY_EXPRESSION(3 == topSum , outputPtr, "Expected to find sum == 11.");

    return 0;
}


int main(int argc, char* argv[]) 
{
    const int len = 2;
    struct TestCase suite[len] = {
        {test_it_should_find_max_sub_subarray, "test_it_should_find_max_sub_subarray"},
        {test_it_should_find_max_sub_array_rec, "test_it_should_find_max_sub_array_rec"},
        {test_it_should_find_max_sub_subarray_small, "test_it_should_find_max_sub_subarray_small"}
    };

    testRunner(suite, len, printTestResult);
    return 0;
}



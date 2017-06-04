#include "logUtils.h"
#include "common.h"
#include <time.h>
#include <stdlib.h>
#include <check.h>

void arrayRandomFiller(int* array, int len);

void arrayRandomFiller(int* array, int len)
{
    for (int i = 0; i < len; i++) 
    {
        array[i] = rand() % 5000;
    }
}

void sortPersonStructureTest(void (sortingAlg)(void* arr, int len, int elemBytes, int (comparator)(const void* e1, const void* e2)));

void sortPersonStructureTest(void (sortingAlg)(void* arr, int len, int elemBytes, int (comparator)(const void* e1, const void* e2)))
{
    struct person ppl[] = {{"Josh",54}, {"JoshJunior", 24}, {"Tibor",22}, {"Captain", 19}, {"Marshall", 30}, {"Sara", 500}};
    sortingAlg(ppl, sizeof(ppl)/sizeof(*ppl), sizeof(*ppl), personComparator);
    ck_assert_str_eq(ppl[0].name, "Captain");
    ck_assert_str_eq(ppl[1].name, "Tibor");
    ck_assert_str_eq(ppl[2].name, "JoshJunior");
    ck_assert_str_eq(ppl[3].name, "Marshall");
    ck_assert_str_eq(ppl[4].name, "Josh");
}

void sortFewNumbersTest(void (sortingAlg)(void* arr, int len, int elemBytes, int (comparator)(const void* e1, const void* e2)))
{
    int nums[] = {5,3,7,1,8,2,4};
    int bytes = sizeof(*nums);
    // printArray(nums, sizeof(nums)/bytes, sizeof(int), printNumber);
    sortingAlg(nums, sizeof(nums)/bytes, bytes, intComparator);
    // printf("after\n");
    // printArray(nums, sizeof(nums)/bytes, sizeof(int), printNumber);
    ck_assert_int_eq(nums[0], 1);
    ck_assert_int_eq(nums[1], 2);
    ck_assert_int_eq(nums[2], 3);
    ck_assert_int_eq(nums[3], 4);
    ck_assert_int_eq(nums[4], 5);
    ck_assert_int_eq(nums[5], 7);
    ck_assert_int_eq(nums[6], 8);
}

void sortRandomBigArrayTest(void (sortingAlg)(void* arr, int len, int elemBytes, int (comparator)(const void* e1, const void* e2)))
{
    srand(time(NULL));
    int len = 10;
    int* nums = malloc(sizeof(int) * len);
    arrayRandomFiller(nums, len);
    sortingAlg(nums, len, sizeof(int), intComparator);
    // printArray(nums, len, sizeof(int), printNumber);
    int lastNo = -1;
    for (int i = 0; i < len; i++) 
    {
        if (lastNo > nums[i])
        {
            ck_abort_msg("Not properly sorted. LastNo=%d, but %d-th value was %d!", lastNo, i, nums[i]);
        }
        lastNo = nums[i];
    }
}
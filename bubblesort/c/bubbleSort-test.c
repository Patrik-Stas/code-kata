/*
 * DO NOT EDIT THIS FILE. Generated by checkmk.
 * Edit the original source file "bubbleSort-test.check" instead.
 */

#include <check.h>

#line 1 "bubbleSort-test.check"
#include "bubbleSort.h"
#include "logUtils.h"
#include "common.h"
#include <time.h>
#include <stdlib.h>

void fillRandomNumbers(int* array, int len);

void fillRandomNumbers(int* array, int len)
{
    for (int i = 0; i < len; i++) 
    {
        array[i] = rand() % 5000;
    }
}


START_TEST(itShouldSortPersonStructures)
{
#line 19
    struct person ppl[] = {{"Josh",54}, {"JoshJunior", 24}, {"Tibor",22}, {"Captain", 19}, {"Marshall", 30}, {"Sara", 500}};
    bubbleSort(ppl, sizeof(ppl)/sizeof(*ppl), sizeof(*ppl), personComparator);
    ck_assert_str_eq(ppl[0].name, "Captain");
    ck_assert_str_eq(ppl[1].name, "Tibor");
    ck_assert_str_eq(ppl[2].name, "JoshJunior");
    ck_assert_str_eq(ppl[3].name, "Marshall");
    ck_assert_str_eq(ppl[4].name, "Josh");

}
END_TEST

START_TEST(itShouldSortNumbers)
{
#line 28
    int nums[] = {5,3,7,1,8,2};
    int bytes = sizeof(*nums);
    bubbleSort(nums, sizeof(nums)/bytes, bytes, intComparator);
    ck_assert_int_eq(nums[0], 1);
    ck_assert_int_eq(nums[1], 2);
    ck_assert_int_eq(nums[2], 3);
    ck_assert_int_eq(nums[3], 5);
    ck_assert_int_eq(nums[4], 7);
    ck_assert_int_eq(nums[5], 8);

}
END_TEST

START_TEST(itShouldSortRandomArrayCorrectly)
{
#line 39
    srand(time(NULL));
    int len = 10;
    int* nums = malloc(sizeof(int) * len);
    fillRandomNumbers(nums, len);
    bubbleSort(nums, len, sizeof(int), intComparator);
    printArray(nums, len, sizeof(int), printNumber);
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
END_TEST

int main(void)
{
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, itShouldSortPersonStructures);
    tcase_add_test(tc1_1, itShouldSortNumbers);
    tcase_add_test(tc1_1, itShouldSortRandomArrayCorrectly);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}

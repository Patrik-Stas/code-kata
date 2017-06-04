/*
 * DO NOT EDIT THIS FILE. Generated by checkmk.
 * Edit the original source file "kataSort-test.check" instead.
 */

#include <check.h>

#line 1 "kataSort-test.check"
#include "kataSort.h"
#include "sortTests.h"

START_TEST(bubbleSort_itShouldSortPersonStructures)
{
#line 5
    sortPersonStructureTest(bubbleSort);

}
END_TEST

START_TEST(bubbleSort_itShouldSortNumbers)
{
#line 8
    sortFewNumbersTest(bubbleSort);

}
END_TEST

START_TEST(bubbleSort_itShouldSortRandomArrayCorrectly)
{
#line 11
    sortRandomBigArrayTest(bubbleSort);


}
END_TEST

START_TEST(quickSort_itShouldSortPersonStructures)
{
#line 15
    sortPersonStructureTest(quickSort);

}
END_TEST

START_TEST(quickSort_itShouldSortNumbers)
{
#line 18
    sortFewNumbersTest(quickSort);

}
END_TEST

START_TEST(quickSort_itShouldSortRandomArrayCorrectly)
{
#line 21
    sortRandomBigArrayTest(quickSort);
}
END_TEST

int main(void)
{
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, bubbleSort_itShouldSortPersonStructures);
    tcase_add_test(tc1_1, bubbleSort_itShouldSortNumbers);
    tcase_add_test(tc1_1, bubbleSort_itShouldSortRandomArrayCorrectly);
    tcase_add_test(tc1_1, quickSort_itShouldSortPersonStructures);
    tcase_add_test(tc1_1, quickSort_itShouldSortNumbers);
    tcase_add_test(tc1_1, quickSort_itShouldSortRandomArrayCorrectly);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}

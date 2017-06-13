#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "myTestRunner.h"
#include <math.h>

#define VERIFY_EXPRESSION(EXPRESSION, out_char_pt, out_text) ({if (EXPRESSION) {} else { *out_char_pt=out_text; return 1;}})
#define ARR_SIZE(arr) (sizeof(arr)/sizeof(arr[0]))

int findMajorityBucket(int* arr, int len)
{
	int max=-1;
	int majority = -1;
	for (int i=0; i<len; i++) 
	{
		max = (max < arr[i]) ? arr[i] + 1 : max;
	}
	int* h = calloc(max, sizeof(int));
	for (int i=0; i<len; i++)
	{
		h[arr[i]]+=1;
	}
	for (int i=0; i<max; i++) 
	{
		if (h[i] >= (len / 2))
		{
			majority = i;
			break;
		}
	}
	return majority;
}

int findMajorityAlg(int* arr, int len)
{
	int ctr = 0;
	int majority = -1;
	for (int i=0; i<len; i++)
	{
		if (0 == ctr)
		{
			majority = arr[i];
			ctr++;
		}
		else 
		{ 
			if (arr[i] == majority)
			{
				ctr++;
			}
			else 
			{
				ctr--;
			}
		}
	}
	return (ctr > 0) ? majority : -1;
}

int test_it_should_find_majority(char** outputPtr)
{
	// prepare
	int arr[] = {2,8,7,2,2,2,5,2,3,1,2,2,3};

	// exercise
	int majority = findMajorityAlg(arr, ARR_SIZE(arr));

	// verify
	VERIFY_EXPRESSION(2 == majority, outputPtr, "Expected to find majorit == 2.");

	return 0;
}

int test_it_should_not_find_majority(char** outputPtr)
{
	// prepare
	int arr[] = {1,2,3,4,4,4,5,8};

	// exercise
	int majority = findMajorityAlg(arr, ARR_SIZE(arr));

	// verify
	VERIFY_EXPRESSION(-1 == majority, outputPtr, "Expected not to find majority.");

	return 0;
}

int main(int argc, char* argv[]) 
{
	const int len = 2;
	struct TestCase suite[len] = {
		{test_it_should_find_majority, "test_it_should_find_majority"},
		{test_it_should_not_find_majority, "test_it_should_not_find_majority"}
	};
	testRunner(suite, len, printTestResult);
	return 0;
}



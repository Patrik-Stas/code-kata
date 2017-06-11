#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "myTestRunner.h"
#include <math.h>

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

int findDuplicate_mark(int* arr, int len)
{
	int duplicate = -1;
	for (int i=0; i<len; i++)
	{
		int no = (arr[i] < 0) ? -arr[i]-1 : arr[i]-1;
		printf("Checking at %d\n", no );
		arr[no] *= -1;
	}
	for (int i=0; i<len; i++)
	{
		printf("%d, ", arr[i]);
	}
	for (int i=0; i<len-1; i++)
	{
		if (arr[i]>0)
		{
			duplicate=i+1;
		}
		else 
		{
			arr[i] = (arr[i]<0) ? -arr[i] : arr[i];
		}
	}
	return duplicate;
}

int findDuplicate_hash(int* arr, int len)
{
	int* t = calloc(len, sizeof(int));
	int duplicate = -1;
	for (int i=0; i<len; i++)
	{
		t[arr[i]]+=1;
		if (t[arr[i]]>1)
		{
			duplicate = arr[i];
			break;
		}
	}
	free(t);
	return duplicate;
}

int findDuplicate_sum(int* arr, int len)
{
	int sumExpected = (len+1)*(len/2.0); // assuming all elements are unique (but in reality there is a duplicate)
	int sumFound = 0;
	for (int i=0; i<len; i++)
	{
		sumFound+=arr[i];
	}
	int delta = sumExpected - sumFound;
	return (delta==0) ? -1 : len-delta;
}


int test_it_should_find_duplicate(char** outputPtr)
{
	// prepare
	int arr[] = {3,2,1,9,5,4,6,3,8,7}; 

	// exercise
	int duplicate = findDuplicate_sum(arr, ARR_SIZE(arr));

	//verify
	VERIFY_EXPRESSION(3 == duplicate, outputPtr, "Expected to find duplicate == 3.");

	return 0;
}

int test_it_should_not_find_duplicate(char** outputPtr)
{
	// prepare
	int arr[] = {3,2,1,9,5,4,6,8,7}; 

	// exercise
	int duplicate = findDuplicate_sum(arr, ARR_SIZE(arr));

	//verify
	VERIFY_EXPRESSION(-1 == duplicate, outputPtr, "Expected not to find duplicate, but was found.");

	return 0;

}

int main(int argc, char* argv[]) 
{
	const int len = 2;
	struct TestCase suite[len] = {
		{test_it_should_find_duplicate, "test_it_should_find_duplicate"},
		{test_it_should_not_find_duplicate, "test_it_should_not_find_duplicate"}
	};
	testRunner(suite, len, printTestResult);
	return 0;
}



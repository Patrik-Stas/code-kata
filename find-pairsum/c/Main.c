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



int findPair(int* arr, int len, int targetSum, struct SumPair* out)
{
	qsort(arr, len, sizeof(*arr), compareInt);
	int pl=0;
	int pr=len-1;
	int pairCounter = 0;
	while (pl < pr) 
	{
		int pairSum = arr[pl] + arr[pr];
		if (pairSum == targetSum) 
		{
			out[pairCounter].n1 = arr[pl];
			out[pairCounter].n2 = arr[pr];
			pairCounter++;
			pl++;
			pr--;
		}
		else if (pairSum<targetSum) 
		{
			pl++;
		}
		else 
		{
			pr--;
		}
	} 
	return pairCounter;
}

int findPair_dict(int* arr, int len, int targetSum, struct SumPair* out)
{
	int max = targetSum;
	for (int i=0; i<len; i++) 
	{
		max = (max<arr[i]) ? arr[i] : max;
	}
	int pairCount = 0;
	int* buckets = malloc(sizeof(int)*max+1);
	for (int i=0; i<len; i++) {
		buckets[i]=0;
	}
	for (int i=0; i<len; i++) {
		int no = arr[i];
		int needNo = targetSum - no;
		if (needNo>0 && buckets[needNo] == 1) {
			printf("for %d found needded bucket value %d\n", no, needNo);
			out[pairCount].n1 = (no < needNo) ? no : needNo;
			out[pairCount].n2 = (no < needNo) ? needNo : no;
			pairCount++;
		}
		buckets[no] = 1;
	}
	return pairCount;
}



int test_it_should_find_pair_producing_sum(char** outputPtr)
{
	// prepare
	int searchSum = 10;
	int arr[] = {8, 7, 2, 5, 3, 1}; 
	struct SumPair* pairs = malloc(sizeof(struct SumPair)*10);

	// exercise
	int foundPairsCount = findPair_dict(arr, ARR_SIZE(arr), searchSum, pairs);

	//verify
	VERIFY_EXPRESSION(2 == foundPairsCount, outputPtr, "Expected 2 pairs to be found.");
	VERIFY_EXPRESSION(pairs[0].n1 == 2, outputPtr, "Expected 2.");
	VERIFY_EXPRESSION(pairs[0].n2 == 8, outputPtr, "Expected 8.");
	VERIFY_EXPRESSION(pairs[1].n1 == 3, outputPtr, "Epxected 3.");
	VERIFY_EXPRESSION(pairs[1].n2 == 7, outputPtr, "Expected 7.");

	// clean
	free(pairs);
	return 0;
}

int test_it_should_find_nothing(char** outputPtr)
{
	//prepare
	int searchSum = 5;
	int arr[] =  {0, 2, 4, 6, 8, 10, 12};
	struct SumPair* pairs = malloc(sizeof(struct SumPair)*10);

	//exercise
	int foundPairsCount = findPair_dict(arr, ARR_SIZE(arr), searchSum, pairs);
	for(int i=0; i<foundPairsCount; i++) {
		printf("Found pair: %d,%d\n", pairs[i].n1, pairs[i].n2 );
	}
	//verify
	VERIFY_EXPRESSION(0 == foundPairsCount , outputPtr, "Expected zero pairs, but a pair was found.");

	//clean
	free(pairs);
	return 0;
}


int main(int argc, char* argv[]) 
{
	const int len = 2;
	struct TestCase suite[len] = {
		{test_it_should_find_pair_producing_sum, "test_it_should_find_pair_producing_sum"}, 
		{test_it_should_find_nothing, "test_it_should_find_nothing"}
	};
	testRunner(suite, len, printTestResult);
	return 0;
}



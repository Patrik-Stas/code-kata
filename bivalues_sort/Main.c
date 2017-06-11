#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "myTestRunner.h"

#define VERIFY_EXPRESSION(EXPRESSION, out_char_pt, out_text) ({if (EXPRESSION) {} else { *out_char_pt=out_text; return 1;}})

void sortbin_1(int* arr, int len);


/* Sorts array of binary values 1/0 in N time .... {0,1,0,1,1,0,1} --> {0,0,0,1,1,1,1}
 */
void sortbin_1(int* arr, int len)
{
	int pl=0;
	int pr=len-1;
	while (pl < pr) 
	{
		if (arr[pl]==0){
			pl++;
		}
		else while (pl < pr)
		{
			if (arr[pr]==0){
				arr[pl]=0;
				arr[pr]=1;
				pr--;
				break;
			}
			else 
			{
				pr--;
			}
		}
	}
}

int test_one_element(char** outputPtr)
{
	int arr[] = {0};
	int len = sizeof(arr)/sizeof(int);
	sortbin_1(arr, len);
	VERIFY_EXPRESSION(0 == arr[0], outputPtr, "Didn't expect value to change.");
	return 0;
}

int test_two_elements_sorted(char** outputPtr)
{
	int arr[] = {0,1};
	int len = sizeof(arr)/sizeof(int);
	sortbin_1(arr, len);
	VERIFY_EXPRESSION(0 == arr[0], outputPtr, "Didn't expect value to change.");
	VERIFY_EXPRESSION(1 == arr[1], outputPtr, "Didn't expect value to change.");
	return 0;
}


int test_big(char** outputPtr)
{
	int arr[] = {0,1,0,0,1,1,0,1,0,1,1,1};
	int len = sizeof(arr)/sizeof(int);
	sortbin_1(arr, len);
	VERIFY_EXPRESSION(0 == arr[0], outputPtr, "Failed 0");
	VERIFY_EXPRESSION(0 == arr[1], outputPtr, "Failed 1");
	VERIFY_EXPRESSION(0 == arr[2], outputPtr, "Failed 2");
	VERIFY_EXPRESSION(0 == arr[3], outputPtr, "Failed 3");
	VERIFY_EXPRESSION(0 == arr[4], outputPtr, "Failed 4");
	VERIFY_EXPRESSION(1 == arr[5], outputPtr, "Failed 5");
	VERIFY_EXPRESSION(1 == arr[6], outputPtr, "Failed 6");
	VERIFY_EXPRESSION(1 == arr[7], outputPtr, "Failed 7");
	VERIFY_EXPRESSION(1 == arr[8], outputPtr, "Failed 8");
	VERIFY_EXPRESSION(1 == arr[9], outputPtr, "Failed 9");
	VERIFY_EXPRESSION(1 == arr[10], outputPtr, "Failed 10");
	VERIFY_EXPRESSION(1 == arr[11], outputPtr, "Failed 11");
	return 0;
}

int main(int argc, char* argv[]) 
{
	const int len = 3;
	struct TestCase suite[len] = {
		{test_one_element, "test_one_element"}, 
		{test_two_elements_sorted, "test_two_elements_sorted"},
		{test_big, "test_big"}
	};
	testRunner(suite, len, printTestResult);
	return 0;
}



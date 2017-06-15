#include "myTestRunner.h"
#include <stdio.h>

void printTestResult(const char* testName, const int exitCode, const char* exitMessage) {
	if  (0 == exitCode) {
		printf("%s Passed: %s \n", ANSI_COLOR_GREEN, testName);
	}
	else 
	{
		printf("%s Failed: %s. Failure message:%s. %s\n",ANSI_COLOR_RED, testName, exitMessage, ANSI_COLOR_RESET);
	}
	return;
}

int testRunner(struct TestCase* testCases, int len, void (*resultPrinter)(const char*, const int, const char*)) 
{
	char* textPtr ="";
	char** exitMessagePtr = &textPtr;
	printf("\n\n---- RUNNING TESTS ----\n");
	for (int i = 0; i < len; i++) 
	{
		int exitCode = testCases[i].runTest(exitMessagePtr);
		printTestResult(testCases[i].testName, exitCode, *exitMessagePtr);
	}
	printf(ANSI_COLOR_RESET);
	return 0;
}
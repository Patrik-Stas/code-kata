struct TestCase{
	int (*runTest)(char** out);
	const char* testName;
};

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

// example: 
//test(char** outputPtr) { VERIFY_EXPRESSION(0 == 1, outputPtr, "Error: Expected 0, got 1"); }


void printTestResult(const char* testName, const int exitCode, const char* exitMessage);
int testRunner(struct TestCase* testCases, int len, void (*resultPrinter)(const char* testName, const int exitCode, const char* exitMessage));

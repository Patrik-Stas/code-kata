void bubbleSort(void* arr, int len, int elemBytes, int (comparator)(const void* e1, const void* e2));
void quickSort (void* arr, int len, int elemBytes, int (comparator)(const void* e1, const void* e2));
void quickSortInt(int* arr, int len);

void swapInt(int* val1, int* val2);
void swapMemory(char* p1, char* p2, int bytes, char* swap);


int qsortPartitionInt(int* arr, int len);
int qsortPartition(void* arr, int len, int elemBytes, int (comparator)(const void* e1, const void* e2));

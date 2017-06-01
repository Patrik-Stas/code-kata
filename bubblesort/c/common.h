#ifndef COMMON_DEF
#define COMMON_DEF

struct person {
    char* name;
    int age;
};

int personComparator (const void * p1, const void * p2);
int intComparator (const void * elem1, const void * elem2); 
#endif

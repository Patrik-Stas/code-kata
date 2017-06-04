#include "common.h"

int personComparator (const void * p1, const void * p2)
{
    if ( ((struct person*)p1)->age > ((struct person*)p2)->age ) 
    {
        return 1;
    } else if ( ((struct person*)p1)->age < ((struct person*)p2)->age ) 
    {
        return -1;
    }
    else 
    {
        return 0;
    }
}

int intComparator (const void * elem1, const void * elem2) 
{
    int f = *((int*)elem1);
    int s = *((int*)elem2);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}

/**
 * Author: Ibrahim Ismail
 //TODO (Description): function in c  which reads four arguments and returns the greatest of them.
 */

/* Header Files */

#include <stdio.h>  // Standard I/O functions
#include <stdlib.h> // Standard library functions

/* Function Declarations */
int max_of_four(int a, int b, int c, int d);

/* Main Function */

int main()
{
    int a, b, c, d;
    printf("Enter four numbers : \n");
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("Max Number =%d", ans);
    return 0;
}

/* Function Definitions */

int max_of_four(int a, int b, int c, int d)
{
    if (a > b && a > c && a > d)
    {
        return a;
    }
    if (b > a && b > c && b > d)
    {
        return b;
    }
    if (c > a && c > b && c > d)
    {
        return c;
    }
    else
    {
        return d;
    }
}

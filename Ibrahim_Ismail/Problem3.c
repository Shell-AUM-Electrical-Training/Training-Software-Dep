/**
 * Author: Ibrahim Ismail
 //TODO (Description): Array in c    Take the elements of array from user then print sum of array
 */

/* Header Files */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/* Main Function*/
int main()
{
    /*variable declaration*/

    int num, *arr, sum = 0, i;

    /*Main code*/
    printf("Enter size of  Array : ");

    scanf("%d", &num);

    arr = (int *)malloc(num * sizeof(int));

    printf("\nEnter the elements of array :");

    for (i = 0; i < num; ++i)
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    printf("Sum=%d", sum);
    free(arr);
    return 0;
}
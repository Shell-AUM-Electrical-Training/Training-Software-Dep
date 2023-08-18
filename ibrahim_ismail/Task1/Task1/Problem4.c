/**
 * Author: Ibrahim Ismail
 //TODO (Description): Array in c  Reverse the array
 */

/* Header Files */

#include <stdio.h>   // Standard I/O functions
#include <windows.h> // for implmenting delay
#include <stdlib.h>  // Standard library functions

/* Main Function*/
int main()
{
  /*variable declaration*/

  int num, *array, j, i;

  /*Main code*/

  printf("Enter size of  Array : ");

  scanf("%d", &num);

  array = (int *)malloc(num * sizeof(int)); // read size of array

  printf("\nEnter the elements of array :");

  for (i = 0; i < num; i++)
  {
    scanf("%d", &array[i]);
  }

  printf("Reversing array.....\n");
  Sleep(1000); // delay

  for (j = num - 1; j >= 0; j--)
  {
    /* code */
    printf("%d", array[j]);
  }
  return 0;
}
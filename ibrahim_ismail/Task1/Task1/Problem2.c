/**
 * Author: Ibrahim Ismail
 //TODO (Description): Conditional Statements in C  print the lowercase English word corresponding to the number if 1<n<9
 //TODO                AND if n>9 print greater than 9
 */

/* Header Files */

#include <stdio.h>  // Standard I/O functions
#include <stdlib.h> // Standard library functions

/* Main Function*/

int main()
{
    /*variable declaration*/
    int n, x = 1;

    /*Main code*/
    while (x == 1)
    {
        printf("Enter Integer Number :");
        scanf("%d", &n);
        if (n >= 1 && n <= 9)
        {
            switch (n)
            {
            case 1:
                printf("one");
                break;

            case 2:
                printf("two");
                break;

            case 3:
                printf("three");
                break;

            case 4:
                printf("four");
                break;

            case 5:
                printf("five");
                break;

            case 6:
                printf("six");
                break;

            case 7:
                printf("seven");
                break;

            case 8:
                printf("eight");
                break;

            case 9:
                printf("nine");
                break;
            }
        }

        else if (n < 0) //if entered is -ve
        {
            printf("Invalid Number,Try again\n");

            continue;
        }

        else if (n == 0) // if entered is 0
        {
            printf("%d", n);
        }

        else 
        {
            printf("Greater Than 9");
        }
            // for repeating the program

        printf("\nReintialize  1)Yes   2)No \n");
        scanf("%d", &x);
    }
}
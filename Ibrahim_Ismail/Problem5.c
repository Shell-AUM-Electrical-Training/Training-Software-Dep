/**
 * Author: Ibrahim Ismail
 //TODO (Description): foor loop in c
 */

/* Header Files */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/* Main Function */
int main()
{
    /*variable declaration*/
    int a, b, x = 1;

    char num[10][10] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"}; // Instead of using switch

    /*Main code*/
    while (x == 1)
    {

        printf("Enter TWO NUMBERS :");

        scanf("%d\n%d", &a, &b);

        for (int i = a; i <= b; ++i)
        {
            if (i >= 1 && i <= 9)
            {
                printf("%s\n", num[i - 1]);
            }
            else if (i > 9 && i % 2 == 0)
            {
                printf("even");
            }
            else
            {
                printf("\nodd");
            }
        }

        printf("\nReintialize  1)Yes   2)No \n");
        scanf("%d", &x);
    }

    return 0;
}

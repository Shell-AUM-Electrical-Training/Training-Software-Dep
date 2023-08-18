#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>



int main()
{
    int a, b;
    scanf("%d\n%d", &a, &b);
  	for(int num=a;num<=b;num++)
      {
          if(num == 1)
        printf("one");
    else if(num == 2)
        printf("two");
    else if(num == 3)
        printf("three");
    else if(num == 4)
        printf("four");
    else if(num == 5)
        printf("five");
    else if(num == 6)
        printf("six");
    else if(num == 7)
        printf("seven");
    else if(num == 8)
        printf("eight");
    else if(num == 9)
        printf("nine");
    else
        {
         if(num%2 == 0)
            printf("even");
        else
            printf("odd");
        }

    printf("\n");
      }

    return 0;
}


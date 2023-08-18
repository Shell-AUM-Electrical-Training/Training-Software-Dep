#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void n_less_than_or_equal_9(int n);
void n_greater_than_9(int n);

int main()
{
    int a, b;
    scanf("%d\n%d", &a, &b);

    if (a < b)
    {
        for (int i = a; i <= b; i++)
        {
            if (i >= 1 && i <= 9)
                n_less_than_or_equal_9(i);
            else
                n_greater_than_9(i);
        }
    }

    return 0;
}

void n_less_than_or_equal_9(int n)
{
    switch (n)
    {
    case 1:
        printf("one\n");
        break;
    case 2:
        printf("two\n");
        break;
    case 3:
        printf("three\n");
        break;
    case 4:
        printf("four\n");
        break;
    case 5:
        printf("five\n");
        break;
    case 6:
        printf("six\n");
        break;
    case 7:
        printf("seven\n");
        break;
    case 8:
        printf("eight\n");
        break;
    case 9:
        printf("nine\n");
        break;
    }
}

void n_greater_than_9(int n)
{
    if (n % 2 == 0)
        printf("even\n");
    else
        printf("odd\n");
}

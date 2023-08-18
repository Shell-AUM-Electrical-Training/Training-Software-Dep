#include <stdio.h>

int max_of_four(int a, int b, int c, int d);

int main()
{
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int max = max_of_four(a, b, c, d);
    printf("%d\n", max);
    return 0;
}

int max_of_four(int a, int b, int c, int d)
{
    int max, i;
    int arr[4] = {a, b, c, d};

    max = arr[0];
    for (i = 1; i < 4; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}
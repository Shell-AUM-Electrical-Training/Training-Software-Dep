#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, sum;
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    sum = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++)
        sum += arr[i];
    printf("%d\n", sum);
    return 0;
}

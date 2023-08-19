#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, *arr, i, hold;
    scanf("%d", &num);
    arr = (int*) malloc(num * sizeof(int));
    for(i = 0; i < num; i++) {
        scanf("%d", arr + i);
    }


    /* Write the logic to reverse the array. */
    for(i = 0; i < num/2; i++)
    {
        hold=arr[i];
        arr[i]=arr[num-i-1];
        arr[num-i-1]=hold;
    }
        
        
        
    for(i = 0; i < num; i++)
        printf("%d ", *(arr + i));
    return 0;
}
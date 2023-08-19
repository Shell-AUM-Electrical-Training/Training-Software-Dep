#include <stdio.h>

void main()
{
    int num;
    printf("Enter array size:");
    scanf("%d", &num);
    printf("Enter numbers:\n");
    int arr[num];
    
    for(int i = 0; i < num; i++) 
    {
        scanf("%d",& arr [i]);
    }
    

    printf("Reversal array: \n");
 for(int i = (num-1); i >=0; i--) 
    {
        printf("%d ", arr [i]);
    }


}
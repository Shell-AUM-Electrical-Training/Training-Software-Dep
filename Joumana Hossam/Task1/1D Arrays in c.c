#include <stdio.h>

void main()
{
    int n, sum=0; 
    printf("Array size:");
    scanf("%d",&n);
    printf("The array numbers:\n");
    int arr[n];

    for(int i=0 ; i<n;i++)
    {
        scanf("%d",& arr[i]);
        sum+=arr[i];

    }

    printf("The sum is: %d",sum);

}
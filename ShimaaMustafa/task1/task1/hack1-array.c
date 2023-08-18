#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
   int n,i;
    int *arr = (int*)malloc(n * sizeof(int));
       scanf("%d",&n);
       //scanf("%d",&*arr);
       int sum=0;
       for(i=0;i<n;i++)
           {
            scanf("%d",&*arr);
           sum +=*arr;
           }
       printf("%d",sum);
    return 0;
}

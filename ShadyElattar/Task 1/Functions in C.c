#include <stdio.h>
#include <stdlib.h>
int max_of_four(int a, int b, int c, int d)
{
    return max(a,max(b,max(c,d)));
}

int max(int x, int y)
{
    if(x>y)
        return x;
    return y;
}

int main()
{
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);

    printf("%d",max_of_four(a,b,c,d));

    return 0;
}

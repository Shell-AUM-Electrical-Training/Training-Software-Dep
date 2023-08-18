#include <stdio.h>
#include <stdlib.h>
int max(){
    int x,maxi;
    scanf("%d",&x);
maxi=x;
for(int i=0;i<3;i++){
    scanf("%d",&x);
    if(x>maxi)
        maxi=x;




}
return maxi;}

int main()
{

    printf("%d",max());
}

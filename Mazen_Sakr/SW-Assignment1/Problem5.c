#include <stdio.h>
/*
Add `int max_of_four(int a, int b, int c, int d)` here.
*/

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);
    
    return 0;
}

int max_of_four(int No1, int No2,int No3, int No4){
    int retVal=0;
    if (No1>No2 && No1>No3 && No1>No4 ) {
        retVal = No1;
    } else if (No2>No3 && No2>No4){
        retVal = No2;
    } else if( No3>No4){
        retVal = No3;
    } else {
        retVal = No4;
    }
    return retVal;
}
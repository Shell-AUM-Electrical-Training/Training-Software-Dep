#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>



int main() 
{
    int a, b;
    scanf("%d\n%d", &a, &b);
  	// Complete the code.
    char* numbers[9] = {"one\n","two\n","three\n","four\n","five\n","six\n","seven\n","eight\n","nine\n"};
    for (int counter = a; counter <= b; counter++){
        if(counter>0&&counter<10){
            printf("%s",numbers[counter-1]);
        }
        else if(counter%2) {
            printf("odd\n");            
        }
        else {
            printf("even\n");
        }
    }
    return 0;
}

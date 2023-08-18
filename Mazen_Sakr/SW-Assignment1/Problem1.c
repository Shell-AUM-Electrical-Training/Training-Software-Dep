#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int arrSize = 0, output = 0, tempInput = 0;
    scanf("%d", &arrSize);
    int *const arr = (int*)malloc(arrSize * sizeof(int));
    fflush(stdin);
    for (int counter = 0; counter < arrSize; counter++) {
        scanf("%d", &tempInput);
        *(arr + counter) = tempInput;
        output += *(arr + counter);
    }
    printf("%d ", output);
    return 0;
}

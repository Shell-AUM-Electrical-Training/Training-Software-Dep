#include <stdio.h>

int max_of_four(int a, int b, int c, int d) {

    int value[4] = {a, b, c, d};
    int max_value = value[0];

    for (int i = 1; i < 4; i++) {

        if (value[i] > max_value) {
            max_value = value[i];
        }
        else {
            continue;
        }
    }

    return max_value;
}

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);
    
    return 0;
}
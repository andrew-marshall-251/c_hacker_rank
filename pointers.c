#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function
    int a_temp = *a;
    int b_temp = *b;
    
    *a = a_temp + b_temp;

    int absolute_dif = a_temp - b_temp;
    if (absolute_dif < 0) {
        *b = -absolute_dif;
    } else {
        *b = absolute_dif;
    }
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}

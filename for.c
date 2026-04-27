#include <stdio.h>

int main() 
{
    int a, b;
    scanf("%d\n%d", &a, &b);
  	// Complete the code.
    char *word[9] = {
        "one", "two", "three", "four",
        "five", "six", "seven", "eight", "nine"
    };
    
    for (int i = a; i <= b; i++) {
        if (1 <= i && i <= 9) {
            puts(word[i - 1]);
        } else {
            if (i % 2) {
                puts("odd");
            } else {
                puts("even");
            }
        }
    }

    return 0;
}



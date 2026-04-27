#include <stdio.h>
#include <ctype.h>

int main() {

    // read
    char    line[1001];
    scanf("%1000[^\n]%*c", line);
    
    // count
    int     count[10] = {0};
    for (int i = 0; line[i]; i++) {
        if (isdigit(line[i])) {
            count[line[i] - '0']++;
        }
    }
    // print    
    for (int i = 0; i < 10; i++) {
        if (i == 9) {
            printf("%d", count[i]);
        } else {
            printf("%d ", count[i]);
        }
    }
    puts("");
    
    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lexicographic_sort(const char* a, const char* b) {
    return strcmp(a, b);
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return strcmp(b, a);
}

int get_number_of_distinct_characters(const char *s) {
    int is_seen_char[256] = {0};
    int count = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (!is_seen_char[s[i]]) {
            is_seen_char[s[i]] = 1;
            count++;
        }
    }
    return count;
}
int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int a_num_distinct_characters = get_number_of_distinct_characters(a);
    int b_num_distinct_characters = get_number_of_distinct_characters(b);
    int res = a_num_distinct_characters - b_num_distinct_characters;
    if (res == 0)
        return strcmp(a, b);
    return res;
}

int sort_by_length(const char* a, const char* b) {
    int res = strlen(a) - strlen(b);
    if (res == 0)
        return strcmp(a, b);
    return res;
}

void    string_swap(char **a, char **b) {
    char    *temp = *a;
    *a = *b;
    *b = temp;
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len - 1; j++) {
            if (cmp_func(arr[j], arr[j + 1]) > 0)
                string_swap(&arr[j], &arr[j + 1]);
        }
    }
}


int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}

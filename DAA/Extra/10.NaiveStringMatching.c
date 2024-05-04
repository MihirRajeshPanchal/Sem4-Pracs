#include <stdio.h>
#include <string.h>

void naive_string_matcher(char text[], char pat[]) {
    char temp[100];
    int n = strlen(text);
    int m = strlen(pat);
    int i, j, s, k, count = 0;
    
    for (s = 0; s <= n - m; s++) {
        for (j = s, k = 0; k < m; j++, k++)
            temp[k] = text[j];
        temp[k] = '\0';
        
        if (strcmp(pat, temp) == 0) {
            printf("\n Pattern Occurs With Shift : %d ", s);
            count++;
        }
    }
    printf("\n\n No Of Times Pattern Occurs  %d:", count);
}

int main() {
    char text[100], pat[100];
    
    printf("\nEnter the text : ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';  
    
    printf("\nEnter the pattern : ");
    fgets(pat, sizeof(pat), stdin);
    pat[strcspn(pat, "\n")] = '\0';      
    naive_string_matcher(text, pat);
    
    return 0;
}
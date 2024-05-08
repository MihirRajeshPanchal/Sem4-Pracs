#include <stdio.h>
#include <string.h>

#define d 256

void search(char pattern[], char text[], int prime) {
    int pattern_length = strlen(pattern);
    int text_length = strlen(text);
    int i, j;
    int pattern_hash = 0; 
    int text_hash = 0; 
    int hash_multiplier = 1;

    // Calculate (d^(pattern_length-1)) % prime
    for (i = 0; i < pattern_length - 1; i++)
        hash_multiplier = (hash_multiplier * d) % prime;

    // Calculate the hash value of pattern and first window of text
    for (i = 0; i < pattern_length; i++) {
        pattern_hash = (d * pattern_hash + pattern[i]) % prime;
        text_hash = (d * text_hash + text[i]) % prime;
    }

    // Slide the pattern over text one by one
    for (i = 0; i <= text_length - pattern_length; i++) {
        // Check the hash values of current window of text and pattern.
        // If the hash values match then only check for characters one by one.
        if (pattern_hash == text_hash) {
            // Check characters one by one
            for (j = 0; j < pattern_length; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }
            // If pattern hash matches and all characters matched, print the index
            if (j == pattern_length)
                printf("Pattern found at index %d \n", i);
        }
        // Calculate hash value for next window of text: Remove leading digit,
        // add trailing digit, and take mod to ensure positive value.
        if (i < text_length - pattern_length) {
            text_hash = (d * (text_hash - text[i] * hash_multiplier) + text[i + pattern_length]) % prime;
            if (text_hash < 0)
                text_hash = (text_hash + prime);
        }
    }
}

int main() {
    char text[100], pattern[100];
    int prime;

    printf("Enter the text: ");
    scanf("%s", text);

    printf("Enter the pattern: ");
    scanf("%s", pattern);

    printf("Enter a prime number: ");
    scanf("%d", &prime);

    search(pattern, text, prime);
    return 0;
}

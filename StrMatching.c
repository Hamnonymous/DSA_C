#include <stdio.h>
#include <string.h>

// Function to remove newline character from fgets
void removeNewline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

// Naive string matching function
void stringMatch(char text[], char pattern[]) {
    int n = strlen(text);
    int m = strlen(pattern);
    int found = 0;

    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j])
                break;
        }

        if (j == m) {
            printf("Pattern found at index %d\n", i);
            found = 1;
        }
    }

    if (!found)
        printf("Pattern not found in the text.\n");
}

int main() {
    char text[100], pattern[100];

    printf("Enter main text: ");
    fgets(text, sizeof(text), stdin);
    removeNewline(text); // remove trailing newline from fgets

    printf("Enter pattern to search: ");
    fgets(pattern, sizeof(pattern), stdin);
    removeNewline(pattern); // remove trailing newline

    stringMatch(text, pattern);

    return 0;
}

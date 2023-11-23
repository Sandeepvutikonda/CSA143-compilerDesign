#include <stdio.h>

int main() {
    char input_text[] = "This is a sample text.\nIt has multiple\nlines and various spaces.";
    int whitespace_count = 0;
    int newline_count = 0;
    int i;

    for (i = 0; input_text[i] != '\0'; i++) {
        if (input_text[i] == ' ') {
            whitespace_count++;
        } else if (input_text[i] == '\n') {
            newline_count++;
        }
    }

    printf("Number of whitespace characters: %d\n", whitespace_count);
    printf("Number of newline characters: %d\n", newline_count);

    return 0;
}

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isSingleLineComment(char *line) {
    size_t len = strlen(line);
    if (len >= 2 && line[0] == '/' && line[1] == '/') {
        return true;
    }
    return false;
}

bool isMultiLineCommentStart(char *line) {
    size_t len = strlen(line);
    if (len >= 2 && line[0] == '/' && line[1] == '*') {
        return true;
    }
    return false;
}

bool isMultiLineCommentEnd(char *line) {
    size_t len = strlen(line);
    if (len >= 2 && line[len - 2] == '*' && line[len - 1] == '/') {
        return true;
    }
    return false;
}

bool isComment(char *line) {
    if (isSingleLineComment(line) || isMultiLineCommentStart(line) || isMultiLineCommentEnd(line)) {
        return true;
    }
    return false;
}

int main() {
    char input[] = "/* This is a multi-line comment */"; // Change the input here

    if (isComment(input)) {
        printf("The given line is a comment.\n");
    } else {
        printf("The given line is not a comment.\n");
    }

    return 0;
}

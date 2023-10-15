#include <stdio.h>
#include <string.h>

void removeLine(char *str) {
    int length = strlen(str);
    if (str[length - 1] == '\n') {
        str[length - 1] = '\0';
    }
}

void vigenereEncrypt(char input[], char keyword[]) {
}

int main() {

    char input[100];
    char keyword[100];

    printf("Enter TEXT: ");
    fgets(input, sizeof(input), stdin);
    removeLines(input);

    printf("Enter KEYWORD: ");
    scanf("%s", keyword);

    vigenereEncrypt(input, keyword);

    printf("Encrypted Text: %s\n", input);

    return 0;
}
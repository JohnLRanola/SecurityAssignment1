#include <stdio.h>
#include <string.h>

void removeLines(char *str) {
    int length = strlen(str);
    if (str[length - 1] == '\n') {
        str[length - 1] = '\0';
    }
}

void vigenereEncrypt(char input[], char keyword[]) {

    int inputLength = strlen(input);
    int keywordLength = strlen(keyword);
    int i, j;

    for (i = 0, j = 0; i < inputLength; ++i) {

        char curChar = input[i];

         if ((curChar >= 'a' && curChar <= 'z') || (curChar >= 'A' && curChar <= 'Z')) {
            char base = (curChar >= 'a' && curChar <= 'z') ? 'a' : 'A';
            input[i] = (curChar + keyword[j] - 2 * base) % 26 + base;
            ++j;

            if (j == keywordLength) {
                j = 0; 
            }
         }
    }
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
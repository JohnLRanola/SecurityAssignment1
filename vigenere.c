#include <stdio.h>
#include <string.h>

int main() {

    char input[100];
    char keyword[100];

    printf("Enter TEXT: ");
    fgets(input, sizeof(input), stdin);
    printf("Enter KEYWORD: ");

    fgets(keyword, sizeof(keyword), stdin);

    vigenereEncrypt(input, keyword);

    return 0;
}
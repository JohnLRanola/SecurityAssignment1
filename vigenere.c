#include <stdio.h>
#include <string.h>

void vigenereEncrypt(char input[], char keyword[]) {

    int inputLength = strlen(input);
    int keywordLength = strlen(keyword);
    char enryptedText[inputLength];

    for (int i = 0; i < inputLength; i++) {

        char inputChar = input[i];
        char keywordChar = keyword[i % keywordLength];

        // Encryption for uppercase
        if (inputChar >= 'A' && inputChar <= 'Z') {
            enryptedText[i] = ((inputChar - 'A' + keywordChar - 'A') % 26);
        }
    }


}

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
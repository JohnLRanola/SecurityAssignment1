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
    int i, j = 0;

    // Loops through each character of input
    for (i = 0; i < inputLength; ++i) {
        char curChar = input[i];

    // This checks if character is in the alphabet
        if ((curChar >= 'a' && curChar <= 'z') || (curChar >= 'A' && curChar <= 'Z')) {
    
    // Converts characters to uppercase or lowercase when needed
    // keywordChar stores the character 
            char base = (curChar >= 'a' && curChar <= 'z') ? 'a' : 'A';
            char keywordChar = keyword[j];

    /*
    The basis of this cipher is the formula which is (curChar
    - base + keywordChar - 'a' ) % 26 + base;

    curChar - base converts the current character to a number between
    0 - 25 depending on the position they are at in the alphabet

    keywordChar - 'a' is used to convert the keyword character to a
    number value

    (curChar - base + keywordChar - 'a') % 26 adds two values 
    and takes the result modulo 26. This makes sure it is in the
    number of alphabet

    The + base then converts the number back to character in the 
    right case and puts it in input[i]

    */
            input[i] = (curChar - base + keywordChar - 'a') % 26 + base;
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
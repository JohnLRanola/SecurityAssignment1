#include <stdio.h>
#include <string.h>



int main() {
    char input[100];
    char keyword[5];

    printf("Enter TEXT: ");
    scanf("%s", input);
    
    printf("Enter a 4 letter KEYWORD: ");
    scanf("%s", keyword);

    if (strlen(keyword) != 4) {
        printf("ERROR. Please enter a 4 LETTER KEYWORD\n");
        return 1;
    }

    printf("Encrypted Text: ");
    hillCipher(input, keyword);
    printf("\n");

    return 0;
}
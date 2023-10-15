#include <stdio.h>
#include <string.h>

int modInverse(int a, int m) {
    a = a % m;

    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
}

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
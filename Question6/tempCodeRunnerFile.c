#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char plaintext[100], keyword[5];
    printf("Enter plaintext (only uppercase letters): ");
    scanf("%s", plaintext);
    printf("Enter keyword (only uppercase letters, exactly 4 letters): ");
    scanf("%s", keyword);

    // Convert plaintext to uppercase
    for (int i = 0; i < strlen(plaintext); i++) {
        plaintext[i] = (char)toupper(plaintext[i]);
    }

    // Generate key matrix from the keyword
    int key[2][2];
    key[0][0] = keyword[0] - 'A';
    key[1][0] = keyword[1] - 'A';
    key[0][1] = keyword[2] - 'A';
    key[1][1] = keyword[3] - 'A';

    // Encrypt the plaintext using the key matrix
    int len = strlen(plaintext);
    for (int i = 0; i < len; i += 2) {
        int letter1 = plaintext[i] - 'A';
        int letter2 = (i + 1 < len) ? plaintext[i + 1] - 'A' : 0;
        
        int encryptedLetter1 = (key[0][0] * letter1 + key[0][1] * letter2) % 26;
        int encryptedLetter2 = (key[1][0] * letter1 + key[1][1] * letter2) % 26;
        
        printf("%c%c", (char)(encryptedLetter1 + 'A'), (char)(encryptedLetter2 + 'A'));
    }

    printf("\n");

    return 0;
}

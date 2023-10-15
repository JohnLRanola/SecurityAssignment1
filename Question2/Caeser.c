#include <stdio.h>

int main() {
    char input[100];
    int shift;

    // Input from user
    printf("Enter TEXT:");
    fgets(input, sizeof(input), stdin);

    // Input for the shift value
    printf("Enter value for SHIFT:");
    scanf("%d", &shift);

    // Call function for cipher
    caesarCipher(input, shift);

    // Output of encryption
    printf("Encrypted Text from Caesar Cipher: %s", input);
}
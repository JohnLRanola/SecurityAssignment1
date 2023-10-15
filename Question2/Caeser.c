#include <stdio.h>

// Function for cipher
void caesarCipher(char input[], int shift) {
    for (int i = 0; input[i] != '\0'; ++i) {
        // for uppercase characters
        if (input[i] >= 'A' && input[i] <= 'Z') {
            input[i] = (input[i] - 'A' + shift) % 26 + 'A';
        }
    }
}
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
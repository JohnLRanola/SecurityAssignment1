#include <stdio.h>

// Function for cipher
void caesarCipher(char input[], int key) {
    for (int i = 0; input[i] != '\0'; ++i) {

        // for uppercase characters
        if (input[i] >= 'A' && input[i] <= 'Z') {
            input[i] = (input[i] - 'A' + key) % 26 + 'A';
        }

        // for lowercase characters
        else if (input[i] >= 'a' && input[i] <= 'z') {
            input[i] = (input[i] - 'a' + key) % 26 + 'a';
        }
    }
}
int main() {
    char input[100];
    int key;

    // Input from user
    printf("Enter TEXT:");
    fgets(input, sizeof(input), stdin);

    // Input for the key value
    printf("Enter value for key:");
    scanf("%d", &key);

    // Call function for cipher
    caesarCipher(input, key);

    // Output of encryption
    printf("Encrypted Text from Caesar Cipher: %s", input);
}
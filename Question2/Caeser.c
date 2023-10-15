#include <stdio.h>

// Function for cipher
void caesarCipher(char input[], int key) {

    // Goes through each character until is reaches a null character '\0' 
    for (int i = 0; input[i] != '\0'; ++i) {

        // for uppercase characters
        /* Character is converted to number between 0 and 25
        by taking away the ASCII value of 'A'. 

        Key is then added to the number acquired

        Modulo 26 is used to make sure it is in the range of the 
        alphabet

        It is then converted back to uppercase and shifts the charatcer by
        the key in the alphabet
        
        */
        if (input[i] >= 'A' && input[i] <= 'Z') {
            input[i] = (input[i] - 'A' + key) % 26 + 'A';
        }

        // for lowercase characters
        // The same logic is used here but is just for lowercase
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
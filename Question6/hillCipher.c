#include <stdio.h>
#include <string.h>

void hillCipher(char* input, char* keyword) {

    int keywordMatrix[2][2];
    int message[2];
    int result[2];

    // Keyword is mapped as integers and stored in the matrix
    keywordMatrix[0][0] = (keyword[0] >= 'a' && keyword[0] <= 'z') ? keyword[0] - 'a' : keyword[0] - 'A';
    keywordMatrix[0][1] = (keyword[1] >= 'a' && keyword[1] <= 'z') ? keyword[1] - 'a' : keyword[1] - 'A';
    keywordMatrix[1][0] = (keyword[2] >= 'a' && keyword[2] <= 'z') ? keyword[2] - 'a' : keyword[2] - 'A';
    keywordMatrix[1][1] = (keyword[3] >= 'a' && keyword[3] <= 'z') ? keyword[3] - 'a' : keyword[3] - 'A';

    // Processes 2 characters from input and converts to numbers
    for (int i = 0; input[i] != '\0'; i += 2) {

    // Input is mapped as intgers and stored in message array
        message[0] = (input[i] >= 'a' && input[i] <= 'z') ? input[i] - 'a' : input[i] - 'A';
        message[1] = (input[i + 1] >= 'a' && input[i + 1] <= 'z') ? input[i + 1] - 'a' : input[i + 1] - 'A';
        
        for (int j = 0; j <2; j++) {

            result[j] = 0;
            
            for (int k = 0; k < 2; k++) {
                result[j] += keywordMatrix[j][k] * message[k];
            }
            result[j] = (result[j] + 26) % 26;
        }

          printf("%c%c", result[0] + ((input[i] >= 'a' && input[i] <= 'z') ? 'a' : 'A'),
               result[1] + ((input[i + 1] >= 'a' && input[i + 1] <= 'z') ? 'a' : 'A'));
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
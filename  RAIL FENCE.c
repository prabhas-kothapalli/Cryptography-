#include <stdio.h>
#include <string.h>
#include <ctype.h>
void railFenceEncrypt(char message[], int rails) {
    int messageLen = strlen(message);
    char encrypted[100] = "";
    int railIndex, railDirection;
    for (int rail = 0; rail < rails; ++rail) {
        railIndex = rail;
        railDirection = 1;
        for (int i = 0; i < messageLen; ++i) {
            if (railIndex == rail) {
                encrypted[strlen(encrypted)] = message[i];
            }
            if (railIndex == 0 || railIndex == rails - 1) {
                railDirection *= -1;
            }
            railIndex += railDirection;
        }
    }
    strcpy(message, encrypted);
}
void railFenceDecrypt(char message[], int rails) {
    int messageLen = strlen(message);
    char decrypted[100] = "";
    int railIndex, railDirection;
    int railLength = messageLen / rails;
    for (int rail = 0; rail < rails; ++rail) {
        railIndex = rail;
        railDirection = 1;
        for (int i = rail * railLength; i < (rail + 1) * railLength; ++i) {
            decrypted[strlen(decrypted)] = message[railIndex];
            if (railIndex == 0 || railIndex == rails - 1) {
                railDirection *= -1;
            }
            railIndex += railDirection;
        }
    }
    strcpy(message, decrypted);
}
int main() {
    char message[100];
    int rails;
    printf("Enter the message: ");
    fgets(message, sizeof(message), stdin);
    printf("Enter the number of rails: ");
    scanf("%d", &rails);
    message[strcspn(message, "\n")] = '\0';
    railFenceEncrypt(message, rails);
    printf("Encrypted message: %s\n", message);
    railFenceDecrypt(message, rails);
    printf("Decrypted message: %s\n", message);
    return 0;
}
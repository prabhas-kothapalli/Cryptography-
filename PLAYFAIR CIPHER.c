#include <stdio.h>
#include <string.h>
#define SIZE 5
void createKeyTable(const char key[], char keyTable[][SIZE]) {
}
void encrypt(char message[], const char keyTable[][SIZE]) {
}
void decrypt(char message[], const char keyTable[][SIZE]) {
}
int main() {
    char key[26], message[100];
    char keyTable[SIZE][SIZE];
    printf("Enter the key: ");
    scanf("%s", key);
    createKeyTable(key, keyTable);
    getchar();
    printf("Enter the message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0';
    encrypt(message, keyTable);
    printf("Encrypted message: %s\n", message);
    decrypt(message, keyTable);
    printf("Decrypted message: %s\n", message);
    return 0;
}

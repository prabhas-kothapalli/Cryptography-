#include <stdio.h>
#include <string.h>
#include <ctype.h>
void vigenereEncrypt(char message[], const char key[]) {
    int messageLen = strlen(message);
    int keyLen = strlen(key);
    for (int i = 0; i < messageLen; ++i) {
        if (isalpha(message[i])) {
            char shift = islower(message[i]) ? 'a' : 'A';
            int keyIndex = i % keyLen;
            int keyShift = tolower(key[keyIndex]) - 'a';
            message[i] = (message[i] - shift + keyShift) % 26 + shift;
        }
    }
}
void vigenereDecrypt(char message[], const char key[]) {
    int messageLen = strlen(message);
    int keyLen = strlen(key);
    for (int i = 0; i < messageLen; ++i) {
        if (isalpha(message[i])) {
            char shift = islower(message[i]) ? 'a' : 'A';
            int keyIndex = i % keyLen;
            int keyShift = tolower(key[keyIndex]) - 'a';
            message[i] = (message[i] - shift - keyShift + 26) % 26 + shift;
        }
    }
}
int main() {
    char message[100];
    char key[100];
    printf("Enter the message: ");
    fgets(message, sizeof(message), stdin);
    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);
    message[strcspn(message, "\n")] = '\0';
    key[strcspn(key, "\n")] = '\0';
    vigenereEncrypt(message, key);
    printf("Encrypted message: %s\n", message);
    vigenereDecrypt(message, key);
    printf("Decrypted message: %s\n", message);
    return 0;
}
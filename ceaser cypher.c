#include <stdio.h>
#include <string.h>
void process(char message[], int key, int encrypt) {
    int i;
    char ch, offset;
    offset = encrypt ? 'a' : 'z';
    for (i = 0; message[i] != '\0'; ++i) {
        ch = message[i];

        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            ch = ch + key;
            if (ch > offset + 25) {
                ch = ch - (offset + 25) + offset - 1;
            }
            message[i] = ch;
        }
    }
}
int main() {
    char message[100];
    int key;

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter a key (positive integer): ");
    scanf("%d", &key);

    process(message, key, 1); // Encrypt
    printf("Encrypted message: %s\n", message);

    process(message, key, 0); // Decrypt
    printf("Decrypted message: %s\n", message);
    return 0;
}
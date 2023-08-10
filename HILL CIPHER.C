#include <stdio.h>
#define MATRIX_SIZE 2
void matrixMultiply(int key[MATRIX_SIZE][MATRIX_SIZE], int vector[MATRIX_SIZE]) {
    int result[MATRIX_SIZE] = {0};
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        for (int j = 0; j < MATRIX_SIZE; ++j) {
            result[i] += key[i][j] * vector[j];
        }
    }
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        vector[i] = result[i] % 26;
    }
}
int main() {
    int key[MATRIX_SIZE][MATRIX_SIZE] = {{6, 24}, {1, 13}};
    char plaintext[100];
    int vector[MATRIX_SIZE];
    printf("Enter the plaintext (up to %d characters): ", MATRIX_SIZE);
    scanf("%s", plaintext);
    getchar();
    printf("Enter %d numbers as the initial vector: ", MATRIX_SIZE);
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        scanf("%d", &vector[i]);
    }
    int len = 0;
    while (plaintext[len] != '\0') {
        ++len;
    }
    if (len % 2 != 0) {
        printf("Plaintext length must be even.\n");
        return 1;
    }
    printf("Ciphertext: ");
    for (int i = 0; i < len; i += 2) {
        vector[0] = plaintext[i] - 'A';
        vector[1] = plaintext[i + 1] - 'A';
        matrixMultiply(key, vector);
        printf("%c%c", vector[0] + 'A', vector[1] + 'A');
    }
    printf("\n");
    return 0;
}
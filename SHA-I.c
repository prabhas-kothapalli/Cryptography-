#include <stdio.h>
#include <stdint.h>
#include <string.h>
typedef uint32_t Word;
typedef uint64_t Length;
#define ROTATE_LEFT(x, n) ((x << n) | (x >> (32 - n)))
void sha1(const unsigned char *message, Length length, Word hash[5]) {
    Word h0 = 0x67452301, h1 = 0xEFCDAB89, h2 = 0x98BADCFE, h3 = 0x10325476, h4 = 0xC3D2E1F0;
    for (int i = 0; i < length / 64; ++i) {
        const Word *chunk = (const Word *)(message + i * 64);
        Word w[80];
        for (int t = 0; t < 16; ++t) w[t] = chunk[t];
        for (int t = 16; t < 80; ++t) w[t] = ROTATE_LEFT(w[t - 3] ^ w[t - 8] ^ w[t - 14] ^ w[t - 16], 1);
        Word a = h0, b = h1, c = h2, d = h3, e = h4;
        for (int t = 0; t < 80; ++t) {
            Word f, k;
            if (t < 20) { f = (b & c) | ((~b) & d); k = 0x5A827999; }
            else if (t < 40) { f = b ^ c ^ d; k = 0x6ED9EBA1; }
            else if (t < 60) { f = (b & c) | (b & d) | (c & d); k = 0x8F1BBCDC; }
            else { f = b ^ c ^ d; k = 0xCA62C1D6; }
            Word temp = ROTATE_LEFT(a, 5) + f + e + k + w[t];
            e = d;
            d = c;
            c = ROTATE_LEFT(b, 30);
            b = a;
            a = temp;
        }
        h0 += a;
        h1 += b;
        h2 += c;
        h3 += d;
        h4 += e;
    }
    hash[0] = h0;
    hash[1] = h1;
    hash[2] = h2;
    hash[3] = h3;
    hash[4] = h4;
}
void printHash(const Word hash[5]) {
    for (int i = 0; i < 5; ++i) {
        printf("%08x", hash[i]);
    }
    printf("\n");
}
int main() {
    const char *message = "Hello, world!";
    Length length = strlen(message);
    Word hash[5];
    sha1((const unsigned char *)message, length, hash);
    printf("SHA-1 hash: ");
    printHash(hash);
    return 0;
}
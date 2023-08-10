#include <stdio.h>
#include <stdint.h>
#include <string.h>
typedef uint32_t Word;
typedef uint64_t Length;
#define BLOCK_SIZE 64
#define HASH_SIZE 16
#define F(x, y, z) ((x & y) | (~x & z))
#define G(x, y, z) ((x & z) | (y & ~z))
#define H(x, y, z) (x ^ y ^ z)
#define I(x, y, z) (y ^ (x | ~z))
#define ROTATE_LEFT(x, n) ((x << n) | (x >> (32 - n)))
const Word K[] = {
    0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
    0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
    0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
    0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
};
const int S[] = {
    7, 12, 17, 22,
    5, 9, 14, 20,
    4, 11, 16, 23,
    6, 10, 15, 21,
};
void md5(const unsigned char *message, Length length, Word hash[4]) {
    Word a = 0x67452301;
    Word b = 0xefcdab89;
    Word c = 0x98badcfe;
    Word d = 0x10325476;
    for (int i = 0; i < length / BLOCK_SIZE; ++i) {
        const Word *chunk = (const Word *)(message + i * BLOCK_SIZE);
        Word aa = a;
        Word bb = b;
        Word cc = c;
        Word dd = d;
        for (int j = 0; j < 64; ++j) {
            Word f, g;
            if (j < 16) {
                f = F(b, c, d);
                g = j;
            } else if (j < 32) {
                f = G(b, c, d);
                g = (5 * j + 1) % 16;
            } else if (j < 48) {
                f = H(b, c, d);
                g = (3 * j + 5) % 16;
            } else {
                f = I(b, c, d);
                g = (7 * j) % 16;
            }
            Word temp = d;
            d = c;
            c = b;
            b = b + ROTATE_LEFT((a + f + K[j] + chunk[g]), S[j]);
            a = temp;
        }
        a += aa;
        b += bb;
        c += cc;
        d += dd;
    }
    hash[0] = a;
    hash[1] = b;
    hash[2] = c;
    hash[3] = d;
}
void printHash(const Word hash[4]) {
    for (int i = 0; i < 4; ++i) {
        printf("%02x%02x%02x%02x", (hash[i] >> 0) & 0xff, (hash[i] >> 8) & 0xff, (hash[i] >> 16) & 0xff, (hash[i] >> 24) & 0xff);
    }
    printf("\n");
}
int main() {
    const char *message = "Hello, world!";
    Length length = strlen(message);
    Word hash[4];
    md5((const unsigned char *)message, length, hash);
    printf("MD5 hash: ");
    printHash(hash);
    return 0;
}
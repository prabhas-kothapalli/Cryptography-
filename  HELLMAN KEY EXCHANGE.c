#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
typedef uint64_t BigInteger;
BigInteger modExp(BigInteger base, BigInteger exp, BigInteger mod) {
    BigInteger result = 1;
    while (exp) {
        if (exp & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}
int main() {
    srand(time(NULL));
    BigInteger p = 23, g = 5;
    BigInteger a = rand() % (p - 2) + 1, b = rand() % (p - 2) + 1;
    BigInteger A = modExp(g, a, p), B = modExp(g, b, p);
    BigInteger secretA = modExp(B, a, p), secretB = modExp(A, b, p);
    printf("Shared secret (Alice): %llu\n", secretA);
    printf("Shared secret (Bob): %llu\n", secretB);
    return 0;
}
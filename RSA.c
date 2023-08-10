#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
typedef uint64_t BigInteger;
BigInteger gcd(BigInteger a, BigInteger b) {
    return b == 0 ? a : gcd(b, a % b);
}
BigInteger modExp(BigInteger base, BigInteger exp, BigInteger mod) {
    BigInteger result = 1;
    while (exp) {
        if (exp & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}
int isPrime(BigInteger num) {
    if (num <= 1) return 0;
    for (BigInteger i = 2; i * i <= num; ++i)
        if (num % i == 0) return 0;
    return 1;
}
BigInteger generatePrime() {
    BigInteger num;
    do num = rand() % 100 + 2;
    while (!isPrime(num));
    return num;
}
int main() {
    srand(time(NULL));
    BigInteger p = generatePrime(), q = generatePrime(), n = p * q, phi = (p - 1) * (q - 1);
    BigInteger e = 2; while (e < phi && gcd(e, phi) != 1) ++e;
    BigInteger d = 1; while ((d * e) % phi) ++d;
    BigInteger plaintext = 12345;
    printf("Plaintext: %llu\n", plaintext);
    BigInteger encrypted = modExp(plaintext, e, n);
    printf("Encrypted: %llu\n", encrypted);
    BigInteger decrypted = modExp(encrypted, d, n);
    printf("Decrypted: %llu\n", decrypted);
    return 0;
}
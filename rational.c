#include "rational.h"
#include <stdlib.h>

static long gcd(long a, long b) {
    while (b != 0) {
        long t = b;
        b = a % b;
        a = t;
    }
    return a;
}

rational_t rational(long n, long d) {
    if (d == 0) {
        // Обработка ошибки деления на ноль
        exit(EXIT_FAILURE);
    }
    long g = gcd(abs(n), d);
    rational_t result = { n / g, d / g };
    if (result.denom < 0) {
        result.num = -result.num;
        result.denom = -result.denom;
    }
    return result;
}

long rat_num(rational_t r) {
    return r.num;
}

long rat_denom(rational_t r) {
    return r.denom;
}
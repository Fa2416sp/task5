#include "safe_rational.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

safe_rational_t safe_rat_parse(const char* str) {
    safe_rational_t r = {0, 1};
    sscanf(str, "%d/%d", &r.numerator, &r.denominator);
    assert(r.denominator != 0); // Проверка на деление на ноль
    return r;
}

safe_rational_t safe_rat_add(safe_rational_t a, safe_rational_t b) {
    safe_rational_t r = {
        .numerator = a.numerator * b.denominator + b.numerator * a.denominator,
        .denominator = a.denominator * b.denominator
    };
    return r;
}

safe_rational_t safe_rat_sub(safe_rational_t a, safe_rational_t b) {
    safe_rational_t r = {
        .numerator = a.numerator * b.denominator - b.numerator * a.denominator,
        .denominator = a.denominator * b.denominator
    };
    return r;
}

safe_rational_t safe_rat_mul(safe_rational_t a, safe_rational_t b) {
    safe_rational_t r = {
        .numerator = a.numerator * b.numerator,
        .denominator = a.denominator * b.denominator
    };
    return r;
}

safe_rational_t safe_rat_div(safe_rational_t a, safe_rational_t b) {
    assert(b.numerator != 0); // Проверка на деление на ноль
    safe_rational_t r = {
        .numerator = a.numerator * b.denominator,
        .denominator = a.denominator * b.numerator
    };
    return r;
}

void safe_rat_print(safe_rational_t r) {
    printf("%d/%d\n", r.numerator, r.denominator);
}

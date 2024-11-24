#ifndef SAFE_RATIONAL_H
#define SAFE_RATIONAL_H

typedef struct {
    int numerator;
    int denominator;
} safe_rational_t;

safe_rational_t safe_rat_parse(const char* str);
safe_rational_t safe_rat_add(safe_rational_t a, safe_rational_t b);
safe_rational_t safe_rat_sub(safe_rational_t a, safe_rational_t b);
safe_rational_t safe_rat_mul(safe_rational_t a, safe_rational_t b);
safe_rational_t safe_rat_div(safe_rational_t a, safe_rational_t b);
void safe_rat_print(safe_rational_t r);

#endif // SAFE_RATIONAL_H

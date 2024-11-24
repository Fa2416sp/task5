#include "safe_rational.h"
#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    safe_rational_t last_result = {0, 1};

    while (fgets(input, sizeof(input), stdin)) {
        char op;
        char num1[50], num2[50];
        sscanf(input, "%s %c %s", num1, &op, num2);

        safe_rational_t a = strcmp(num1, "last") == 0 ? last_result : safe_rat_parse(num1);
        safe_rational_t b = strcmp(num2, "last") == 0 ? last_result : safe_rat_parse(num2);
        safe_rational_t result;

        switch (op) {
            case '+': result = safe_rat_add(a, b); break;
            case '-': result = safe_rat_sub(a, b); break;
            case '*': result = safe_rat_mul(a, b); break;
            case '/': result = safe_rat_div(a, b); break;
            default: continue;
        }

        last_result = result;
        printf("= ");
        safe_rat_print(result);
    }

    return 0;
}

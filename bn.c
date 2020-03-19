#include "bn.h"

/* Count numbers of valid digits */
int count_digits(bn_t *n)
{
    int i;
    for (i = MAX_DIGITS; i > 0 && n->digits[i - 1] == 0; --i)
        ;
    return (i == 0) ? 1 : i;
}

/* Initialize bignum with value */
void bn_init(bn_t *n, int value)
{
    for (int i = 0; i < MAX_DIGITS; ++i) {
        if (value % 10) {
            n->digits[i] = value % 10;
        } else {
            n->digits[i] = 0;
        }
        value /= 10;
    }
    n->num_digits = count_digits(n);
}

/* A = B */
// void bn_assign(bn_t* a, bn_t *b)
// {
//     for (int i = 0; i < MAX_DIGITS; ++i)
//         a->digits[i] = b->digits[i];
//     a->num_digits = b->num_digits;
// }

/* C = A + B */
void bn_add(bn_t *c, bn_t *a, bn_t *b)
{
    for (int i = 0; i < MAX_DIGITS; ++i)
        c->digits[i] = 0;
    int carry = 0;
    for (int i = 0; i < MAX_DIGITS; ++i) {
        c->digits[i] = a->digits[i] + b->digits[i] + carry;
        carry = c->digits[i] / 10;
        c->digits[i] %= 10;
    }
    c->num_digits = count_digits(c);
}

/* C = A - B */
void bn_sub(bn_t *c, bn_t *a, bn_t *b)
{
    for (int i = 0; i < MAX_DIGITS; ++i)
        c->digits[i] = 0;

    int borrow = 0;
    for (int i = 0; i < MAX_DIGITS; ++i) {
        c->digits[i] = a->digits[i] - b->digits[i] - borrow;
        if (c->digits[i] < 0) {
            borrow = 1;
            c->digits[i] += 10;
        } else {
            borrow = 0;
        }
    }
    c->num_digits = count_digits(c);
}

/* C = A x B */
void bn_mul(bn_t *c, bn_t *a, bn_t *b)
{
    for (int i = 0; i < MAX_DIGITS; ++i)
        c->digits[i] = 0;

    for (int i = 0; i < MAX_DIGITS; ++i) {
        if (a->digits[i] == 0)
            continue;
        for (int j = 0; j < MAX_DIGITS; ++j) {
            if (b->digits[j] == 0)
                continue;
            c->digits[i + j] += (a->digits[i]) * (b->digits[j]);
        }
    }
    for (int i = 0; i < MAX_DIGITS - 1; ++i) {
        int carry = 0;
        carry = c->digits[i] / 10;
        c->digits[i + 1] += carry;
        c->digits[i] %= 10;
    }
    c->num_digits = count_digits(c);
}

/* Print bignum */
// void print_bn(bn_t n)
// {
//     printf("num digits: %d\n", n.num_digits);
//     for (int i = 0; i < n.num_digits; ++i)
//         printf("%d", n.digits[n.num_digits - i - 1]);
//     printf("\n");
// }
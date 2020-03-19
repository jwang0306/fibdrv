#ifndef BIGN_H
#define BIGN_H

#define MAX_DIGITS 32

/*
 * The number is stored in reverse order
 * ex. 12345 -> digits[5,4,3,2,1,0,0,0,0,0,0,0,.....]
 */
typedef struct bignum {
    int num_digits;
    int digits[MAX_DIGITS];
} bn_t;

int count_digits(bn_t *n);        /* Count numbers of valid digits */
void bn_init(bn_t *n, int value); /* Initialize bignum with value */
// void bn_assign(bn_t* a, bn_t *b); /* A = B */
void bn_add(bn_t *c, bn_t *a, bn_t *b); /* C = A + B */
void bn_sub(bn_t *c, bn_t *a, bn_t *b); /* C = A - B */
void bn_mul(bn_t *c, bn_t *a, bn_t *b); /* C = A x B */
// void print_bn(bn_t n); /* Print bignum */

#endif
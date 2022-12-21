#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

/* This is Nominal Animal's answer at
    http://stackoverflow.com/a/29434131
   to the StackOverflow.com question
    http://stackoverflow.com/questions/29420602/how-to-solve-this-without-using-queues-stacks-or-arrays

   At compile time, define preprocessor macro or macros
    DOT         To print out a directed graph of the card shuffling,
                in Graphviz dot language, to standard output
    EXACT       To print out the exact cycle lengths in product form,
                with ^ denoting exponentiation, to standard error

   This is licensed under the Creative Commons CC0 1.0 Universal license:
    https://creativecommons.org/publicdomain/zero/1.0/
   You can copy, modify, distribute and perform the work, even for
   commercial purposes, all without asking permissions.
   Nominal Animal makes no warranties about this work, and disclaims
   liability for all uses of this work, to the fullest extent permissible
   by law. In other words, if it breaks, you don't get to blame me,
   and get to keep all the pieces.

   Nominal Animal
   <question@nominal-animal.net>
*/

size_t *mapping(const size_t cards)
{
    size_t *deck, n;

    if (cards < (size_t)1) {
        errno = EINVAL;
        return NULL;
    }

    deck = malloc(cards * sizeof *deck);
    if (deck == NULL) {
        errno = ENOMEM;
        return NULL;
    }

    for (n = 0; n < cards; n++)
        deck[n] = n;

    n = cards;

    while (n > 2) {
        const size_t c0 = deck[0];
        const size_t c1 = deck[1];
        memmove(deck, deck + 2, (n - 2) * sizeof *deck);
        deck[n-1] = c0;
        deck[n-2] = c1;
        n--;
    }
    if (n == 2) {
        const size_t c = deck[0];
        deck[0] = deck[1];
        deck[1] = c;
    }

    return deck;
}

size_t *cycle_lengths(size_t *graph, const size_t nodes)
{
    size_t *len, i;

    if (graph == NULL || nodes < 1) {
        errno = EINVAL;
        return NULL;
    }

    len = malloc(nodes * sizeof *len);
    if (len == NULL) {
        errno = ENOMEM;
        return NULL;
    }

    for (i = 0; i < nodes; i++) {
        size_t c = i;
        size_t n = 1;

        while (graph[c] != i) {
            c = graph[c];
            n++;
        }

        len[i] = n;
    }

    return len;
}

#ifndef ULONG_BITS
#define ULONG_BITS (sizeof (unsigned long) * CHAR_BIT)
#endif

unsigned long *sieve(const size_t limit)
{
    const size_t   bytes = (limit / ULONG_BITS + 1) * sizeof (unsigned long);
    unsigned long *prime;
    size_t         base;

    prime = malloc(bytes);
    if (prime == NULL) {
        errno = ENOMEM;
        return NULL;
    }
    memset(prime, ~0U, bytes);

    /* 0 and 1 are not considered prime. */
    prime[0] &= ~(3UL);

    for (base = 2; base < limit; base++) {
        size_t i = base + base;
        while (i < limit) {
            prime[i / ULONG_BITS] &= ~(1UL << (i % ULONG_BITS));
            i += base;
        }
    }

    return prime;
}

int main(int argc, char *argv[])
{
    unsigned long *prime;
    size_t        *map, *len;
    size_t         cards, i, p;
    double         result;
    long           value;
    char           dummy;

    if (argc != 2 || sscanf(argv[1], " %ld %c", &value, &dummy) != 1 || value < 1L) {
        if (argc == 2)
            fprintf(stderr, "%s: Invalid number of cards.\n", argv[1]);
        fprintf(stderr, "\nUsage: %s NUMBER-OF-CARDS\n\n", argv[0]);
        return EXIT_FAILURE;
    }

    cards = (size_t)value;
    if (cards < (size_t)1 || (long)cards != value) {
        fprintf(stderr, "%s: Too many cards.\n", argv[1]);
        return EXIT_FAILURE;
    }

    map = mapping(cards);
    if (map == NULL) {
        fprintf(stderr, "%s.\n", strerror(errno));
        return EXIT_FAILURE;
    }

#if defined(DOT)
    printf("digraph { dir=LTR; \n");
    for (i = 0; i < cards; i++) {
        printf("\t\"%lu\" -> \"%lu\";\n", (unsigned long)i + 1UL, (unsigned long)map[i] + 1UL);
    }
    printf("}\n");
    fflush(stdout);
#endif

    len = cycle_lengths(map, cards);
    if (len == NULL) {
        fprintf(stderr, "%s.\n", strerror(errno));
        return EXIT_FAILURE;
    }

    prime = sieve(cards + 1);
    if (prime == NULL) {
        fprintf(stderr, "%s.\n", strerror(errno));
        return EXIT_FAILURE;
    }

    map[cards - 1] = 0;
    for (p = 2; p <= cards; p++) {
        map[p-2] = 0;
        if (prime[p / ULONG_BITS] & (1UL << (p % ULONG_BITS)))
            for (i = 0; i < cards; i++)
                if (len[i] > 1) {
                    size_t n = 0;
                    while (len[i] % p == 0) {
                        len[i] /= p;
                        n++;
                    }
                    if (n > map[p-2])
                        map[p-2] = n;
                }
    }

#if defined(EXACT)
    fprintf(stderr, "Exact result = ");
    i = 0;
    for (p = 2; p <= cards; p++)
        if (map[p-2] > 0) {
            if (i++ > 0)
                fprintf(stderr, " * ");
            if (map[p-2] > 1)
                fprintf(stderr, "%lu^%lu", (unsigned long)p, (unsigned long)map[p-2]);
            else
                fprintf(stderr, "%lu", (unsigned long)p);
        }
    fprintf(stderr, "\n");
    fflush(stderr);
#endif

    result = 1.0;
    for (p = 2; p <= cards; p++)
        while (map[p-2]-->0)
            result *= (double)p;

#if defined(DOT)
    fprintf(stderr, "%lu cards, %.0f rounds.\n", (unsigned long)cards, result);
#else
    printf("%lu cards, %.0f rounds.\n", (unsigned long)cards, result);
#endif

    free(prime);
    free(len);
    free(map);

    return EXIT_SUCCESS;
}
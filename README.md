# RSA-Factoring-Challenge

## About RSA
RSA (Rivest–Shamir–Adleman) is a public-key cryptosystem, one of the oldest, that is widely used for secure data transmission depending on two large prime numbers.

The security of RSA relies on the practical difficulty of factoring the product of two large prime numbers.

In this project I am trying to factorize these numbers as fast as possible so that we can decode the encrypted datat.

## To build normal factoring program
```bash
$ gcc -Wall -Werror -Wextra -pedantic normal_factoring.c -lm -o factors
```

## To build factoring factoring program
```bash
$ gcc -Wall -Werror -Wextra -pedantic prime_factoring.c -lm -o rsa
```

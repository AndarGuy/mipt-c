#ifndef UTILS_H
#define UTILS_H

/**
 * @brief Finds the greatest common divisor of 2 numbers.
 * 
 * @param n first number
 * @param n1 second number
 * @return int the greatest common divisor
 */
int gcd(int n, int n1);


/**
 * @brief finds factorial of n
 * 
 * @param n number to find factorial with
 * @return int factorial value
 */
int fac(int n);

/**
 * @brief return x^n
 * 
 * @param x the base
 * @param n the exp
 * @return long int 
 */
long int power(long int x, long int n);

/**
 * @brief finds the number of combinations
 * 
 * @param n нижнее число
 * @param k верхнее число
 * @return long long int 
 */
long long int combination(int n, int k);

/**
 * @brief checks if number is prime
 * 
 * @param n number to check
 * @return 1 if number is prime, 0 if isn't
 */
int is_prime(int n);

/**
 * @brief Get the N_th prime number on
 * 
 * @param n number of prime number.........
 * @return prime number of N_th position
 */
int resheto(int n);

/**
 * @brief returns amount of digits in number
 * 
 * @param number 
 * @return char 
 */
char number_digits_amount(long long int number);

/**
 * @brief swaps values of a and b
 * 
 * @param a 
 * @param b 
 */
void swap_numbers(int* a, int* b);

#endif
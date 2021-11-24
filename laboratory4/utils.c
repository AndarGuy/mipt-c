#include "utils.h"

int gcd(int n, int n1) {
	while(n != n1) {
		if (n > n1) n = n - n1;
		else n1 = n1 - n;
	}
	return n;
}

int fac(int n) {
	if(n == 1) {
		return 1;
	} else {
		return n * fac(n - 1);
	}
}

long int power(long int x, long int n) {
    if (n == 0)
        return 1;
    else if (n == 1)
        return x;
    else if (n % 2 == 0 )
        return power(x * x, n / 2);
    else
        return power(x * x, n / 2) * x;
}

long long int combination(int n, int k) {
    if (k == 0 || k == n) return 1;
    return combination(n - 1, k - 1) * n / k;
}

int is_prime(int n) {
	int flag = 0;
	int i = 0;

	for (i = 2; i * i <= n; i++) {
		if (n % i == 0)
			flag++;
	}
	
	return (flag == 0) ? 1 : 0;
}

int resheto(int n) {
	int schet = 1, cur = 3;
	if (n == 1) return 2;
	while (schet != n) {
		if (is_prime(cur)) {
			schet++;
		}
		cur += 2;
	}
	return cur - 2;
}

char number_digits_amount(long long int number) {
	int count = 0;
	while (number != 0) {
    	count++;
    	number /= 10;
	}
	return count;
}

void swap_numbers(int* a, int* b) {
	int swaper = *a;
	*a = *b;
	*b = swaper;
	return;
}
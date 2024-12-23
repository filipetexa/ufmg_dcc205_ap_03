#include "operations.h"

// Implementação recursiva de fatorial
unsigned long long factorial_recursive(unsigned int n) {
    if (n == 0)
        return 1;
    else
        return n * factorial_recursive(n - 1);
}

// Implementação iterativa de fatorial
unsigned long long factorial_iterative(unsigned int n) {
    unsigned long long result = 1;
    for (unsigned int i = 2; i <= n; i++)
        result *= i;
    return result;
}

// Implementação recursiva de Fibonacci
unsigned long long fibonacci_recursive(unsigned int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

// Implementação iterativa de Fibonacci
unsigned long long fibonacci_iterative(unsigned int n) {
    unsigned long long a = 0, b = 1, c;
    if (n == 0)
        return a;
    for (unsigned int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if a number is prime
bool is_prime(int num)
{
    if (num <= 1)
        return false;
    if (num == 2)
        return true;
    if (num % 2 == 0)
        return false;
    for (int i = 3; i * i <= num; i += 2)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

// Program 1: Print all prime numbers up to N
void print_primes(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (is_prime(i))
        {
            printf("%d ", i);
        }
    }
    printf("\n");
}

// Program 2: Print the prime factored form of N
void prime_factors(int n)
{
    printf("%d = ", n);
    for (int i = 2; i <= n; i++)
    {
        while (is_prime(i) && n % i == 0)
        {
            printf("%d ", i);
            n /= i;
            if (n > 1)
                printf("* ");
        }
    }
    printf("\n");
}

// Program 3: Multiply two signed integers without using "*"
int multiply(int a, int b)
{
    int result = 0;
    bool neg = (a < 0 && b > 0) || (a > 0 && b < 0); // Check if result should be negative
    a = abs(a);
    b = abs(b);
    for (int i = 0; i < b; i++)
    {
        result += a;
    }
    return neg ? -result : result;
}

// Program 4: Divide two signed integers without using "/"
int divide(int a, int b)
{
    if (b == 0)
    {
        printf("Error!: Division by zero.\n");
        exit(1);
    }
    int result = 0;
    bool neg = (a < 0 && b > 0) || (a > 0 && b < 0); // Check if result should be negative
    a = abs(a);
    b = abs(b);
    while (a >= b)
    {
        a -= b;
        result++;
    }
    return neg ? -result : result;
}

// Program 5: Implementation of atoi function
int atoi(const char *str)
{
    int result = 0;
    bool neg = false;
    if (*str == '-')
    {
        neg = true;
        str++;
    }
    while (*str >= '0' && *str <= '9')
    {
        result = result * 10 + (*str - '0');
        str++;
    }
    return neg ? -result : result;
}

// Program 6: Sort and print a sequence of numbers
void sort_and_print(int argc, char *argv[])
{
    if (argc > 21)
    {
        printf("Warning!: There are too many numbers.\n");
        return;
    }
    int numbers[20];
    for (int i = 1; i < argc; i++)
    {
        numbers[i - 1] = atoi(argv[i]);
    }
    // Simple bubble sort
    for (int i = 0; i < argc - 2; i++)
    {
        for (int j = 0; j < argc - 2 - i; j++)
        {
            if (numbers[j] > numbers[j + 1])
            {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < argc - 1; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage!: gcc -o 01 01.c\n");
        printf("Usage!: ./01 [numbers]\n");
        return 1;
    }
    int n = atoi(argv[1]);
    printf("Prime numbers           : ");
    print_primes(n);
    printf("Prime factored          : ");
    prime_factors(n);
    printf("Multiplication          : %d * 3 = %d\n", n, multiply(n, 3));
    printf("Division                : %d / 3 = %d\n", n, divide(n, 3));
    printf("Sorted numbers sequence : ");
    sort_and_print(argc, argv);
    return 0;
}
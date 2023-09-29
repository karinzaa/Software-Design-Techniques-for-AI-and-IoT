import math
import sys

# Function to check if a number is prime
def is_prime(num):
    if num <= 1:
        return False
    if num == 2:
        return True
    if num % 2 == 0:
        return False
    for i in range(3, int(math.sqrt(num)) + 1, 2):
        if num % i == 0:
            return False
    return True

# Program 1: Print all prime numbers up to N
def print_primes(n):
    for i in range(2, n + 1):
        if is_prime(i):
            print(i, end=' ')
    print()

# Program 2: Print the prime factored form of N
def prime_factors(n):
    print(f'{n} = ', end='')
    i = 2
    while i <= n:
        if is_prime(i) and n % i == 0:
            print(i, end=' ')
            n //= i
            if n > 1:
                print('* ', end='')
        else:
            i += 1
    print()

# Program 3: Multiply two signed integers without using "*"
def multiply(a, b):
    result = 0
    neg = (a < 0 and b > 0) or (a > 0 and b < 0)  # Check if result should be negative
    a = abs(a)
    b = abs(b)
    for i in range(b):
        result += a
    return -result if neg else result

# Program 4: Divide two signed integers without using "/"
def divide(a, b):
    if b == 0:
        raise ValueError("Error!: Division by zero.")
    result = 0
    neg = (a < 0 and b > 0) or (a > 0 and b < 0)  # Check if result should be negative
    a = abs(a)
    b = abs(b)
    while a >= b:
        a -= b
        result += 1
    return -result if neg else result

# Program 5: Implementation of atoi function
def atoi(str):
    result = 0
    neg = False
    if str[0] == '-':
        neg = True
        str = str[1:]
    for char in str:
        if '0' <= char <= '9':
            result = result * 10 + int(char)
        else:
            break
    return -result if neg else result

# Program 6: Sort and print a sequence of numbers
def sort_and_print(args):
    if len(args) > 21:
        print("Warning!: There are too many numbers.")
        return
    numbers = [atoi(arg) for arg in args[1:]]
    numbers.sort()
    print(' '.join(map(str, numbers)))

# Main function
def main(args):
    if len(args) < 2:
        print("Usage!: python 01.py [numbers]")
        return
    n = atoi(args[1])
    print("Prime numbers           : ", end='')
    print_primes(n)
    print("Prime factored          : ", end='')
    prime_factors(n)
    print(f"Multiplication          : {n} * 3 = {multiply(n, 3)}")
    print(f"Division                : {n} / 3 = {divide(n, 3)}")
    print("Sorted numbers sequence : ", end='')
    sort_and_print(args)

# Call main function
if __name__ == '__main__':
    main(sys.argv)

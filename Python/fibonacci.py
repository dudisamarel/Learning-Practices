# 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, …
def fibonacci(n):
    if (n <= 1):
        return n
    return fibonacci(n-1) + fibonacci(n-2)


def fibonacciPrint(n):
    if (n == 0):
        print(n)
    else:
        print(fibonacci(n))
        fibonacciPrint(n-1)

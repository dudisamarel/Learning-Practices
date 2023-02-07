# 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, …


def fibonacci(n):
    if n <= 0:
        return []
    elif n == 1:
        return [0]
    elif n == 2:
        print(0)
        print(1)
        return [0, 1]
    else:
        fib_list = fibonacci(n-1)
        result = fib_list[-1] + fib_list[-2]
        print(result)
        fib_list.append(result)
        return fib_list

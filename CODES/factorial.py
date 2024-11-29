def factorial(n):
    if(n==0):
        return 1
    result = 1
    for i in range(1, n + 1):  
        result = result * i
    return result

number = int(input("Enter a non-negative integer: "))

result = factorial(number)
print(f"The factorial of {number} is: {result}")

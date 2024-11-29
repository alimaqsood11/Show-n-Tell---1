def gcd(a, b):
    if a == 0:
        return b
    return gcd(b % a, a)

num1 = int(input("Enter the first non-negative integer (a): "))
num2 = int(input("Enter the second non-negative integer (b): "))

result = gcd(num1, num2)
print(f"The GCD of {num1} and {num2} is: {result}")

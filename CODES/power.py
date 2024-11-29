def power(n, a):
    if a == 0:
        return 1
    return n * power(n, a - 1)

base = int(input("Enter the base (n): "))
exponent = int(input("Enter the exponent (a): "))

result = power(base, exponent)
print(f"{base} raised to the power of {exponent} is: {result}")

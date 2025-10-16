def Fibonacci(num):
    if num <= 1:
        return num
    else:
        return Fibonacci(num - 1) + Fibonacci(num - 2)

limit = int(input("Enter the Limit: "))
print("Fibonacci Series: ", end=" ")
for i in range(limit):
    print(Fibonacci(i), end=" ")
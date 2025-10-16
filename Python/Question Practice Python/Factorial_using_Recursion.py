def Factorial(num):
    if num == 0 or num == 1:
        return 1
    else:
        return num * Factorial(num-1)

num = int(input("Enter the Number: "))
fact = Factorial(num)
print(f"factorial  is {fact}")
user = input("Enter the number type (Binary or Decimal): ")

if (user == "binary"):
    user1 = input("Enter the number: ")
    ans = 0

    for i in range(len(user1)):
        ans += (2**i)*(int(user1)%10)
        user1 = int(user1)
        user1 //= 10

    print(f"Number in Decimal is {ans}")

elif (user == "decimal"):
    user1 = int(input("Enter the number: "))
    ans = ""

    while (user1 != 1):
        ans += str(user1%2)
        user1 //= 2
        if (user1 == 1):
            ans += "1"

    ans = int(ans[::-1])
    print(f"Number in Binary is {ans}")

else:
    print("Didn't get that....")
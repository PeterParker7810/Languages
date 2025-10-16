user = input("Enter the number: ")
list1 = []

for i in range(len(user)):
    list1 += [int(user[i])**len(user),]

if (sum(list1) == int(user)):
    print(f"Yes...{user} is an Armstrong Number")

else:
    print(f"No...{user} is not an Armstrong Number")
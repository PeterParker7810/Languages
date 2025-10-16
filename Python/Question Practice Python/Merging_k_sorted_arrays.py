user = int(input("Enter no of Lists: "))
list1 = []
list3 = []

for i in range(user):
    print(f"\nFor List-{i+1}")
    list2 = []
    user1 = int(input("Enter the no of elements: "))
    for j in range(user1):
        user2 = int(input("Enter the element: "))
        list2 += [user2,]

    list2.sort()
    list1 += [list2,]

    for k in range(len(list2)):
        list3 += [list2[k],]

print("\nInputted List:")
print(list1)

list3.sort()
print("\nOutput List:")
print(list3)
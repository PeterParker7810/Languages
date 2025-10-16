#Inputting Elements for Array-1
user1 = int(input("Enter no of elements for Array-1: "))
list1 = []

print("For Array-1:")
for i in range(user1):
    user2 = int(input("Enter the element: "))
    list1 += [user2,]
    
#Inputting Elements for Array-2
user3 = int(input("\nEnter no of elements for Array-2: "))
list2 = []

print("For Array-2:")
for i in range(user3):
    user4 = int(input("Enter the element: "))
    list2 += [user4,]

# Merging and Sorting Arrays
list3 = []

print("\nElements for Array-1:")
for i in range(user1):
    print(list1[i],end=" ")
    list3 += [list1[i],]
    
print("\nElements for Array-2:")
for i in range(user3):
    print(list2[i],end=" ")
    list3 += [list2[i],]

list3.sort()
print("\nElements for Merged Array:")
for i in range(user1 + user3):
    print(list3[i],end=" ")

print("\nMedian of Sorted Arrays: ",end="")
if (((user1+user3)-1)%2 == 0):
    print(list3[((user1+user3)-1)//2])
else:
    print((list3[((user1+user3)//2)-1] + list3[((user1+user3)//2)])/2)
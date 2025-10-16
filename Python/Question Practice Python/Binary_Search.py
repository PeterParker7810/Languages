def BinarySearch(arr, find):
    start, end = 0, len(arr)-1

    while start <= end:
        mid = start + (end - start) // 2
        if (arr[mid] == find):
            return mid
        elif (arr[mid] < find):
            start = mid + 1
        else:
            end = mid - 1  
    return -1

list1 = []
user = int(input("Enter the no of Elements: "))
for i in range(user):
    user1 = int(input("Enter the Element: "))
    list1.append(user1)

list1.sort()
user2 = int(input("\nEnter the Element to Find: "))
result = BinarySearch(list1, user2)

if result == -1:
    print("Element not Found")
else:
    print(f"Element Found at Index {result}")
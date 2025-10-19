def SubSequence(index, arr, sub_seq):
    if index == len(arr):
        return [sub_seq]
    
    # Include the current element
    with_current = SubSequence(index + 1, arr, sub_seq + [arr[index]])

    # Exclude the current element
    without_current = SubSequence(index + 1, arr, sub_seq)
    return with_current + without_current

arr = []
size = int(input("Enter the no of Elements: "))
for i in range(size):
    element = int(input("Enter the Element: "))
    arr.append(element)

print("\nOriginal Array: ")
print(arr)

check = int(input("Enter the number to check: "))
result = SubSequence(0, arr, [])

found = []
for i in range(len(result)):
    if sum(result[i]) == check:
        found.append(1)
    else:
        found.append(0)

if sum(found) == 0:
    print("No Pairs Found...")

else:
    for i in range(len(result)):
        if found[i] == 1:
            print(f"The Numbers {result[i]} add upto {check}")
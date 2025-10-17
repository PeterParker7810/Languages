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
    element = int(input("Enter Element: "))
    arr.append(element)

print("\nOriginal Array: ")
for i in range(size):
    print(arr[i], end=" ")

print("\n\nAll Subsequences: ")
result = SubSequence(0, arr, [])
for subseq in result:
    print(subseq)
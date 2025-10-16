limit = int(input("Enter the limit: "))
list1 = [] 

# Making Lists
for i in range(1,limit+1):
    list1 += [i,]

list2 = list1[::-1]

# Pattern-1
print("\nPattern-1")
for i in list1:
    for j in range(i):
        print("*",end=" ")
    print("")

# Pattern-2
print("\nPattern-2:")
for i in list2:
    for j in range(list2[i-1]):
        if (j > 0):
            print(end="  ")
    for k in range(i):
        print("*",end=" ")
    print("")

# Pattern-3
print("\nPattern-3")
for i in list2:
    for j in range(i):
        print("*",end=" ")
    print("")

# Pattern-4
print("\nPattern-4:")
for i in list1:
    for j in range(list2[i-1]):
        if (j > 0):
            print(end="  ")       
    for k in range(i):
        print("*",end=" ")
    print("")

# Pattern-5
print("\nPattern-5:")
for i in list1:
    if (i != limit):
        for j in range(i):
            print("*",end=" ")
        print("")
for i in list2:
    for j in range(i):
        print("*",end=" ")
    print("")

# Pattern-6
print("\nPattern-6:")
for i in list1:
    if (i != limit):
        for j in range(list2[i-1]):
            if (j > 0):
                print(end="  ")
            
        for k in range(i):
            print("*",end=" ")
        print("")

for i in list2:
    for j in range(list2[i-1]):
        if (j > 0):
            print(end="  ")
    for k in range(i):
        print("*",end=" ")
    print("")

# Pattern-7
print("\nPattern-7:")
for i in list1:
    if (i != limit):
        for j in range(list2[i-1]):
            if (j > 0):
                print(end=" ")
            
        for k in range(i):
            print("*",end=" ")
        print("")

for i in list2:
    for j in range(list2[i-1]):
        if (j > 0):
            print(end=" ")
    for k in range(i):
        print("*",end=" ")
    print("")

# Pattern-8
print("\nPattern-8:")
temp = 1
for i in range(1,(limit*2)+1):
    if (i%2 == 0):
        temp1 = limit
        while temp1 != i//2:
            print(end="  ")
            temp1 -= 1
    else:
        temp1 = limit
        while temp1 != (i+1)//2:
            print(end="  ")
            temp1 -= 1

    for k in range(temp):
        print("*",end=" ")
    print("")
    if (i%2 == 0):
        temp += 2
    
# Pattern-9
print("\nPattern-9:")
for i in range(limit-1):
    for j in range(list1[i]):
        if (j > 0):
            print(end=" ")
    for k in range(list2[i]):
        print("*",end=" ")
    print("")

for i in list1:
    for j in range(list2[i-1]):
        if (j > 0):
            print(end=" ")
        
    for k in range(i):
        print("*",end=" ")
    print("")

# Pattern-10
print("\nPattern-10:")
for i in list1:
    if (i != limit):
        for j in range(list2[i-1]):
            if (j > 0):
                print(end=" ")
            
        for k in range(i):
            if (k == 0 or k == i-1):
                print("*",end=" ")
            else:
                print(end="  ")
        print("")

for i in list2:
    for j in range(list2[i-1]):
        if (j > 0):
            print(end=" ")
    for k in range(i):
        if (k == 0 or k == i-1):
            print("*",end=" ")
        else:
            print(end="  ")
    print("")

# Pattern-11
print("\nPattern-11:")
for i in list1:
    for j in range(limit):
        if (i == 1 or i == limit):
            print("*",end=" ")
        else:
            if (j == 0 or j == limit-1):
                print("*",end=" ")
            else:
                print(end="  ")
    print("")

# Pattern-12
print("\nPattern-12:")
for i in list1:
    for j in range(list2[i-1]):
        if (j > 0):
            print(end=" ")
        
    for k in range(i):
        if (i == limit):
            print("*",end=" ")

        else:
            if (k == 0 or k == i-1):
                print("*",end=" ")
            else:
                print(end="  ")
    print("")

# Pattern-13
print("\nPattern-13:")
for i in list2:
    for j in range(list2[i-1]):
        if (j > 0):
            print(end=" ")
    for k in range(i):
        if (i == limit):
            print("*",end=" ")
        else:
            if (k == 0 or k == i-1):
                print("*",end=" ")
            else:
                print(end="  ")
    print("")

# Pattern-14
print("\nPattern-14")
for i in list1:
    for j in range(i+1):
        if (j > 1):
            print(end="  ")
    for k in list1:
        print("*",end=" ")
    print("")

# Pattern-15
print("\nPattern-15:")
for i in list2:
    if (i != 1):
        for j in range(list2[i-1]):
            if (j > 0):
                print(end=" ")
        for k in range(i):
            if (i == limit):
                print("*",end=" ");
            else:
                if (k == 0 or k == i-1):
                    print("*",end=" ")
                else:
                    print(end="  ")
        print("")

for i in list1:
    for j in range(list2[i-1]):
        if (j > 0):
            print(end=" ")
        
    for k in range(i):
        if (i == limit):
            print("*",end=" ")

        else:
            if (k == 0 or k == i-1):
                print("*",end=" ")
            else:
                print(end="  ")
    print("")
user = input("Enter the String: ")
user1 = input("Enter the Pattern: ")
list1 = []
try:
    temp = ""
    for i in range(len(user1)):
        if (user1[i] == "."):
            list1 += [i+1,]
            temp += user1[i+1]

        else:
            temp += user1[i]

    user1 = temp

    if (len(list1) == 0):
        temp = ""
        limit = len(user)
        for i in range(limit):
            temp += user1[:user1.index("*")]
        
        user1 = user1.replace("*", temp)
    
    else:
        temp = ""
        limit = len(user)
        for i in range(limit):
            temp += user1[list1[-1]:user1.index("*")]
        
        user1 = user1.replace("*", temp)

    user1 = user1[:len(user)]
    
except Exception as a:
    pass

if (user == user1):
    print("Yess....String Matches the Pattern")
    
else:
    print("No....String does not Matches the Pattern")
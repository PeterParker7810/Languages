# STACK Functions
def Display(s):
    if (len(s) == 0):
        print("\nEmpty Stack")
    else:
        print("\nDisplaying Stack Elements:")
        for i in range(len(s)):
            print(s[i],end=" ")
        print()

def Pop(s):
    global size
    if (len(s) == 0):
        print("\nStack Underflow")
    else:
        print(f"\nPopped out {s[-1]}")
        s.pop()
        size += 1
    
def Push(s,elem):
    global size
    if (size > 0):
        print(f"\nPushing {elem} to Stack")
        s.append(elem)
        size -= 1
    else:
        print("\nStack Overflow")

def isEmpty(s):
    if (len(s) != 0):
        print("\nStack is not Empty")
    else:
        print("\nStack is Empty")

def isFull():
    global size
    if (size > 0):
        print("\nStack is not Full")
    else:
        print("\nStack is Full")

def Count(s):
    print(f"\nNumber of items in Stack is {len(s)}")

def Peek(s,i):
    try:
        print(f"\nElement at index {i} is {s[i]}")
    
    except Exception as a:
        print("\nCouldn't Find an Element")

def Change(s,elem,i):
    try:
        s[i] = elem
        print(f"\nChanged the Element to {elem}")

    except Exception as a:
        print("\nEnter Valid Index")

# Operations on STACK
size = int(input("Enter the size of Stack: "))
stack = []

print("\nStack Functions:\npush\npop\ndisplay\nisempty\nisfull\npeek\ncount\nchange\n")
while True:
    user = input("\nEnter Stack Function: ")

    if (user == "push"):
        user1 = int(input("Enter Element to be Pushed: "))
        Push(stack,user1)

    elif (user == "pop"):
        Pop(stack)

    elif (user == "display"):
        Display(stack)

    elif (user == "isempty"):
        isEmpty(stack)

    elif (user == "isfull"):
        isFull()

    elif (user == "count"):
        Count(stack)

    elif (user == "peek"):
        user1 = int(input("Enter the Index: "))
        Peek(stack,user1)

    elif (user == "change"):
        user1 = int(input("Enter the Element: "))
        user2 = int(input("Enter the Index: "))
        Change(stack,user1,user2)

    else:
        print("\nEnter Valid Stack Function")
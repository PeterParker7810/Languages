# Queeue Functions
def Enqueue(arr,elem):
    global size
    if (size > 0):
        print(f"\nEnqueued {elem} to Queue")
        arr += [elem,]
        size -= 1
    else:
        print("\nQueue Overflow")

def Display(arr):
    print("\nDisplaying Queue Elements:")
    for i in range(len(arr)):
        print(arr[i],end=" ")
    print()

def isFull(arr):
    global size
    if (size == 0):
        print("\nQueue is Full")
    else:
        print("\nQueue is not FUll")

def isEmpty(arr):
    if (len(arr) == 0):
        print("\nQueue is Empty")
    else:
        print("\nQueue is not Empty")

# Queue Operations
size = int(input("Enter the size of Queue: "))
queue = []

print("\nQueue Functions:\nenqueue\ndequeue\ndisplay\ncount\nisfull\nisempty")
while True:
    user = input("\nEnter Queue Function: ")

    if (user == "enqueue"):
        user1 = int(input("Enter the Element: "))
        Enqueue(queue,user1)

    elif (user == "display"):
        Display(queue)

    elif (user == "dequeue"):
        if (len(queue) == 0):
            print("\nQueue Underflow")
        else:
            print(f"\nDequeued {queue[0]}")
            del queue[0]
            size += 1
        
    elif (user == "isfull"):
        isFull(queue)

    elif (user == "isempty"):
        isEmpty(queue)

    elif (user == "count"):
        print(f"\nNo of items in queue is {len(queue)}")

    else:
        print("\nEnter Valid Queue Function")
class CircularQueue:
    round = 0
    Queue = []

    def __init__(self,limit):
        self.size = limit

    def Enqueue(self,elem):
        if (self.round == 0):
            if ((self.size - len(self.Queue)) == 0):
                print("\nQueue Overflow")
                self.round += 1
            else:
                print(f"\nEnqueued {elem} to Queue")
                self.Queue += [elem,]

        else:
            if ((self.size - len(self.Queue)) == 0):
                print("\nQueue Overflow")
            else:
                print(f"\nEnqueued {elem} to Queue")
                self.Queue = self.Queue[::-1]
                self.Queue += [elem]
                self.Queue = self.Queue[::-1]

    def Display(self):
        print("\nDisplaying Queue Elements:")
        for i in range(len(self.Queue)):
            print(self.Queue[i],end=" ")
        print()

    def Dequeue(self):
        if (len(self.Queue) == 0):
            print("\nQueue Underflow")

        else:
            if ((self.size - len(self.Queue)) == 0):
                self.round += 1
            
            print(f"\nDequeued {self.Queue[0]}")
            del self.Queue[0]

    def Peek(self):
        try:
            print(f"Peeking {self.Queue[0]}")
        except Exception as a:
            print("\n")

    def isFull(self):
        if ((self.size - len(self.Queue)) == 0):
            print("\nQueue is Full")
        else:
            print("\nQueue is not Full")

    def isEmpty(self):
        if (len(self.Queue) == 0):
            print("\nQueue is Empty")
        else:
            print("\nQueue is not Empty")


user = int(input("Enter the size: "))
queue = CircularQueue(user)

print("\nQueue Functions:\nenqueue\ndequeue\npeek\ndisplay\nisfull\nisempty")

while True:
    user1 = input("\nEnter Queue Function: ")

    if (user1 == "enqueue"):
        val = int(input("Enter the Element: "))
        queue.Enqueue(val)

    elif (user1 == "display"):
        queue.Display()

    elif (user1 == "dequeue"):
        queue.Dequeue()

    elif (user1 == "peek"):
        queue.Peek()
    
    elif (user1 == "isfull"):
        queue.isFull()

    elif (user1 == "isempty"):
        queue.isEmpty()
    
    else:
        print("\nEnter Valid Queue Function")
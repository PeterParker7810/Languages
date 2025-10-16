class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def insertAtEnd(self, val):
        newNode = Node(val)
        if self.head is None:
            self.head = newNode
            print(f"Inserted head node with value {newNode.data}")
            return
        
        temp = self.head
        while temp.next is not None:
            temp = temp.next

        temp.next = newNode
        print(f"Inserted new node with value {newNode.data}")

    def insertAtBeginning(self, val):
        newNode = Node(val)
        newNode.next = self.head
        self.head = newNode
        print(f"Inserted head node with value {newNode.data}")

    def deleteAtBeginning(self):
        if self.head is None:
            print("List is empty")
            return
        
        temp = self.head
        self.head = self.head.next
        print(f"Deleted node with value {temp.data}")
        del temp

    def deleteAtEnd(self):
        if self.head is None:
            print("List is empty")
            return
        
        if self.head.next is None:
            print(f"Deleted node with value {self.head.data}")
            del self.head
            self.head = None
            return
        
        temp = self.head
        while temp.next.next is not None:
            temp = temp.next

        toDelete = temp.next
        temp.next = None
        print(f"Deleted node with value {toDelete.data}")
        del toDelete

    def display(self):
        temp = self.head
        while temp is not None:
            print(f"{temp.data} -> ", end="")
            temp = temp.next

        print("NULL")

list = LinkedList()
print("Linked List Operations:")
print("1. Insert at end\n2. Insert at beginning\n3. Delete at beginning\n4. Delete at end\n5. Display")

while True:
    oper = int(input("\nEnter the Operation: "))
    if oper == 1:
        val = int(input("Enter the value to insert: "))
        list.insertAtEnd(val)
        
    elif oper == 2:
        val = int(input("Enter the value to insert: "))
        list.insertAtBeginning(val)
        
    elif oper == 3:
        list.deleteAtBeginning()
        
    elif oper == 4:
        list.deleteAtEnd()
        
    elif oper == 5:
        list.display()
        
    else:
        print("Invalid Operation")
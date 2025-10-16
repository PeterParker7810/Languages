employee=[]
y="c"
while(y=='c'):
    print("1.PUSH")
    print("2.POP")
    print("3.DISPLAY")
    ch=int(input("enter your choice:"))
    if ch==1:
        e_no=int(input("enter the employee number"))
        e_name=input("enter the name:")
        emp=(e_no,e_name)
        employee.append(emp)
    elif ch==2:
        if (employee==[]):
            print("stack is empty")
        else:
            e_no,e_name=employee.pop()
            print("deleted item is:",e_no,e_name)
    elif ch==3:
        i=len(employee)
        while(i>0):
            print(employee[i-1])
            i=i-1
    else:
        print("invalid choice")
y=input("do you wanna continue?(y or n)")
    
    

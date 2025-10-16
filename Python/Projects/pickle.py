import pickle
while True:
    print("1. Add Record 2. Display Record 3. Display Record  4.Exit")
    ch=int(input("Enter Your Choice:"))
    l=[]
    if ch==1:
        f=open("shoes.dat","ab")
        s_id=int(input("Enter Shoes ID:"))
        name=input("Enter Shoes Name:")
        typ=input("Enter Shoes Type:")
        brand=input("Enter Brand Name:")
        price=int(input("Enter shoes price: "))
        l=[s_id,name,typ,brand]
        pickle.dump(l,f)
        print("Data Record Successfully")
        f.close()
    elif ch==2:
        f=open("shoes.dat","rb")
        while True:
            try:
                dt=pickle.load(f)
                print(dt)
            except EOFError:
                break
                f.close()
    elif ch==3:
        si=int(input("Enter Shoes ID:"))
        f=open("shoes.dat","ab")
        fl=False
        while True:
            try:
                dt=pickle.load(f)
                for i in dt:
                    if i==si:
                        fl=True
                        print("Record Found")
                        print("ID:",dt[0])
                        print("name:",dt[1])
                        print("type:",dt[2])
                        print("brand:",dt[3])
                        print("price:",dt[4])
            except EOFError:
                break
        if i==si:
            fl==False
            f.close()
    elif ch==4:
        break
        print("Invalid Choice")
                        

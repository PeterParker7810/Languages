import time

def Ebill():
    import random
    
    global user3
    ran = random.randint(0,1)
    cal = ['January','February','March','April','May','June','July','August','September','October','November','December']
    bill = random.randint(100,10000)
    month = random.choice(cal)
    if ran == 0:
        print(f'No pending bills for Mr/Ms {user3}')

    else:
        print(f'An amount of {bill} rupees is pending for the month of {month}')
        while True:
            user4 = input('Do you wish to continue to payment? ')
            if user4 == 'no':
                time.sleep(1)
                print('As you say...')
                break

            elif user4 == 'yes':
                print('Choose Payment Method:\nPayTM\nPhonePe\nOther')
                user5 = input('')
                print('Loading.....')
                time.sleep(2)
                while True:
                    user6 = int(input('Enter Amount: '))
                    if user6 == bill:
                        print('Transaction in process....')
                        time.sleep(2)
                        print('Transaction Successfull')
                        time.sleep(2)
                        break

                    else:
                        time.sleep(2)
                        print('Enter the correct amount')

            else:
                print('Enter yes or no')
            
def Gbill():
    import random
    
    global user6
    ran = random.randint(0,1)
    cal = ['January','February','March','April','May','June','July','August','September','October','November','December']
    bill = random.randint(100,10000)
    month = random.choice(cal)
    if ran == 0:
        print(f'No pending bills for Mr/Ms {user6}')

    else:
        print(f'An amount of {bill} rupees is pending for the month of {month}')
        while True:
            user4 = input('Do you wish to continue to payment? ')
            if user4 == 'no':
                time.sleep(1)
                print('As you say...')
                break

            elif user4 == 'yes':
                print('Choose Payment Method:\nPayTM\nPhonePe\nOther')
                user5 = input('')
                print('Loading.....')
                time.sleep(2)
                while True:
                    user6 = int(input('Enter Amount: '))
                    if user6 == bill:
                        print('Transaction in process....')
                        time.sleep(2)
                        print('Transaction Successfull')
                        time.sleep(2)
                        break

                    else:
                        time.sleep(2)
                        print('Enter the correct amount')

            else:
                print('Enter yes or no')

def Rbill():
    import random
    
    user7 = input('Enter your SIM card company name: ')
    rep = []
    while True:
        user8 = input('Enter Mobile Number: ')
        if len(user8) != 10:
            print('Mobile Number Invalid...')

        elif user8 in rep and user7 in rep:
            print(f'Bill already filled for Mobile Number {user8}')
            break

        else:
            print(f'loading details......')
            time.sleep(2)
            idn = random.randint(10000000000,100000000000)
            print(f'ID number for Mobile Number {user8} is {idn}')
            rech = random.randint(0,1)
            if rech == 0:
                print(f'No bill is pending for ID number {idn}')
                break

            elif rech == 1:
                bill = random.randint(100,1000)
                print(f'An amount of {bill} rupees is pending for Mobile Number {user8}')
                time.sleep(2)
                user9 = input('Enter payment method: ')
                print('PayTM\nPhonePe\nother')
                print('Loading...')
                time.sleep(2)
                user10 = input(f'Continue payment of {bill} rupees? ')
                if user10 == 'no':
                    print('Cancelling Transaction....')
                    time.sleep(2)
                    break

                elif user10 == 'yes':
                    print('Transaction in progress....')
                    time.sleep(2)
                    print('Transaction complete')
                    break
                
    rep += [user8,user7,]       
        
def Cal():
    import calendar

    Year = int(input('Enter the year: '))
    Month = int(input('Enter the month: '))
    print('Loading...')
    time.sleep(2)
    print(calendar.month(Year,Month))

def Open():
    try:
        user11 = input('Enter file name(without extension): ')
        f = open(f'{user11}.txt')
        c = f.read()
        print(c)
        f.close()

    except Exception as a:
        print(f'No file named {user11} found')

def New():
    user12 = input('Name the file: ')
    f = open(f'{user12}.txt','w')
    print('FIle renamed.....')
    user13 = input('')
    f.write(user13)
    f.close()

def GTN():
    import random
    
    no = random.randint(1,100)
    guess = 5
    final = guess
    while guess > 0:
        user14 = int(input('\nGuess the number: '))
        if user14 > no:
            print('Nope...the guesses number is GREATER than the random number')
            guess -= 1

        elif user14 < no:
            print('Nope...the guesses number is LESS than the random number')
            guess -= 1

        elif user14 == no:
            print(f'CONGRATULATIONS! The random number is {no}')
            break
        
    if guess == 0:
        time.sleep(2)
        print(f'\nYOU LOST :(\nThe Number was: {no}')
        print(f'\nNo. of Guesses taken: {final-guess}')

    time.sleep(2)
    print('Press any key to exit the game...')
    user15 = input('')           

def Data():
    import mysql.connector as my

    user = input('Enter Database name: ')
    user2 = input('Enter Password: ')

    mydb = my.connect(host = 'localhost' , user = 'root' , passwd = f'{user2}' , database = f'{user}')
    cursor = mydb.cursor()
    while True:
        user3 = input('Enter the Query:\n')
        cursor.execute(f'{user3}')
        print('\nQuery ran successfully...\n')
        for i in cursor:
            print(i)

        user4 = input('Wanna type more queries? ')
        if user4 == 'no':
            break
            
print('Hello friend! I am the owner of this Cyber Cafe')
time.sleep(2)
user = input('My name is Peter Parker, what can i call you? ')
time.sleep(2)
print(f'Nice to meet you {user}')
time.sleep(2)

Elimit = 0
Glimit = 0

while True:
    print('\nHow may i help you?')
    time.sleep(2)
    print("Type 'Ebill' for Electricity Bills\nType 'Gbill' for Pipeline Bills\nType 'Recharge' for Mobile Recharge\nType 'GTN' for playing Guess the number\nType 'Note' to open NotePad\nType 'Calendar' to open Calendar\nType 'Data' for Database\nType 'Exit' to exit the cafe")

    user2 = input('')
    if user2 == 'Ebill':
        if Elimit == 0:
            print('\nWelcome to BSES Bill Payment Page')
            time.sleep(2)
            user3 = input('Bill is on who\'s name? ')
            print('Checking DataBase....')
            time.sleep(2)
            Ebill()
            Elimit = 1

        else:
            print('No Pending ELectricity Bill....')

    elif user2 == 'Gbill':
        if Glimit == 0:
            print('\nWelcome to IGL Bill Payment Page')
            time.sleep(2)
            user6 = input('Bill is on who\'s name? ')
            print('Checking DataBase....')
            time.sleep(2)
            Gbill()
            Glimit = 1

        else:
            print('No Pending Pipeline Bill....')

    elif user2 == 'Recharge':
        print('\nOpening page....')
        time.sleep(2)
        Rbill()

    elif user2 == 'Calendar':
        print('\n')
        Cal()

    elif user2 == 'Note':
        while True:
            user10 = input('\nEnter O for opening existing file or N for new file: ')
            if user10.lower() == 'o':
                Open()
                break

            elif user10.lower() == 'n':
                New()
                print('Autosave complete...')
                break

    elif user2 == 'GTN':
        print('\nLoading Game.....')
        time.sleep(2)
        print('Read the instructions carefully')
        time.sleep(2)
        print('There is a random unknown number between 1 and 100')
        time.sleep(2)
        print('You have 5 Guesses....')
        time.sleep(2)
        print('Starting game...')
        time.sleep(2)
        GTN()

    elif user2 == 'Exit':
        print(f'Thanks for your visit {user}')
        break

    elif user2 == 'Data':
        print('\nLoading setup...')
        time.sleep(2)
        Data()

    else:
        print('Sorry i didn\'t get that :(')
# Importing all the important modules
import time
import wikipedia
import pyttsx3
import pyautogui

# Setting Text to Speech engine
engine = pyttsx3.init()
rate = engine.getProperty('rate')
voices = engine.getProperty('voices')

# Setting Text to Speech properties
engine.setProperty('rate',150)
engine.setProperty('voice',voices[1].id)

# System Initializing.....
print("Hello Peter")
engine.say("Hello Peter")
engine.runAndWait()

print("i am your AI Assistant")
engine.say("i am your AI Assistant")
engine.runAndWait()

# Commands
commands = ['open','wikipedia','exit','close','type']

# Response
response = 0
while response%2 == 0:
    print("You can type the following commands.....")
    engine.say("You can type the following commands")
    print(f'\n{commands}')
    engine.runAndWait()

    user = input('Enter the command: ')

    # Wikipedia Commands
    if user.lower() in commands:
        response += 1
        if user.lower() == commands[1]:
            print("\nokay......Tell me what do you wanna search")
            engine.say("okay......Tell me what do you wanna search")
            engine.runAndWait()
            while True:
                user1 = input("Search: ")
                try:
                    out = wikipedia.summary(user1,sentences = 2)
                    time.sleep(2)
                    print(f"Here are some related searches about {user1}")
                    engine.say(f"Here are some related searches about {user1}")
                    engine.runAndWait()
                    print(wikipedia.search(user1))
                    time.sleep(2)

                    print(f"\nhere's what i found about {user1}")
                    engine.say(f"here's what i found about {user1}")
                    engine.runAndWait()
                    
                    print(f'\n{out}')
                    engine.say(out)
                    engine.runAndWait()

                    print("\nI hope the searched output was relevant to you....")
                    engine.say("I hope the searched output was relevant to you....")
                    engine.runAndWait()
                    response += 1
                    if response%2 == 0:
                        break

                    else:
                        pass

                except Exception as a:
                    print("oops.....i couldn't understand")
                    engine.say("oops.....i couldn't understand")
                    engine.runAndWait()

        # Opening Applications
        elif user.lower() == commands[0]:
            while True:
                print("\nOkay......tell me what do you wanna open")
                engine.say("Okay......tell me what do you wanna open")
                engine.runAndWait()
                user2 = input("Open: ")

                time.sleep(2)
                print(F"Opening {user2}")
                engine.say(f"Opening {user2}")
                engine.runAndWait()

                pyautogui.moveTo(700,1052,0.5)
                pyautogui.click()
                time.sleep(1)
                pyautogui.write(user2)
                pyautogui.moveTo(700,275,0.5)
                pyautogui.doubleClick()

                print(f"{user2} opened successfully....")
                engine.say(f"{user2} opened successfully....")
                engine.runAndWait()

                response += 1
                if response%2 == 0:
                    break

                else:
                    pass

        # Exiting the code
        elif user.lower() == commands[2]:
            print("I'm so glad to be useful for you........Goodbye")
            engine.say("I'm so glad to be useful for you........Goodbye")
            engine.runAndWait()

        # Closing VS Code
        elif user.lower() == commands[3]:
            print("Are you sure you wanna close the code editor?")
            engine.say("Are you sure you wanna close the code editor?")
            engine.runAndWait()
            user3 = input("y/n: ")
            while True:
                if user3.lower() == 'y':
                    print("Okay.......closing the code editor")
                    engine.say("Okay.......closing the code editor")
                    engine.runAndWait()
                    pyautogui.moveTo(1900,40,0.5)
                    pyautogui.click()

                else:
                    print("Okay.......Not closing the code editor")
                    engine.say("Okay.......Not closing the code editor")
                    engine.runAndWait()
                    response += 1
                    if response%2 == 0:
                        break

                    else:
                        pass
                        
        elif user.lower() == commands[4]:
            print("I can type something for you in notepad...........What should i type?")
            engine.say("I can type something for you in notepad...........What should i type?")
            engine.runAndWait()
            user4 = input("Type: ")
            list1 = user4.split()

            print("Okay......just a second")
            engine.say("Okay......just a second")
            engine.runAndWait()

            while True:
                pyautogui.moveTo(700,1052,2)
                pyautogui.click()
                time.sleep(1)
                pyautogui.write('notepad')
                pyautogui.moveTo(700,275,2)
                pyautogui.doubleClick()
                time.sleep(2)
                for i in range(len(list1)):
                     pyautogui.write(list1[i],)
                     pyautogui.hotkey('space')

                print("Done")
                engine.say("Done!!")
                engine.runAndWait()

                response += 1
                if response%2 == 0:
                    break

                else:
                    pass

    # Irrelevant Commands Handler
    else:
        print("\nSorry....I didn't get that")
        engine.say("Sorry....I didn't get that")
        engine.runAndWait()
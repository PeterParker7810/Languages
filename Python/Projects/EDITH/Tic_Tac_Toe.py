# Importing all the modules
import time
import random
import pyttsx3

# Setting Text to Speech engine
engine = pyttsx3.init()
rate = engine.getProperty('rate')
voices = engine.getProperty('voices')

# Setting Text to Speech properties
engine.setProperty('rate',150)
engine.setProperty('voice',voices[0].id)

# Intro Line
print("Hello...What can i call you?")
engine.say("Hello...What can i call you?")
engine.runAndWait()
user = input('')

print(f"\nHello {user}....Nice to meet you")
engine.say(f"Hello {user}....Nice to meet you")
engine.runAndWait()

# Rules
print("\n")
print("+-+-+-+")
print("| | | | ")
print("+-+-+-+")
print("| | | | ")
print("+-+-+-+")
print("| | | | ")
print("+-+-+-+")

# Toss
print("\nLet's Toss.....")
engine.say("Let's Toss.....")
engine.runAndWait()

while True:  
    print("What do you wanna choose? (H/T)")
    engine.say("What do you wanna choose? Head or Tail")
    engine.runAndWait()
    choice = input("")

    if choice.lower() == 'h' or choice.lower() == 't':
        print("\nAlright....Flipping the coin...")
        engine.say("Alright....Flipping the coin...")
        engine.runAndWait()

        toss = ['h','t']
        toss = random.choice(toss)
        time.sleep(2)

        if toss == choice.lower():
            print("\nYeah...you won the toss")
            engine.say("Yeah...you won the toss")
            engine.runAndWait()
            break

        else:
            print("\noops...you lost the toss")
            engine.say("oops...you lost the toss")
            engine.runAndWait()
            break

        # if toss%2 == 0:
        #     print("\n")

    else:
        print(f"Just type 'h' or 't' {user}")
        engine.say(f"Just type 'h' or 't' {user}")
        engine.runAndWait()
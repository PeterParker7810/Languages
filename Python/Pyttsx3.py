import pyttsx3

AI = pyttsx3.init()
rate = AI.getProperty('rate')
voices = AI.getProperty('voices')
AI.setProperty('voice',voices[1].id)
AI.setProperty('rate',200)
AI.say("Hello Peter")

AI.runAndWait()
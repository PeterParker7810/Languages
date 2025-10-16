# Required Modules
import datetime
import speech_recognition as sr
import pyttsx3
import webbrowser
import wikipedia
import wolframalpha

# Speech Engine Initialisation
engine = pyttsx3.init()
voices = engine.getProperty('voices')
engine.setProperty('voice',voices[0].id)
activationword = 'EDITH'

# Speaking Library
def speak(text , rate = 120):
    engine.setProperty('rate',rate)
    engine.say(text)
    engine.runAndWait()

# Commands
def ParseCommand():
    listener = sr.Recognizer()
    print('Listening to the command....')

    with sr.Microphone() as source:
        listener.pause_threshold = 2
        input_speech = listener.listen(source)

    try:
        print('Recognizing Speech...')
        query = listener.recognize_google_cloud(input_speech,language='en_gb')
        print(f'The input speech was: {query}')

    except Exception as a:
        print('Sorry.....i Didn\'t get that one')
        speak('I didn\'t get that one....')
        print(a)
        return None
    
    return query

# Main Loop
if __name__ == '__main__':
    speak('Hello Peter',170)
    speak('How may i Help you Today?',170)

    while True:
        query = ParseCommand().lower().split()
        if query[0] == activationword:
            query.pop(0)

            if query[0] == 'say':
                if 'hello' in query:
                    speak('Greetings, all..')

                else:
                    query.pop(0)
                    speech = ' '.join(query)
                    speak(speech)
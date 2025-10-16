import datetime
import random
import webbrowser
import pyttsx3

# Initialize text-to-speech engine
engine = pyttsx3.init()

def speak(text):
    engine.say(text)
    engine.runAndWait()

def get_time():
    now = datetime.datetime.now()
    return now.strftime("%H:%M:%S")

def get_date():
    now = datetime.datetime.now()
    return now.strftime("%Y-%m-%d")

def open_website(url):
    webbrowser.open(url)

def tell_joke():
    jokes = [
        "Why don't scientists trust atoms? Because they make up everything!",
        "Why did the math book look sad? Because it had too many problems.",
        "What do you call fake spaghetti? An impasta!"
    ]
    return random.choice(jokes)

def process_command(command):
    command = command.lower()
    
    if 'time' in command:
        current_time = get_time()
        response = f"The current time is {current_time}."
        speak(response)
        return response

    elif 'date' in command:
        current_date = get_date()
        response = f"Today's date is {current_date}."
        speak(response)
        return response

    elif 'open' in command:
        if 'google' in command:
            url = "http://www.google.com"
        elif 'youtube' in command:
            url = "http://www.youtube.com"
        else:
            response = "Sorry, I don't know that website."
            speak(response)
            return response
        
        open_website(url)
        response = f"Opening {url}."
        speak(response)
        return response

    elif 'joke' in command:
        joke = tell_joke()
        speak(joke)
        return joke

    elif 'quit' in command:
        response = "Goodbye!"
        speak(response)
        return response

    else:
        response = "Sorry, I didn't understand that command."
        speak(response)
        return response

def main():
    print("Hello! I am your AI assistant. How can I help you today?")
    speak("Hello! I am your AI assistant. How can I help you today?")

    while True:
        command = input("You: ")
        if 'quit' in command.lower():
            break
        response = process_command(command)
        print("Assistant:", response)

if __name__ == "__main__":
    main()
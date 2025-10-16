import speech_recognition as sr # type: ignore
import pyttsx3 as ptx

rec = sr.Recognizer()
engine = ptx.init()
voices = engine.getProperty('voices')
engine.setProperty('voice',voices[1].id)

while True:
    try:
        with sr.Microphone() as source:
            print("Say Something.....")
            engine.say("Say Something.....")
            engine.runAndWait()

            rec.adjust_for_ambient_noise(source, duration=1)  # Reduce noise
            audio = rec.listen(source)

            # Use Google's free web API instead of Google Cloud API
            text = rec.recognize_google(audio)

            print(f"Recognized Text:\n{text}")
            engine.say(f"Recognized Text:\n{text}")
            engine.runAndWait()

    except sr.UnknownValueError:
        print("I didn't get that...")
        engine.say("I didn't get that...")
        engine.runAndWait()
        continue
import pyautogui
import time

print(pyautogui.size())
x,y = pyautogui.position()
print(x,y)

#move the mouse
pyautogui.moveTo(681,1054,2)
##pyautogui.dragTo(1885,20,button = 'left')
pyautogui.click()

##Keyboard
pyautogui.click()
pyautogui.write('notepad')

pyautogui.moveTo(681,310,2)
pyautogui.click()
time.sleep(0.5)
pyautogui.write('Hello World')

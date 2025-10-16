@echo off
color B
title Killing Process Delay

start notepad++.exe
timeout /t 10 /nobreak
taskkill /f /im notepad++.exe
pause
exit
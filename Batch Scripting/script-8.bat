@echo off
:start
cls
title Conditional Statements
set /p input=Do you like to continue (y/n)? 

if /i "%input%"=="y" goto yes
if /i "%input%"=="n" goto no

echo Enter Valid Command...
pause
goto start

:yes
echo Ok Let's Continue...
pause
goto start

:no
echo Ok Let's stop here...
pause
exit
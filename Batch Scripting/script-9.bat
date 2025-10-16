@echo off
title New Folder

set /p user=Enter the Path: 
set /p user1=Enter Folder Name:

if exist "%user%\%user1%" (
	echo Folder Already Exists...
) else (
	echo New Folder Created...
	mkdir "%user%\%user1%"
)

pause
exit
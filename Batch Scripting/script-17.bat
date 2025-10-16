@echo off
title New Folder
color E

set A=%date:~0,2%%date:~3,2%%date:~6,4%
set B=%time:~0,2%%time:~3,2%%time:~6,2%%time:~9,2%

set /p user=Enter a Path: 

if exist %user% (
	mkdir %user%\%A%%B: =%
	echo Successfully Created a folder named %A%%B: =%
) else echo Path is Invalid

pause 
exit
exit
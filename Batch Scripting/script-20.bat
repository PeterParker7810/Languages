@echo off
title System Info

systeminfo | findstr /i /c:"host name"
systeminfo | findstr /i /c:"os build type"
pause
exit
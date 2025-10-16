@echo off
title For Loop

echo Numbers from 1-10
for /l %%i in (1,1,10) do echo %%i

echo Numbers from 10-1
for /l %%i in (10,-1,1) do echo %%i

echo Even Numbers from 1-10
for /l %%i in (2,2,10) do echo %%i

echo Odd Numbers from 1-10
for /l %%i in (1,2,10) do echo %%i

pause
exit
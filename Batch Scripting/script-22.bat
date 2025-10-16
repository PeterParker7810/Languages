@echo off

set /a count = 0

if count leq 5 do (
	echo Value is %count%
	goto start
)

pause
exit

:start
set /a count += 1
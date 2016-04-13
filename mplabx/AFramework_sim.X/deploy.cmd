setlocal enabledelayedexpansion

set major=0
set minor=1
set buildnum=

for /f "delims=;" %%i in (build_number.txt) do set buildnum=%%i

@echo.
@echo ===============================================================
@echo Created new firmware version: v%major%_%minor%_%buildnum%.hex 
@echo ===============================================================

set /a buildnum=%buildnum% + 1

@echo %buildnum%;> build_number.txt
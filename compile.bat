@echo off
cd .\build >nul 2>&1
cmake -G "MinGW Makefiles" .. >nul 2>&1
make
if %errorlevel% equ 0 (
    del ..\release\csconfig.exe
    copy /B/V/Y csconfig.exe ..\release\csconfig.exe >nul 2>&1
) else (
    cd .. >nul 2>&1
)
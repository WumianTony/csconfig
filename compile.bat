@echo off
cd ./build >nul 2>&1
cmake -G "Unix Makefiles" .. >nul 2>&1
make
if %errorlevel% equ 0 (
    copy /V /Y csconfig.exe ../release/csconfig.exe >nul 2>&1
) else (
    cd .. >nul 2>&1
)
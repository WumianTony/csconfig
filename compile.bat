cd ./build >nul 2>&1
cmake -G "Unix Makefiles" .. >nul 2>&1
make >nul 2>&1
copy /V /Y csconfig.exe ../release/csconfig.exe >nul 2>&1
@REM cd ..
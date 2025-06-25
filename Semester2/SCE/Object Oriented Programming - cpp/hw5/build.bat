@echo off
g++ -g -std=c++11 -o driver.exe driver.cpp matrix.cpp
if %ERRORLEVEL% EQU 0 (
    echo Compilation successful! Running the game...
    driver.exe
) else (
    echo Compilation failed!
    pause
)
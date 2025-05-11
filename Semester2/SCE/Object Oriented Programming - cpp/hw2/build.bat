@echo off
g++ -g -o Driver.exe Driver.cpp Game.cpp Card.cpp Pile.cpp
if %ERRORLEVEL% EQU 0 (
    echo Compilation successful! Running the game...
    Driver.exe
) else (
    echo Compilation failed!
    pause
)
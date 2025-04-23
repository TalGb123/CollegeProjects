@echo off
g++ -g -o Game\Driver.exe Game\Driver.cpp Game\Game.cpp Game\Card.cpp Game\Pile.cpp
if %ERRORLEVEL% EQU 0 (
    echo Compilation successful! Running the game...
    Game/Driver.exe
) else (
    echo Compilation failed!
    pause
)
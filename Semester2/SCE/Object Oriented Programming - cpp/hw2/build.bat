@echo off
<<<<<<< HEAD:Semester2/SCE/Object Oriented Programming - cpp/hw2/build.bat
g++ -g -o Driver.exe Driver.cpp Game.cpp Card.cpp Pile.cpp
if %ERRORLEVEL% EQU 0 (
    echo Compilation successful! Running the game...
    Driver.exe
=======
g++ -g -o Game\Driver.exe Game\Driver.cpp Game\Game.cpp Game\Card.cpp Game\Pile.cpp
if %ERRORLEVEL% EQU 0 (
    echo Compilation successful! Running the game...
    Game/Driver.exe
>>>>>>> 0bd7a6be10755f7d79ba59fbbf327870937d1002:Semester2/SCE/Object Oriented Programming - cpp/hw2-215681107/build.bat
) else (
    echo Compilation failed!
    pause
)
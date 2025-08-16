@echo off
g++ -g -o main.exe main.cpp EncryptedText.cpp Text.cpp Word.cpp
if %ERRORLEVEL% EQU 0 (
    echo Compilation successful! Running the game...
    main.exe
) else (
    echo Compilation failed!
    pause
)
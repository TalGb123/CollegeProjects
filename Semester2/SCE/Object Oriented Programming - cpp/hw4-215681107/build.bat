@echo off
g++ -g -o main.exe main.cpp CoronaManagement.cpp Corona.cpp Patient.cpp Doctor.cpp Nurse.cpp Worker.cpp Human.cpp
if %ERRORLEVEL% EQU 0 (
    echo Compilation successful! Running the game...
    main.exe
) else (
    echo Compilation failed!
    pause
)
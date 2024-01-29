@echo off

REM Define your executable base names and the number of runs per executable
set executables=10 25 50 75 100 150 200 250 300 350 400 450 500 550 600 650 700 750 800 850 900 950 1000
set runs=10

REM Loop through each executable
for %%e in (%executables%) do (
    REM Run each executable 10 times
    for /L %%i in (1,1,%runs%) do (
        echo Running project_%%e.exe, iteration %%i
        .\project_%%e.exe
    )
    echo Done with project_%%e
    echo.
)

echo All tasks are completed.

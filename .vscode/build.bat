@echo off
mingw32-make
if %errorlevel%==0 (
    game.exe
)
pause
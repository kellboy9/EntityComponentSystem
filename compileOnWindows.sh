#!/bin/sh
 gcc -o main.exe *.c -I/usr/local/include/SDL2 -I/usr/include/mingw -Dmain=SDL_main -L/usr/local/lib -lcygwin -lSDL2main -lSDL2 -mwindows


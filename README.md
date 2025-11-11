# lua-coding-game-test

# NOTE:
For running the game make sure that in the EMSDK that in its libglfw.js that you comment out line 425
The file would be ```emsdk\upstream\emscripten\src\lib\libglfw.js```
The line that says
```
if (event.key == 'Backspace' || event.key == 'Tab') {
    event.preventDefault();
}
```
This will make sure that you are able to use the delete and tab button in the code editor
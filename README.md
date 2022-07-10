# STM32 Mechanical Keyboard

a DIY attempt of a 68 key style mechanical keyboard.

click the image below to watch the build video on youtube.

[![Youtube Video of the build process](https://user-images.githubusercontent.com/103286009/171074288-37d4d750-bf04-4c73-a355-b5b2445a03f6.png)](http://www.youtube.com/watch?v=smThnvXJ02c)

This keyboard is powered with a STM32F401CC board (a.k.a black pill F401CC)

![image](https://user-images.githubusercontent.com/103286009/171076032-ed510f66-37e4-4617-830d-a6bc695102cc.png)

To build this project, simply clone this project and build it in vscode with PlatformIO IDE

Note : Before building and flashing to the microcontroller, make sure that the keyboard wiring matches this schematic

![image](https://user-images.githubusercontent.com/103286009/171072490-12b0d3a3-1370-45db-9883-a4ab201bd165.png)

or instead change the matrix pin definitions in src/main.c (rowPins and colPins) to fit your wiring while paying attention to the key mapping in src/keymap.c

"secret" features:
  - AutoType mode: The keyboard will turn into an automatic text typer configured to output a specific text defined in src/text.c. Each key press will send a character of the text, and a long press will send the characters continuously. Enable autotype mode by pressing and holding FN and all five right-most keys.  
  - AutoPress mode: The keyboard will repeatedly press and unpress the enabled key(s). Enable autopress mode by defining ENABLE_AUTOTYPER in src/main.c (definition has been commented out). Then, on the keyboard, press FN, and the key desired (a key without an alternate mode to avoid conflict with alternate key). Then a long press will repeatedly send the desired key. Disable it by again pressing FN and the desired key, or to disable it for the entire keyboard, press FN and ESC

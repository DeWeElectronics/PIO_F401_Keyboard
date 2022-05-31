# STM32 Mechanical Keyboard

a DIY attempt of a 68 key style mechanical keyboard.

click the image below to watch the build video on youtube.

[![Youtube Video of the build process](https://user-images.githubusercontent.com/103286009/171074288-37d4d750-bf04-4c73-a355-b5b2445a03f6.png)](http://www.youtube.com/watch?v=smThnvXJ02c)

This keyboard is powered with a STM32F401CC board (a.k.a black pill F401CC)

![image](https://user-images.githubusercontent.com/103286009/171075774-e85a7d94-5f6c-4caf-abea-434bbc42154b.png)

To build this project, simply clone this project and build it in vscode with PlatformIO IDE

Note : Before building and flashing to the microcontroller, make sure that the keyboard wiring matches this schematic

![image](https://user-images.githubusercontent.com/103286009/171072490-12b0d3a3-1370-45db-9883-a4ab201bd165.png)

or instead change the matrix pin definitions in src/main.c (rowPins and colPins) to fit your wiring

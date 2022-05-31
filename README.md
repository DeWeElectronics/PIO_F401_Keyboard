# STM32 Mechanical Keyboard

a DIY attempt of a 68 key style mechanical keyboard.

click the image below to watch the build video on youtube.

[![Youtube Video of the build process]((https://user-images.githubusercontent.com/103286009/171074063-f86d0fd2-322c-4945-9ebb-d810ecc667af.png)](http://www.youtube.com/watch?v=smThnvXJ02c)

This keyboard is powered with a STM32F401CC board (a.k.a black pill F401CC)

Before building and flashing to the microcontroller, make sure that the keyboard wiring matches this schematic

![image](https://user-images.githubusercontent.com/103286009/171072490-12b0d3a3-1370-45db-9883-a4ab201bd165.png)

or instead change the matrix pin definitions in src/main.c (rowPins and colPins) to fit your wiring

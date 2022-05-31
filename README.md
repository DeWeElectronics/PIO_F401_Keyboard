# STM32 Mechanical Keyboard

a DIY attempt of a 68 key style mechanical keyboard.

![image](https://user-images.githubusercontent.com/103286009/171072225-c393b0a1-e99a-41db-9dae-a7502b0eaaeb.png)

<iframe width="1280" height="720" src="https://www.youtube.com/embed/smThnvXJ02c" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

This keyboard is powered with a STM32F401CC board (a.k.a black pill F401CC)

Before building and flashing to the microcontroller, make sure that the keyboard wiring matches this schematic

![image](https://user-images.githubusercontent.com/103286009/171072490-12b0d3a3-1370-45db-9883-a4ab201bd165.png)

or instead change the matrix pin definitions in src/main.c (rowPins and colPins) to fit your wiring

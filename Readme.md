# Designing Interactive Devices Lab2: Digital Timer

Lab report for the IDD lab 2 by Fabio Daiber

## Part A. Solder your LCD panel

Close-up of my soldering: 
![alt text](https://github.com/fpdaiber/IDD_Lab2/blob/master/IMG_2337.jpg)

## Part B. Writing to the LCD
#### a. What voltage level do you need to power your display?

The 3.5V powers the display.

### b. What voltage level do you need to power the display backlight?

The 5V powers the display backlight. You can see that the display is still working when you pull the 5V connection.

### c. What was one mistake you made when wiring up the display? How did you fix it?

My pot was set too high and the contrast on the display was so low that I could not see the text showing up. This was an easy fix.

### d. What line of code do you need to change to make it flash your name instead of "Hello World"?

You change the print statement
```
  lcd.print("Fabio Daiber");
````

![alt text](https://github.com/fpdaiber/IDD_Lab2/blob/master/IMG_2339.jpg)

### e. Include a copy of your Lowly Multimeter code in your lab write-up.

[My Multimeter](https://drive.google.com/open?id=1K9EHW3xyOUSyLR97CkWMqE7F06eF7VRU)

[Multimeter Code](https://github.com/fpdaiber/IDD_Lab2/blob/master/Multimeter.ino)


## Part C. Using a time-based digital sensor
### Upload a video of your working rotary encoder here.

[My Rotary Encoder Video](https://drive.google.com/open?id=16NYnVdigfccj3x3GUAWQHb7Oq5-uAKN2)

I adapted the rotary code slightly, so that it also prints the counter on my LCD display, as shown in my video. Here is the code to it:
[Custom rotary code](https://github.com/fpdaiber/IDD_Lab2/blob/master/Rotary_counter.ino)

## Part D. Make your Arduino sing!

![alt text](https://github.com/fpdaiber/IDD_Lab2/blob/master/IMG_2334.jpg)

##### a. How would you change the code to make the song play twice as fast?

You simply change noteDuration to less than a 1000, e.g. 
```noteDuration = 500 ```

You can also change the ```pauseBetweenNotes ```
to half the value to make it play twice as fast.

#### b. What song is playing?

It's the StarWars theme song

[The Star Wars Song](https://drive.google.com/open?id=1fpYqc16HcLLLSjBfXQWl9Wdv9hQbqUeq)

## Part E. Make your own timer
### a. Make a short video showing how your timer works, and what happens when time is up!

[MyTimer Video](https://drive.google.com/file/d/1Kr_iSIc0bgryJma9MOmBUzpxKavGsbQQ/view?usp=sharing)

### b. Post a link to the completed lab report your class hub GitHub repo.
[MyTimer Code](https://github.com/fpdaiber/IDD_Lab2/blob/master/Timer.ino)

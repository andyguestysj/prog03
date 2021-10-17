---
title: C Programming - Task Sheet
permalink: /docs/c-tasks/
---

## Introduction

### Task 1

1. Create a new folder called "CTasks1"
  *  You can do this from the file manager, or from the terminal. 
  *  In the terminal 
     *  you can use `ls` to see the contents of the current folder
     *  you can use `cd` to **c**hange **d**irectory - `cd foldername`
     *  you can use `md` to **m**ake a **d**irectory - `md CTasks1`
2. Open *Visual Studio Code*
  * You can do this from the Linux menu
    * Choose `Open Folder` from the menu and select your new folder
  * Or you can do this from terminal
    * you can use `code` to launch VSC
    * if you change to the directory you want to work in VSC will open using that folder
3. Create a new file called `HelloWorld.c`
4. Put the code below in the file

```c
#include <stdio.h>

int main(void) {
  printf("Hello World\n");
  return 0;
}
```

5. Compile and run the code
  * Right click on the file and select run
  * or
  * Select the terminal window (this can be opened from the View menu)
  * Enter `gcc HelloWorld.c -o HelloWorld` to compile the code to an executable called `HelloWorld`.
  * Enter `./HelloWorld` to run the code

### Task 2

1. Create a new file in the `CTasks1` folder called `printfDemo.c`
2. Open this file in VSC
3. Put the code below in the file

```c
#include <stdio.h>

int main(void) {
  printf("Hello World\n");
  return 0;
}
```
4. Experiment with adding copies of the printf line
   * place a `\n` in between Hello and World
   * place a `\t` in between Hello and World

### Task 3
1. Return to your `printf_demo` code
2. Add the two lines of code 

```c
int iVal = 65;
printf("Variable 0 %d", iVal);
```

3. What happens if you change the %d to %c?
4. Add a float variable with `float fVal=5.6;`
5. Output the new variable using printf.
   
### Task 4
1. Return to your `printf_demo` code
2. Add these lines to your code
3. 
```c
float fVal = 3.14159265;
printf("float is %f\n", fVal);
printf("float is %.2f\n", fVal);
```

Do you get different output?  
2. Try adding a new line

```c
printf("float is %6.2f\n", fVal);
```

What happens? Why?  

### Task 5

1. Return to your `printf_demo` code
2. Print out a receipt for the following items Bread £1.20, Milk 95p, Cheese £5, Butter £2.10. 
3. The price for each item should be stored in a float variable and printed from there.
4. Calculate the sum of the items and store it in another variable
5. The receipt should be headed "Recipt", should print out each item and its price, each item on its own line
6. The total should be printed from the variable as shown below

```
Receipt
-------
Bread  £1.20
Milk   £0.95
Cheese £5.00
Butter £2.10
       -----
Total  £9.25  
```

## Variables

### Task 6

1. Create a new file and call it `variables_demo.c`
2. Create an `enum` called `days` for the days of the week. It should store the name of each day, numbered from 0.
3. Create an `enum` variable called `today`.
4. Create an integer array that stores 7 values {10,15,5,60,20,40,30}.
5. Set `today` to Thursday.
6. Output the value from the integer array for `today`.

## Functions

### Task 7

1. Create a new file and call it `functions_demo.c`
2. Write a function that returns the middle value of three integer parameters

## Strings

1. Create a new file and call it `strings_demo.c`
2. Demonstrate outputting the length of a string stored in a char array.
3. Demonstrate copying one string to another
4. Demonstrate concatenating one string to the end of another
5. Demonstrate checking to see if two strings are the same
6. Write code that reads in a string from the keyboard and outputs it to the screen.
   
## Bringing it together

1. Create a new file and call it `morse.c`
2. Write an application that reads in a string of text from the keyboard and converts it to morse code, outputting one the morse for each character on a separate line. The test should consist of only lower case characters and spaces.

[Morse code on wikipedia](https://en.wikipedia.org/wiki/Morse_code)  


---
title: The C Programming Language
permalink: /docs/intro-c/
---

## Introduction

C is a general purpose, procedural programming language. It was developed in the early 1970s by Dennis Ritchie at Bell Labs. 
It was designed to map efficiently to machine instructions to make fast running applications.  

C is a powerful language that gives access to low level functionality that is often forbidden or restricted in other programming languages. Direct access to memory allows the programmer to access *anything* - devices, drives, memory, registers, for good or bad. 

The downside to this level of access is that you have to be very aware of what you are doing and how you are accessing the memory to prevent disaster!

C is the basis on which many other languages are based, including C++, C# and Objective C.

C should look a lot like Java, but unlike Java C is not an object-oriented language. You cannot create classes in C. *Methods* in C are called *functions*.  

## Hello World

We'll start the traditional way with *Hello World*.  

Here's *Hello World* in Java.

##### Hello World Java
 <iframe title="Hello World in Java" height="400px" width="100%" src="https://repl.it/@andyguest/JavaHelloWorld?lite=true" scrolling="no" frameborder="no" allowtransparency="true" allowfullscreen="true" sandbox="allow-forms allow-pointer-lock allow-popups allow-same-origin allow-scripts allow-modals"></iframe>  

The C version is a little different but should look very familiar.  

##### Hello World C
 <iframe title="Hello World in C" height="400px" width="100%" src="https://repl.it/@andyguest/HelloWorld?lite=true" scrolling="no" frameborder="no" allowtransparency="true" allowfullscreen="true" sandbox="allow-forms allow-pointer-lock allow-popups allow-same-origin allow-scripts allow-modals"></iframe>  

Breaking the code down.  

<div class="row">
  <div class="col-md-6" markdown="1">  

```c
#include <stdio.h>
```  

  </div>
  <div class="col-md-6" markdown="1">  

This imports the Standard Input/Output library. This is required to use the ```printf``` function.  
  
  </div>
</div>

<div class="row">
  <div class="col-md-6" markdown="1">  

```c
int main(void){

}
```   
  
  </div>
  <div class="col-md-6" markdown="1">  

Just like Java every C programme has a main function. This is the *entry* point for the application, the first function called when the programme is run.  
  
  </div>
</div>

<div class="row">
  <div class="col-md-6" markdown="1">  

```c
printf("Hello World\n");
```   
  
  </div>
  <div class="col-md-6" markdown="1">  

Outputs *Hello World* to the screen. ```printf``` is the *formatted print* function.  
  
  </div>
</div>

<div class="row">
  <div class="col-md-6" markdown="1">  

```c
return 0;
```   
  
  </div>
  <div class="col-md-6" markdown="1">  

The main function returns an integer. A zero indicates the programme exitted correctly. Any other value indicates some kind of error. Typically the number indicates which specific error occurred.
  
  </div>
</div>

### Compiling And Executing C Code

In repl.it you can simply press the <i class="fa fa-play" aria-hidden="true"><body> button.  

Alternatively, the way to compile C code from the Linux terminal is  
* Click on the terminal window
* Enter ```gcc main.c```
* Enter ```./a.out```

```gcc main.c``` - main.c is the name of our C file. ```gcc``` is the command for the GNU C Compiler. ```gcc main.c``` compiles the main.c file to the standard output file ```a.out```.  

If you wish you can specify the output executable filename with ```gcc main.c -o HelloWorld```. The ```-o``` flag allows you to specify the filename.  

```./a.out``` executes the file ```a.out```.  

You can see which files exits in the folder with the `ls` command.  

## Exercises

 <iframe title="Hello World in C" height="400px" width="100%" src="https://repl.it/@andyguest/HelloWorld?lite=true" scrolling="no" frameborder="no" allowtransparency="true" allowfullscreen="true" sandbox="allow-forms allow-pointer-lock allow-popups allow-same-origin allow-scripts allow-modals"></iframe>  

1. In the repl.it box above, compile and execute the code by pressing the <i class="fa fa-play" aria-hidden="true"> button.   

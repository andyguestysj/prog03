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

```c
#include <stdio.h> 
```

This imports the Standard Input/Output library. This is required to use the ```printf``` function.

```c
int main(void){

}
```






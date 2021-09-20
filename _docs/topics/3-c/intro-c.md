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
 <iframe title="Hello World in Java" height="400px" width="100%" src="https://replit.com/@andyguest/JavaHelloWorld?lite=true" scrolling="no" frameborder="no" allowtransparency="true" allowfullscreen="true" sandbox="allow-forms allow-pointer-lock allow-popups allow-same-origin allow-scripts allow-modals"></iframe>  

The C version is a little different but should look very familiar.  

##### Hello World C
 <iframe title="Hello World in C" height="400px" width="100%" src="https://replit.com/@andyguest/HelloWorld?lite=true" scrolling="no" frameborder="no" allowtransparency="true" allowfullscreen="true" sandbox="allow-forms allow-pointer-lock allow-popups allow-same-origin allow-scripts allow-modals"></iframe>  

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

In replit.com you can simply press <i class="fa fa-play" aria-hidden="true">  

Alternatively, the way to compile C code from the Linux terminal is  
* Click on the terminal window
* Enter ```gcc main.c```
* Enter ```./a.out```

```gcc main.c``` - main.c is the name of our C file. ```gcc``` is the command for the GNU C Compiler. ```gcc main.c``` compiles the main.c file to the standard output file ```a.out```.  

If you wish you can specify the output executable filename with ```gcc main.c -o HelloWorld```. The ```-o``` flag allows you to specify the filename.  

```./a.out``` executes the file ```a.out```.  

You can see which files exits in the folder with the `ls` command.  

## Exercises

 <iframe title="Hello World in C" height="400px" width="100%" src="https://replit.com/@andyguest/HelloWorld?lite=true" scrolling="no" frameborder="no" allowtransparency="true" allowfullscreen="true" sandbox="allow-forms allow-pointer-lock allow-popups allow-same-origin allow-scripts allow-modals"></iframe>  

1. In the replit.com box above, compile and execute the code by pressing <i class="fa fa-play" aria-hidden="true">
2. Compile and execute the code using the command line as described above.  

### The *ls* Command

The ls command lists all the files in the current folder that are not hidden.  
By using the `-l` flag you can see the full details of each unhidden file.

```console
ls -l
total 16
-rwxr-xr-x 1 runner runner 8304 Sep 20 10:02 main
-rw-r--r-- 1 runner runner   77 Sep 20 08:25 main.c
```  
The first part of this, `-rwxr-xr-x`, shows the accessibility of the file. The first character indicates the if the entry is a folder or not (`d` for folder, `-` for anything else i.e. a file). The rest of the string is made up of three sets of three letters, indicating the permissions of types of users.
* The first three characters indicate the *owners* permissions
* The middle three characters indicate the *group* permissions for the group owning the file
* The last three characters indicate the premissions for *others*, i.e. everyone else
The three characters in each set indicate whether or not that user can do something with the file. A `-` indicates the user cannot do it, a letter indicates they can.  
* The first character indicates if the user-type can read the file. If it is `r` then the user-type can read the file, they can see its contents but not change them. 
* The second character is `w` if the user-type can write the file, if they can edit it. It **is** possible to have write but not read access.
* The third character is `x` if the user-type can execute the file.

The second column of the listing shows how many link to the file.  

The third column indicates the *owner* of the file.  

The fourth column indicates the *group owner* of the file.

The fifth column indicates the size of the file in bytes. If the entry is a directory the size is always 4096.

The sixth column indicates the last time and date the file was modified.  

The seventh column indicates the name of the file or directory.  

The ls command can also use the -A flag to show hidden files. Flags can be combined to show multiple items.

```console
ls -la
total 20
drwxr-xr-x 1 runner runner   20 Sep 20 10:05 .
drwxr-xr-x 1 runner runner 4096 Sep 20 10:05 ..
-rwxr-xr-x 1 runner runner 8304 Sep 20 10:02 main
-rw-r--r-- 1 runner runner   77 Sep 20 08:25 main.c
```

This shows all the information for all the files, including any hidden ones.  

The entry `.` is the current folder. The `..` entry is the folder above the current one.  



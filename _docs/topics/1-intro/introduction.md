---
title: Introduction
permalink: /docs/introduction/
---

## Contents  

1. [Module Outline](#outline)  
2. [Assessment](#assessment)  
3. [Memory](memory)  
4. [Java Memory Usage](#javamem)  

## <a name="outline"></a>Module Outline  

1. Memory
  * How memory is used
  * The Stack, Frames, The Heap
  * Primitive Variables Vs Objects
  * Memory at a very low level

2. Java Memory Usage

3. C Programming
  * The Basics
  * GNU Debugger
  * Data Structures
  * Pointers
  * Linked Lists
  * Binary Trees

4. Inside The Chip

5. Assembly Language

## <a name="asseddment"></a>Assessment

Portfolio  
* Submitted at the end of the module  
* Consisting of  
  * C Code Assignment  
For full details see the Assessment section of the side bar.  

## <a name="memory"></a>Memory

### Physical Memory  

There are many ways of looking at memory. The images below describe the physical structure of computer memory and the protocols that involved in accessing it.  
![alt text](/assets/img/mem1.jpg "DIB Architecture")  
![alt text](/assets/img/mem2.jpg "memory access protocol")  
![alt text](/assets/img/mem3.jpg "DMA")  
![alt text](/assets/img/mem4.png "Physical structure of memory")  
This module does not focus on physical memory, nor on how it is accessed electronically. Instead this module focuses on how software accesses memory. 

### The Java Virtual Machine  

We will start by looking at the Java Virtual Machine (JVM).  

The JVM is an abstract virtual computer that is used to compile and execute Java code. Different implementations of JVMs are what allow Java to be compiled and run on different types of machines.  

We want to look at how memory is used by software running in the JVM. Different types of data are stored in different sections of the JVM. For our purposes there are four different memory areas.  

* The **code** section contains your **bytecode**. Bytecode is the compiled version of your code.  
* The **stack** section contains **methods, local variables, and reference variables**  
* The **heap** section contains **objects**, including all the data within those objects  
* The **static** section contains **static data and methods**  



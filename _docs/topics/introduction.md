---
title: 1. Introduction
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

### The Stack

The stack is used to store data as code is executed. Every time a method is called a new area is added to the stack. This area is called a **frame**. Note that this is a **frame** for each time a method is called, not one frame for each method.  

The frame for a method call stores the parameters passed in a method call and all the local variables used within that module. When the method finishes running the associated frame is deleted from the stack.

#### A Simple Java Application
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java">public static void main(String[] args)  
{  
  int i=1;  
}
</code></pre>
<ul>
<li>A frame is created on the stack</li>
<li>The stack is filled from zero upwards</li>
<li>Within the main() frame all local variables are stored</li>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/simple-java-stack-1.png" alt="simple java stack">

    </div>
</div>

#### Data is binary
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java">public static void main(String[] args)  
{  
  int i=1;  
}
</code></pre>
<ul>
<li>All data is stored in binary</li>
<li>(shown here as one byte)</li>
<li>(actual amount varies by chip)</li>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/simple-java-stack-2-binary.png" alt="simple java stack">

    </div>
</div>

#### Data stored smallest part first
<div class="row">
    <div class="col-md-6">
            <pre><code class="language-java">public static void main(String[] args)  
{  
  int i=1;  
}
</code></pre>
<ul>
<li>All data is stored in binary</li>
<li>Is is stored as least significant "part" first</li>
<li>(again, part size varies by chip)</li>
<li>We'll typically just show the numbers in decimal</li>
<li>We typically only need to deal with binary in Assembly</li>
</ul>
    </div>
    <div class="col-md-6">
<img src="/assets/img/simple-java-stack-2-binary2.png" alt="simple java stack">

    </div>
</div>

### [Methods & Frames](/intro-silly.html)





## <a name="javamem"></a>Java Memory Usage



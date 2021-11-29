---
title: Assembly
permalink: /docs/assembly-01/
---



Each personal computer has a microprocessor that manages the computer's arithmetical, logical, and control activities.  

Each family of processors has its own set of instructions for handling various operations such as getting input from keyboard, displaying information on screen and performing various other jobs. These set of instructions are called 'machine language instructions'.  

A processor understands only machine language instructions, which are strings of 1's and 0's. However, machine language is too obscure and complex for using in software development. So, the low-level assembly language is designed for a specific family of processors that represents various instructions in symbolic code and a more understandable form.   

## Advantages of Assembly Language

Having an understanding of assembly language makes one aware of −

* How programs interface with OS, processor, and BIOS;
* How data is represented in memory and other external devices;
* How the processor accesses and executes instruction;
* How instructions access and process data;
* How a program accesses external devices.

Other advantages of using assembly language are −
* It requires less memory and execution time;
* It allows hardware-specific complex jobs in an easier way;
* It is suitable for time-critical jobs;
* It is most suitable for writing interrupt service routines and other memory resident programs.

In other words, assembly language is ideal if you required fast code using very little memory that interacts directly with hardware and has to react quickly to signals.  

It is faster and closer to the hardware than C, but that comes at a cost of being even harder to read.  

## Disadvantages of Assembly Language

Assembly language is machine specific. The code has to be re-written to run on different hardware - Mac assembly code won't run on a PC, and assembly written for one PC may not work on another - 64 bit machine and 32 bit machine assembly code are different.  

Assembly is hard to read. It has only a basic set of operations that can be carried out so any complex operations have to be built up from first principles. So while assembly compiles down to a small size the code itself can be very long.  

## Assembly Videos

* [Hello World Tutorial](https://www.youtube.com/watch?v=HgEGAaYdABA)
* [Intro to x86 Assembly](https://www.youtube.com/playlist?list=PLmxT2pVYo5LB5EzTPZGfFN0c2GDiSXgQe)
* [Assembly Primer for Hackers](https://www.youtube.com/watch?v=K0g-twyhmQ4&list=PLue5IPmkmZ-P1pDbF3vSQtuNquX0SZHpB)
* [Assembly Language Programming](https://www.youtube.com/watch?v=3ulCFewbj-I&list=PLJp-g8uP8qlZSQlu8TwrFqkBsie5QpYPX)
* [x64 Assembly Tutorial Series](https://www.youtube.com/watch?v=rxsBghsrvpI&list=PLKK11Ligqitg9MOX3-0tFT1Rmh3uJp7kA)

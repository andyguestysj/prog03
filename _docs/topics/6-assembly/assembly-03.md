---
title: Assembly Environment Setup
permalink: /docs/assembly-03/
---

We will be using **NASM** (Netwide Assembler) to compile some assembly language code.  

NASM is installed in repl.it by default. You can use it from the terminal window/command line in repl.it.  

However repl.it doesn't directly support Assembly language so we have to take a few steps to get it to run. I'll provide you with a starting template for exercises but if you want to create your own here are the steps.

1. Create a new c project in repl.it
2. Select the terminal window and run `rm main.c` - we are writing assembly, not c, we don't need it.
3. Create a new file called `main.asm` - `asm` for assembly. You won't get coloured highlighting but we'll manage.
4. Create a new file called `main.sh` and put the following in it  

```console 
nasm -f elf -o main.o main.asm
ld -m elf_i386 -s -o main main.o
./main
```
5. Create a new file called `.replit` (don't forget the `.`). Put the following in it
```
run="sh main.sh"
```
6. Run your code by pressing the green triangle button as normal


Alternatively you can enter those three lines in the terminal every time you want to run the code. Creating the shell file is easier. 

NB if you create an assembly file called something other than `main.asm` you'll need to change the contents of main.sh to match.

**`nasm -f elf main.asm`** - nasm compiles the code, the `-f elf` flag tells the compiler the code is written in 32 bit PC assembly. This setting can be changed for other types of assembly (eg `-f elf64` for 64 bit PC assembly), but we will stick with `-f elf`. It generates an object file with the name defined by the `-o` flag. `-o main.o` causes the file to be called `main.o`. `-o bob.o` would make an object file called `bob.o` even if the source file is still called `main.asm`.  

**`ld -m elf_i386 -s -o main main.o`** *links* the object file with the required libraries to produce an executable. `-m elf_i386` specifies the target machine (32 bit PC). Again `-o` specifies the output file name.  

## Local Installations

NASM is available for any Linux system or Linux emulator for PC/Mac. There are other assemblers available that generally go by the name *ASM. MASM is a Microsoft assembler for example.  

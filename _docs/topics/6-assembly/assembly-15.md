---
title: Debugging Assembly
permalink: /docs/assembly-15/
---

## Debugging Preparation

To debug our assembly code we need to compile and link it slightly differently. To compile `main.asm` use the following commands.  

```console
nasm -f elf -g -o main.o main.asm
ld -m elf_i386 -o main main.o
```

In the setup we've been using to compile and run our programs, you can change `main.sh` to the following

>nasm -f elf -g -o main.o main.asm
>ld -m elf_i386 -o main main.o
>./main

>For reference we've added the `-g` flag to the `nasm` line and removed the `-s` flag from the `ld` line.

These changes generate debugging information that can be used by `gdb`.

## Using gdb

After we have compiled and linked our assembly code we can use gdb from the terminal window.  

`gdb main` will launch the debugger.

The prompt will change to `(gdb)`

gdb defaults to a different syntax to the one we are using. To change to Intel syntax enter  

`set disassembly-flavor intel`

You will need to do this each time you start `gdb`.

gdb has the following commands
* `break x` creates a breakpoint at the label `x`
* `break x+y` creates a breakpoint `y` bytes after the label `x`
* `run` starts the code running. it will stop at the first breakpoint
* `continue` will restart the code running if it has stopped at a breakpoint
* `stepi` or `si` will run the next instruction, stepping in to any functions
* `nexti` or `ni` will run the next instruction but not step in to functions

To start debugging at the start of your code use the commands  

```
break _start
run
```

You can use the commands above to step through the code.

## Layout

To aid in debugging we can use the `layout` command within `gdb` so that we can see the contents of the registers and the assembly code.  

To set layout up, compile and link your code and run gdb as follows -  

```console
gdb main
(gdb) set disassembly-flavor intel
(gdb) break _start
(gdb) run
(gdb) layout asm
(gdb) layout regs
```

You should see something like this -  

<img src="/assets/img/other/layout.png.png" alt="gdb layout">

The upper section of the layout shows the registers and their contents.  
The middle section of the layout shows the code with the current line highlighted.  
You can enter the gdb commands in the bottom section of the layout.  

As you step through the code you will see the registers updated.


---
title: Assembly Basics
permalink: /docs/assembly-04/
---


## Structure / Sections

An assembly program can be divided into three sections −

* The **data** section
* The **bss** section
* The **text** section

### The data Section
The **data** section is used for declaring initialized data or constants. This data does not change at runtime. You can declare various constant values, file names, or buffer size, etc., in this section.

The syntax for declaring data section is −

```assembly
section.data
```

### The bss Section
The bss section is used for declaring variables. The syntax for declaring bss section is −

```assembly
section.bss
```

### The text section
The text section is used for keeping the actual code. This section must begin with the declaration global _start, which tells the kernel where the program execution begins.  

The syntax for declaring text section is −  

```assembly
section.text
   global _start
_start:
```

## Comments
Assembly language comment begins with a semicolon (;). It may contain any printable character including blank. It can appear on a line by itself, like −  
```assembly
; This program displays a message on screen
```
or, on the same line along with an instruction, like −

```assembly
add eax, ebx     ; adds ebx to eax
```

## Assembly Language Statements
Assembly language programs consist of three types of statements −
* Executable instructions or instructions,
* Assembler directives or pseudo-ops, and
* * Macros.
The executable instructions or simply instructions tell the processor what to do. Each instruction consists of an operation code (opcode). Each executable instruction generates one machine language instruction.  

The assembler directives or pseudo-ops tell the assembler about the various aspects of the assembly process. These are non-executable and do not generate machine language instructions.  

Macros are basically a text substitution mechanism.  

### Syntax of Assembly Language Statements
Assembly language statements are entered one statement per line. Each statement follows the following format −  

```
[ label ]   mnemonic   [ operands ]   [ ;comment ]
```

The fields in the square brackets are optional. A basic instruction has two parts, the first one is the name of the instruction (or the mnemonic), which is to be executed, and the second are the operands or the parameters of the command.  

Following are some examples of typical assembly language statements −  

```assembly
INC COUNT        ; Increment the memory variable COUNT

MOV TOTAL, 48    ; Transfer the value 48 in the 
                 ; memory variable TOTAL
					  
ADD AH, BH       ; Add the content of the 
                 ; BH register into the AH register
					  
AND MASK1, 128   ; Perform AND operation on the 
                 ; variable MASK1 and 128
					  
ADD MARKS, 10    ; Add 10 to the variable MARKS
MOV AL, 10       ; Transfer the value 10 to the AL register
```
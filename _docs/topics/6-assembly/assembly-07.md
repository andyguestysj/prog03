---
title: Variables & Constants
permalink: /docs/assembly-07/
---

## Variables
To create variables the format is  

`[ variable-name ]    define-directive    initial-value   [ ,initial-value ]...`  

There are five basic forms of the define directive −  

|Directive|Purpose|Storage Space|
|---|---|---|
|DB|Define Byte|allocates 1 byte|
|DW|Define Word|allocates 2 bytes|
|DD|Define Doubleword|allocates 4 bytes|
|DQ|Define Quadword|allocates 8 bytes|
|DT|Define Ten Bytes|allocates 10 bytes|

Since assembly doesn't have variable types we need to define the amount of space required to store the variable.  

```assembly
choice		   DB	   'y'
number		   DW	   12345
neg_number	   DW	   -12345
big_number	   DQ	   123456789
real_number1	DD	   1.234
real_number2	DQ	   123.456
```

Keep in mind that  

* Each byte of character is stored as its ASCII value in hexadecimal.
* Each decimal value is automatically converted to its 16-bit binary equivalent and stored as a hexadecimal number.
* Processor uses the little-endian byte ordering.
* Negative numbers are converted to its 2's complement representation.
* Short and long floating-point numbers are represented using 32 or 64 bits, respectively.

You can also reserve space for unitialised variables.  

Directive|Purpose|
|---|---|
|RESB|Reserve a Byte|
|RESW|Reserve a Word|
|RESD|Reserve a Doubleword|
|RESQ|Reserve a Quadword|
|REST|Reserve a Ten Bytes|

The TIMES directive allows multiple initializations to the same value. For example, an array named marks of size 9 can be defined and initialized to zero using the following statement −  

`marks  TIMES  9  DW  0`

The TIMES directive is useful in defining arrays and tables. 

## Constants

### EQU

The `EQU` directive is used for defining constants. The syntax of the EQU directive is as follows −  

`CONSTANT_NAME EQU expression`  

For example,  

`TOTAL_STUDENTS equ 50`  

You can then use this constant value in your code, like −  

```assembly
mov  ecx,  TOTAL_STUDENTS 
cmp  eax,  TOTAL_STUDENTS
```

The operand of an EQU statement can be an expression −  

```assembly
LENGTH equ 20
WIDTH  equ 10
AREA   equ length * width
```

Above code segment would define AREA as 200.  

```assembly
SYS_EXIT  equ 1
SYS_WRITE equ 4
STDIN     equ 0
STDOUT    equ 1
section	 .text
   global _start    ;must be declared for using gcc
	
_start:             ;tell linker entry point
   mov eax, SYS_WRITE         
   mov ebx, STDOUT         
   mov ecx, msg1         
   mov edx, len1 
   int 0x80                
	
   mov eax, SYS_WRITE         
   mov ebx, STDOUT         
   mov ecx, msg2         
   mov edx, len2 
   int 0x80 
	
   mov eax, SYS_WRITE         
   mov ebx, STDOUT         
   mov ecx, msg3         
   mov edx, len3 
   int 0x80
   
   mov eax,SYS_EXIT    ;system call number (sys_exit)
   int 0x80            ;call kernel

section	 .data
msg1 db	'Hello, programmers!',0xA,0xD 	
len1 equ $ - msg1			

msg2 db 'Welcome to the world of,', 0xA,0xD 
len2 equ $ - msg2 

msg3 db 'Linux assembly programming! '
len3 equ $- msg3
```

### %assign

The **%assign** directive can be used to define numeric constants like the EQU directive. This directive allows redefinition. For example, you may define the constant TOTAL as −  

`%assign TOTAL 10`

Later in the code, you can redefine it as −  

`%assign  TOTAL  20`  

This directive is case-sensitive.  

### %define

The **%define** directive allows defining both numeric and string constants. This directive is similar to the #define in C. For example, you may define the constant PTR as −  

`%define PTR [EBP+4]`  

The above code replaces PTR by [EBP+4].  

This directive also allows redefinition and it is case-sensitive.  
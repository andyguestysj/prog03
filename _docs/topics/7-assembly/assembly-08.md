---
title: Arithmetic
permalink: /docs/assembly-08/
---

## INC & DEC

```assembly
INC EBX    ; Adds 1 to EBX
DEC EBX    ; Subtracts 1 from EBX
```

## ADD & SUB

```assembly
ADD ebx, ecx  ; add ecx to ebx, storing the results in ebx
SUB ebx, ecx  ; subtract ecx from ebx, storing the results in ebx
```

## MUL/IMUL

There are two instructions for multiplying binary data. The MUL (Multiply) instruction handles unsigned data and the IMUL (Integer Multiply) handles signed data. Both instructions affect the Carry and Overflow flag.  

**Syntax**
The syntax for the MUL/IMUL instructions is as follows −  

`MUL/IMUL multiplier`  

Multiplicand in both cases will be in an accumulator, depending upon the size of the multiplicand and the multiplier and the generated product is also stored in two registers depending upon the size of the operands. Following section explains MUL instructions with three different cases −  


|Sr.No.|Scenarios|
|---|---|
|1|**When two bytes are multiplied −**<BR>The multiplicand is in the AL register, and the multiplier is a byte in the memory or in another register. The product is in AX. High-order 8 bits of the product is stored in AH and the low-order 8 bits are stored in AL.<BR>![MUL two bytes](/assets/img/assembly/arithmetic1.jpg "MUL two bytes")|
|2|**When two one-word values are multiplied −**<BR>The multiplicand should be in the AX register, and the multiplier is a word in memory or another register. For example, for an instruction like MUL DX, you must store the multiplier in DX and the multiplicand in AX.<BR>The resultant product is a doubleword, which will need two registers. The high-order (leftmost) portion gets stored in DX and the lower-order (rightmost) portion gets stored in AX.<BR>![MUL two words](/assets/img/assembly/arithmetic2.jpg "MUL two words")|
|3|**When two doubleword values are multiplied −**<BR>When two doubleword values are multiplied, the multiplicand should be in EAX and the multiplier is a doubleword value stored in memory or in another register. The product generated is stored in the EDX:EAX registers, i.e., the high order 32 bits gets stored in the EDX register and the low order 32-bits are stored in the EAX register.<BR>![MUL two double words](/assets/img/assembly/arithmetic3.jpg "MUL two double words")|

*Example*   

The following example multiplies 3 with 2, and displays the result −  

```assembly
section	.text
   global _start    ;must be declared for using gcc
	
_start:             ;tell linker entry point

   mov	al,'3'
   sub     al, '0'
	
   mov 	bl, '2'
   sub     bl, '0'
   mul 	bl
   add	al, '0'
	
   mov 	[res], al
   mov	ecx,msg	
   mov	edx, len
   mov	ebx,1	;file descriptor (stdout)
   mov	eax,4	;system call number (sys_write)
   int	0x80	;call kernel
	
   mov	ecx,res
   mov	edx, 1
   mov	ebx,1	;file descriptor (stdout)
   mov	eax,4	;system call number (sys_write)
   int	0x80	;call kernel
	
   mov	eax,1	;system call number (sys_exit)
   int	0x80	;call kernel

section .data
msg db "The result is:", 0xA,0xD 
len equ $- msg   
segment .bss
res resb 1
```

## DIV/IDIV

The division operation generates two elements - a quotient and a remainder. In case of multiplication, overflow does not occur because double-length registers are used to keep the product. However, in case of division, overflow may occur. The processor generates an interrupt if overflow occurs.  

The DIV (Divide) instruction is used for unsigned data and the IDIV (Integer Divide) is used for signed data.  

Syntax  

The format for the DIV/IDIV instruction −  

`DIV/IDIV	divisor`

The dividend is in an accumulator. Both the instructions can work with 8-bit, 16-bit or 32-bit operands. The operation affects all six status flags. Following section explains three cases of division with different operand size −  

|Sr.No.|Scenarios|
|---|---|
|1|**When the divisor is 1 byte −**<BR>The dividend is assumed to be in the AX register (16 bits). After division, the quotient goes to the AL register and the remainder goes to the AH register.<BR>![1 Byte Divisor](/assets/img/assembly/arithmetic4.jpg "1 Byte Divisor")|
|2|**When the divisor is 1 word −**<BR>The dividend is assumed to be 32 bits long and in the DX:AX registers. The high-order 16 bits are in DX and the low-order 16 bits are in AX. After division, the 16-bit quotient goes to the AX register and the 16-bit remainder goes to the DX register.<BR>![1 Word Divisor](/assets/img/assembly/arithmetic5.jpg "1 Word Divisor")|
|3|**When the divisor is doubleword −**<BR>The dividend is assumed to be 64 bits long and in the EDX:EAX registers. The high-order 32 bits are in EDX and the low-order 32 bits are in EAX. After division, the 32-bit quotient goes to the EAX register and the 32-bit remainder goes to the EDX register.<BR>![Doubleword Divisor](/assets/img/assembly/arithmetic6.jpg "Doubleword Divisor")|

*Example*  

The following example divides 8 with 2. The dividend 8 is stored in the 16-bit AX register and the divisor 2 is stored in the 8-bit BL register.  

```assembly
section	.text
   global _start    ;must be declared for using gcc
	
_start:             ;tell linker entry point
   mov	ax,'8'
   sub     ax, '0'
	
   mov 	bl, '2'
   sub     bl, '0'
   div 	bl
   add	ax, '0'
	
   mov 	[res], ax
   mov	ecx,msg	
   mov	edx, len
   mov	ebx,1	;file descriptor (stdout)
   mov	eax,4	;system call number (sys_write)
   int	0x80	;call kernel
	
   mov	ecx,res
   mov	edx, 1
   mov	ebx,1	;file descriptor (stdout)
   mov	eax,4	;system call number (sys_write)
   int	0x80	;call kernel
	
   mov	eax,1	;system call number (sys_exit)
   int	0x80	;call kernel
	
section .data
msg db "The result is:", 0xA,0xD 
len equ $- msg   
segment .bss
res resb 1
```


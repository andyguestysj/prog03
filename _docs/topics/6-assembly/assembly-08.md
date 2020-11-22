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
|1|When two bytes are multiplied −  

The multiplicand is in the AL register, and the multiplier is a byte in the memory or in another register. The product is in AX. High-order 8 bits of the product is stored in AH and the low-order 8 bits are stored in AL.  
![MUL two bytes](/assets/img/assembly/arithmetic1.jpg "MUL two bytes")  
|
|2|When two one-word values are multiplied −  

The multiplicand should be in the AX register, and the multiplier is a word in memory or another register. For example, for an instruction like MUL DX, you must store the multiplier in DX and the multiplicand in AX.  

The resultant product is a doubleword, which will need two registers. The high-order (leftmost) portion gets stored in DX and the lower-order (rightmost) portion gets stored in AX.  
![MUL two words](/assets/img/assembly/arithmetic2.jpg "MUL two words")  
|
|3|When two doubleword values are multiplied −  

When two doubleword values are multiplied, the multiplicand should be in EAX and the multiplier is a doubleword value stored in memory or in another register. The product generated is stored in the EDX:EAX registers, i.e., the high order 32 bits gets stored in the EDX register and the low order 32-bits are stored in the EAX register.  
![MUL two double words](/assets/img/assembly/arithmetic3.jpg "MUL two double words")  
|
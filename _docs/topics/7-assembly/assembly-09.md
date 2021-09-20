---
title: Logic
permalink: /docs/assembly-09/
---

The processor instruction set provides the instructions AND, OR, XOR, TEST, and NOT Boolean logic, which tests, sets, and clears the bits according to the need of the program.  

The format for these instructions −  

|Instruction|Format|
|---|---|
|AND|AND operand1, operand2|
|OR|OR operand1, operand2|
|XOR|XOR operand1, operand2|
|TEST|TEST operand1, operand2|
|NOT|NOT operand1|

The first operand in all the cases could be either in register or in memory. The second operand could be either in register/memory or an immediate (constant) value. However, memory-to-memory operations are not possible. These instructions compare or match bits of the operands and set the CF, OF, PF, SF and ZF flags.  

The AND instruction is used for supporting logical expressions by performing bitwise AND operation. The bitwise AND operation returns 1, if the matching bits from both the operands are 1, otherwise it returns 0. For example −  

||Operand1:|0101|
||Operand2:|0011|
|---|---|---|
|After AND ->|Operand1:|0001|

The AND operation can be used for clearing one or more bits. For example, say the BL register contains 0011 1010. If you need to clear the high-order bits to zero, you AND it with 0FH.  

`AND	BL,   0FH   ; This sets BL to 0000 1010`

Let's take up another example. If you want to check whether a given number is odd or even, a simple test would be to check the least significant bit of the number. If this is 1, the number is odd, else the number is even.  

Assuming the number is in AL register, we can write −  

```assembly
AND	AL, 01H     ; ANDing with 0000 0001
JZ    EVEN_NUMBER
```

The OR and XOR functions work similarly.  

The TEST instruction works like AND but doesn't change the operand.  

The NOT instruction takes a single operand and inverts it, bit by bit.  

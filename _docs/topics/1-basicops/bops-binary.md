---
title: Binary Recap
permalink: /docs/bops-binary/
---

### Base 10 - The Decimal System

The numbering system we use in everyday life is the decimal system. The decimal system is a **Base 10** system. This means we count in multiples of 10. Each digit in a decimal number is a multiple of ten. More correctly each digit in a decimal number is a multiple of a power of 10.  

**Powers of 10**

| 10<sup>y</sup> | Means | 10<sup>-y</sup> | Means |
| --- | --- | --- | --- |
| 10<sup>0</sup> | 1 | | | 
| 10<sup>1</sup> | 10 | 10<sup>-1</sup> | 0.1 : 1/10 |
| 10<sup>2</sup> | 100 | 10<sup>-2</sup> | 0.01 : 1/100 |
| 10<sup>3</sup> | 1000 | 10<sup>-3</sup> | 0.001 : 1/1000 |
| 10<sup>4</sup> | 10000 | 10<sup>-4</sup> | 0.0001 : 1/10000 |

So the number 123.45 is 
* 1 * 10<sup>2</sup> -> 1 * 100 -> 100
* plus 2 * 10<sup>1</sup> -> 2 * 10 -> 20
* plus 3 * 10<sup>0</sup> -> 3 * 1 -> 3
* plus 4 * 10<sup>-1</sup> -> 4 * 0.1 -> 0.4
* plus 5 * 10<sup>-2</sup> -> 5 * 0.01 -> 0.05
  
Which is 100 + 20 + 3 + 0.4 + 0.05 or 123.45.

This might seem like a bit of a pointless exercise, but that is because the decimal, base-10 system is "natural" to us. Other counting systems seem unnatural and we need to convert them to base-10 to work out what the numbers mean. The same process works for every base-X system, we simply replace the 10 in the 10<sup>y</sup> with the base number to give us x<sup>y</sup>. Oh, and we remember that the biggest number we can use in any single column is X-1!

### Base 2 - The Binary System

Computers are based on switches which have two settings - on and off, because of this basis computers "naturally" use base-2, the binary numbering system. In the binary system each digit is a multiple of a power of 2. Remember each digit can only be 0 or 1.

**Powers of 2**

| 2<sup>y</sup> | Means | 2<sup>-y</sup> | Means |
| --- | --- | --- | --- |
| 2<sup>0</sup> | 1 | | | 
| 2<sup>1</sup> | 2 | 2<sup>-1</sup> | 0.5 : 1/2 |
| 2<sup>2</sup> | 4 | 2<sup>-2</sup> | 0.25 : 1/4 |
| 2<sup>3</sup> | 8 | 2<sup>-3</sup> | 0.125 : 1/8 |
| 2<sup>4</sup> | 16 | 2<sup>-4</sup> | 0.0625 : 1/16 |

So the number 101.11 is 
* 1 * 2<sup>2</sup> -> 1 * 4 -> 4
* plus 2 * 2<sup>1</sup> -> 0 * 2 -> 0
* plus 3 * 2<sup>0</sup> -> 1 * 1 -> 1
* plus 4 * 2<sup>-1</sup> -> 1 * 0.5 -> 0.5
* plus 5 * 2<sup>-2</sup> -> 1 * 0.25 -> 0.25
  
Which is 4 + 0 + 1 + 0.5 + 0.25 = 5.75.

### Base-10 - Addition

In base-10 we start with the least significant digit (the one with the lowest power of 10, remembering that -1 is lower than 0) and add together the digits in that position. If the sum of those digits is less than ten we put the sum in that position in the solution. If it is greater than or equal to ten we put the "units" in that position of the solution and carry the number of "tens" to the next column.

| Base-10 Addition |||||
| --- | --- | --- | --- | --- |
|| 1 | 2 | 3 | 4 |
|plus|||||
|| 1 | 9 | 8 | 4 |
|equals|||||
|add "units" together (10<sup>0</sup>)||||4+4|
|||||8|
|add "tens" together (10<sup>1</sup>)|||3+8|8|
||||11|8|
|carry the multiple of 10||1|1|8|
|add "hundreds" together (10<sup>2</sup>)||2+9+1|1|8|
|||12|1|8|
|carry the multiple of 10|1|2|1|8|
|add "thousands" together (10<sup>3</sup>)|1+1+1|2|1|8|
|Sum|3|2|1|8|

### Base-2 - Addition

Base-2 addition works in the same way

| Base-2 Addition |||||
| --- | --- | --- | --- | --- |
|| 0 | 0 | 1 | 1 |
|plus|||||
|| 0 | 1 | 1 | 0 |
|equals|||||
|add "units" together (2<sup>0</sup>=1)||||1+0|
|||||1|
|add "twos" together (2<sup>1</sup>=2)|||1+1|1|
|1+1=2, 2 in binary is 10|||10|1|
|carry the multiple of 2||1|0|1|
|add "fours" together (2<sup>2</sup>=4)||0+1+1|0|1|
|||10|1|1|
|carry the multiple of 2|1|0|0|1|
|add "eights" together (2<sup>3</sup>=8)|0+0+1|0|0|1|
|Sum|1|0|0|1|

0011 = 3  
0110 = 6  
1001 = 9  

### Base-16 - Hexadecimal

Binary numbers get very long, very quickly. While they are perfect for computers to use they are very fiddly for humans. We can very easily make mistakes transcribing all those ones and zeros. We are most comfortable with counting in base-10 but converting between base-2 and base-10 is tricky and, again, easy to make mistakes in.  
We've settled on using base-16 or hexadecimal notation as a compromise. It is no more natural than base-2 but it is less fiddly (thanks to shorter numbers) and converting between binary and hexadecimal is quick and easy.  

In the hexadecimal system each digit is a multiple of a power of 16. Each digit can be 0-9 or A,B,C,D,E or F (representing the numbers 10-15).  

**Base-16**

|Hexadecimal|Decimal|
|---|---|
|0|0|
|1|1|
|2|2|
|3|3|
|4|4|
|5|5|
|6|6|
|7|7|
|8|8|
|9|9|
|A|10|
|B|11|
|C|12|
|D|13|
|E|14|
|F|15|


**Powers of 16**

| 16<sup>y</sup> | Means | 16<sup>-y</sup> | Means |
| --- | --- | --- | --- |
| 16<sup>0</sup> | 1 | | | 
| 16<sup>1</sup> | 16 | 16<sup>-1</sup> | 1/16 |
| 16<sup>2</sup> | 256 | 16<sup>-2</sup> | 1/256 |
| 16<sup>3</sup> | 4096 | 16<sup>-3</sup> | 1/4096 |
| 16<sup>4</sup> | 65536 | 16<sup>-4</sup> | 1/65536 |

The process of converting between base-16 and base-10 follows the principles shown above, I'm not going to go through it again. Base-16 addition likewise follows the same principles.  

### Base-16 to Base-2 Conversion

The main reason we use base-16 is because 16 is a power of 2 (2<sup>4</sup>), this means each hexadecimal digit represents four binary digits.

|Hexadecimal|Decimal|Binary|
|---|---|---|
|0|0|0000|
|1|1|0001|
|2|2|0010|
|3|3|0011|
|4|4|0100|
|5|5|0101|
|6|6|0110|
|7|7|0111|
|8|8|1000|
|9|9|1001|
|A|10|1010|
|B|11|1011|
|C|12|1100|
|D|13|1101|
|E|14|1110|
|F|15|1111|

To convert between hexadecimal and binary, convert each hexadecimal digit to its binary equivalent.  
To convert from binary to hexadecimal convert each four digits to its hexadecimal equivalent, remembering to start at the right hand side.  

Hexadecimal has the further advantage that each pair of digits represents a single byte.  
---
title: Basic Operations
permalink: /docs/bops-integers/
---

### Storing Integers  

We've already said that computers used binary notation, integers are "whole numbers" so surely integers are just stored as their binary equivalent right? Well it isn't quite that simple, we have a couple of complications to consider. 

### Unsigned Integers

Lets consider the simplest case. We want to store an integer number, we know the number will be positive or zero. In this case we can simply store the number in binary.  

In most languages we have three types of integer data types - **short, int and log**. 

|Data Type|Size|
|---|---|
|short|2 bytes|
|int|4 bytes|
|long|8 bytes|

However short, int and long can also store negative numbers. If we know the number is positive or zero we can use the keyword **unsigned**. This allows us to use all the bits to represent the integer.  

|Data Type|Size|Range|
|---|---|---|
|unsigned short|2 bytes|0 - 65,535|
|unsigned int|4 bytes|0 - 4,294,967,295|
|unsigned long|8 bytes|0 - 18,446,744,073,709,551,615|

**Overflow Errors**

Unsigned integers are generally straight forward but there are two situations which require careful consideration.  

What happens if you are storing 65,535 in an unsigned short and add 1 to it?  
65,535 = 1111 1111 1111 1111  
65,536 = 1 0000 0000 0000 0000  
The maths is easy enough but the problem is an unsigned short only has 16 bits of data in it. The number is too big to be stored in the data type. What happens varies by language but generally you will be allowed to do this. A flag will be set to let you know an *overflow* has occurred but the programme will continue running.  
The code below is in **c**, we'll learn about c before long but this should be easy to follow.  

```c
unsigned short int aNumber=65535;

printf("the number is %hu\n", aNumber);


aNumber = aNumber + 1;

printf("the number is now %hu\n", aNumber);

```
Produces
```console
the number is 65535
the number is now 0
```

Similarly if the numnber is zero and we subtract one.  

```c
unsigned short int aNumber=0;

printf("the number is %hu\n", aNumber);


aNumber = aNumber - 1;

printf("the number is now %hu\n", aNumber);

```
Produces
```console
the number is 0
the number is now 65535
```

We say the numbers wrap-around. The wrap-around when we put a number in that is too big is obvious but why does subtracting 1 from 0 have this effect? It is caused by the way we store negative numbers.  

### Signed Integers - Storing Negative Numbers

As described above, most languages we have three types of integer data types - **short, int and log**. 

|Data Type|Size|
|---|---|
|short|2 bytes|
|int|4 bytes|
|long|8 bytes|

We'll shift the range of numbers so that 0 is in the middle.

|Data Type|Size|Range|Data Type|Size|Range|
|---|---|---|---|---|---|
|unsigned short|2 bytes|0 - 65,535|short|2 bytes|-32,768 to 32,767|
|unsigned int|4 bytes|0 - 4,294,967,295|int|4 bytes|-2,147,483,648 to 2,147,483,647|
|unsigned long|8 bytes|0 - 18,446,744,073,709,551,615|long|8 bytes|-9,223,372,036,854,775,808 to 9,223,372,036,854,775,807|

We need some way to distinguish negative numbers from positive numbers. The approach taken was to use the leftmost bit to indicate the sign of the number. 0 means a positive number, 1 means a negative number.  

## (Too) Simple Negatives

Lets try simply using the left hand bit as a sign indicator. We end up with these numbers.

0 = positive
1 = negative

**Too Simple Binary**
|Binary|Decimal|Binary|Decimal|
|---|---|---|---|
|0000|0|1000|-0|
|0001|1|1001|-1|
|0010|2|1010|-2|
|0011|3|1011|-3|
|0100|4|1100|-4|
|0101|5|1101|-5|
|0110|6|1110|-6|
|0111|7|1111|-7|

First off we've got two zeroes and one of them is negative. That's weird and it's not good, it means we'll need to check for both zeroes.  

How does addition work? What if we add a positive and negative number together?  

| 7 + -3 |||||
| --- | --- | --- | --- | --- |
|7| 0 | 1 | 1 | 1 |
|plus|||||
|-3| 1| 0 | 1 | 1 |
|equals|||||
|add "units" together (2<sup>0</sup>=1)||||1+1|
|||||10|
|carry the multiple of 2|||1|0|
|add "twos" together (2<sup>1</sup>=2)|||1+1+1|0|
|1+1+1=3, 3 in binary is 11|||11|0|
|carry the multiple of 2||1|1|1|
|add "fours" together (2<sup>2</sup>=4)||1+0+1|1|0|
|||10|1|0|
|carry the multiple of 2|1|0|1|0|
|add "fours" together (2<sup>2</sup>=4)|0+1+1|0|1|0|
||10|0|1|0|
|carry sets a flag|0|0|1|0|
|Sum|0|0|1|0|

7 + -3 = 2 ?!?!

So simple binary addition doesn't work if we simply use the left hand bit to indicate sign.  

## 1s Complement

Let's try a different approach. Lets say for a negative number we take the positive number and invert every bit - swap 1s for 0s and 0s for 1s.  

**1s Complement**
|Binary|Decimal|Binary|Decimal|
|---|---|---|---|
|0000|0|1111|-0|
|0001|1|1110|-1|
|0010|2|1101|-2|
|0011|3|1100|-3|
|0100|4|1011|-4|
|0101|5|1010|-5|
|0110|6|1001|-6|
|0111|7|1000|-7|

We've still got two zeroes, but how does the maths work out?  

| 7 + -3 |||||
| --- | --- | --- | --- | --- |
|7| 0 | 1 | 1 | 1 |
|plus|||||
|-3| 1| 1 | 0 | 0 |
|equals|||||
|add "units" together (2<sup>0</sup>=1)||||1+0|
|||||1|
|add "twos" together (2<sup>1</sup>=2)|||1+0|0|
||||1|1|
|add "fours" together (2<sup>2</sup>=4)||1+1|0|0|
|||10|1|1|
|carry the multiple of 2|1|0|1|1|
|add signs together|1+1|0|1|1|
||10|0|1|1|
|The carry here sets a flag|0|0|1|1|
|Sum|0|0|1|1|

7 + -3 = 3 ?!? Still not right. But watch what happens if we add a new rule. The rule is if after adding all the digits together the flag is set then add one to the sum. So we have an extra step.

| 7 + -3 |||||
| --- | --- | --- | --- | --- |
|...|...|...|...|
|carry flag set|0|0|1|1|
||0|0|1|1|
|+|||||
|0||0|0|1|
|=|||||
|||||1+1|
||||1|0|
||||1+1|0|
|||1|0|0|
||0+0|1|0|0|
||0|1|0|0|
|Sum|0|1|0|0|

7 + -3 = 4 ! Success

But we've still got two zeroes and that carry bit is a pain to deal with.  

## 2s Complement

Let's try 2s Complement. 2s Complement is 1s Complement + 1  

**2s Complement**
|Binary|Decimal|Binary|1s Comp|2s Comp : 1s Comp +1|
|---|---|---|---|---|
|0000|0|1111|-0|0000|
|0001|1|1110|-1|1111|
|0010|2|1101|-2|1110|
|0011|3|1100|-3|1101|
|0100|4|1011|-4|1100|
|0101|5|1010|-5|1011|
|0110|6|1001|-6|1010|
|0111|7|1000|-7|1001|
||||-8|1000|

Now both 0 and -0 are the same thing! How does the maths work out

| 7 + -3 |||||
| --- | --- | --- | --- | --- |
|7| 0 | 1 | 1 | 1 |
|plus|||||
|-3| 1| 1 | 0 | 1 |
|equals|||||
|add "units" together (2<sup>0</sup>=1)||||1+1|
|||||10|
||||1|0|
|add "twos" together (2<sup>1</sup>=2)|||1+0+1|0|
||||10|0|
|||1|0|0|
|add "fours" together (2<sup>2</sup>=4)||1+1+1|0|0|
|||11|0|0|
||1|1|0|0|
|add signs together (2<sup>2</sup>=4)|0+1+1|1|0|0|
||10|1|0|0|
||0|1|0|0|
|The carry here sets a flag|0|1|0|0|
|Sum|0|1|0|0|

7 + -3 = 4! Success and no faffing about with the addition.  

But remember those overflows, we know it is possible to add two numbers together and end up with a results that is too big to be stored. If we add 7+1 (or any positive number) the result cannot be stored in 4 bits. Similarly if we add -7 + any negative number the result cannot be stored correctly. Is there a way to detect this? Yes, and its very simple - there is a carry in to the sign bit and a carry out from the sign bit then the number has over or under flowed.  



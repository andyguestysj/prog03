---
title: Floating Point Numbers
permalink: /docs/bops-floats/
---

We've looked at integers, what happens with real numbers?  

We've looked at how real numbers could be stored in binary, is this what happens?  

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

No, the issue here is that we need to know where the decimal point is and if we fix its position then we end up with a limited range of possible numbers that can be stored - either a small difference between the lowest and highest number or a small precision (number of digits after the decimal point).  

### Scientific Notation

The solution comes from adapting scientific notation to binary.  

In scientific notation we store numbers in the format **X * 10<sup>Y</sup>**

**X** here is referred to as the *mantissa*, **Y** as the exponent.

This has a number of advantages. 
* We can store very large numbers : 300,000,000 becomes 3.0 * 10<sup>8</sup>
* We can store very small numbers : 0.000000000001 becomes 1.0 * 10<sup>-12</sup>
* It makes multiplying two numbers very easy. We multiply the mantissa and add the exponents.
  * 3.0 * 10<sup>8</sup> * 1.0 * 10<sup>-11</sup> 
  * = (3.0 * 1.0) * 10<sup>(8+ (-12))</sup>
  * = 3.0 * 10<sup>-4</sup>

#### Scientific Notation In Binary

First let's start by converting a decimal number to binary to see how this looks.  

10.75 -> 1010.11 in binary 

We put this in scientific notation by
* making the mantissa equal to the number with the decimal point moved to the left of the first 1 -> 0.101011
* making the exponent equal to the number of places the decimal point was moved (left is +ve, right is -ve) -> 4 -> 100 in binary
  
So how is this actually stored? Well its fiddly and hard to get your head round. It goes like this..

### Floating Point In Memory

A typical 32 bit floating-point is stored in memory with three fields
* sign
* exponent
* significand (mantissa)

```console
+-+--------+-----------------------+
| |        |                       |
+-+--------+-----------------------+
 ^    ^                ^
 |    |                |
 |    |                +-- significand(width- 23 bit) 
 |    |
 |    +------------------- exponent(width- 8 bit) 
 |
 +------------------------ sign bit(width- 1 bit)
 ```

**Sign**
* We know this from earlier, 0 = positive, 1 = negative.  
**Exponent**  
* The next 8 bits are used for the exponent which can be positive or negative, but instead of reserving another sign bit, they're encoded such that `1000 0000` represents `0`, so `0000 0000` represents `-128` and `1111 1111` represents `127`.
**Significand**  
* The remaining 23-bits used for the significand(AKA mantissa). Each bit represents a negative power of 2 countings from the left, so:

```console
01101 = 0 * 2^-1 + 1 * 2^-2 + 1 * 2^-3 + 0 * 2^-4 + 1 * 2^-5 
      = 0.25 + 0.125 + 0.03125 
      = 0.40625
```

#### Lets walk through converting a decimal number to a binary float.  
Adapted from [https://dev.to/visheshpatel/how-floating-point-no-is-stored-memory-47od]

Lets consider the float value 3.14(PI) as an example.

1. Sign: Zero here, as PI is positive!
2. Exponent Calculation
* `3` is `0011` in binary
* `0.14` is

```console
0.14 x 2 = 0.28, 0

0.28 x 2 = 0.56, 00

0.56 x 2 = 1.12, 001

0.12 x 2 = 0.24, 0010

0.24 x 2 = 0.48, 00100

0.48 x 2 = 0.96, 001000

0.96 x 2 = 1.92, 0010001

0.92 x 2 = 1.84, 00100011

0.84 x 2 = 1.68, 001000111

And so on . . .
```

* So, `0.14 = 001000111...`
* Add `3` + `0.14` -> 11.001000111... with exp  0 (3.14 * 2<sup>0</sup>)
* Now you only have to add the bias of `127` to the exponent `1` and store it(i.e. `128` = `1000 0000`)  `0:1000 0000:1100 1000 111...`
* Forget the top `1` of the mantissa (which is always supposed to be `1`, except for some special values, so it is not stored), and you get:  `0:1000 0000:1001 0001 111...`
* So our value of `3.14` would be represented as something like:

```console
    0 10000000 10010001111010111000011
    ^     ^               ^
    |     |               |
    |     |               +--- significand = 0.7853975
    |     |
    |     +------------------- exponent = 1
    |
    +------------------------- sign = 0 (positive)
```

* The number of bits in the exponent determines the range (the minimum and maximum values you can represent).

**Significand/Mantissa Notes**
* If you add up all the bits in the significand, they don't total `0.7853975`(which should be, according to 7 digit precision). They come out to `0.78539747`.
* There aren't quite enough bits to store the value exactly. we can only store an approximation.
* The number of bits in the significand determines the precision.
* 23-bits gives us roughly 6 decimal digits of precision. 64-bit floating-point types give roughly 12 to 15 digits of precision.
  
**Note Also**
* Some values cannot represent exactly no matter how many bits you use. Just as values like 1/3 cannot represent in a finite number of decimal digits, values like 1/10 cannot represent in a finite number of bits.
* Since values are approximate, calculations with them are also approximate, and rounding errors accumulate.

The code below will output the way a float is stored in memory.  

 <iframe height="400px" width="100%" src="https://replit.com/@andyguest/cFloatRepr?lite=true" scrolling="no" frameborder="no" allowtransparency="true" allowfullscreen="true" sandbox="allow-forms allow-pointer-lock allow-popups allow-same-origin allow-scripts allow-modals"></iframe>  

Don't worry about the details of this, you just need to understand that floats are stored in binary using scientific notation.  



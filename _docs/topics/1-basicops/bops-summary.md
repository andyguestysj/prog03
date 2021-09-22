---
title: Basic Operations - Summary
permalink: /docs/bops-summary/
---

### Why does all this matter?

1. The more you know about how computers actually work, the better you can understand and develop code.  
2. You *will* run in to situations where code doesn't do what you expect, sometimes they will be caused by the way numbers are stored
   * **Overflows** - if you add too much to an integer it will flip from positive to negative.
   * **Underflows** - if you subtract too much to an integer it will flip from negative to positive.
     * Both are bad when storing data and can cause havoc in loop counters
   * **Precision or rounding errors** - floats are seldom stored exactly and are stored to a limited number of significant digits, this can cause arithmetic answers to be very slightly incorrect. This very slight innaccuracy can build up over repeated operations.  
   * **Direct memory access** - sometimes we access memory directly (much of the rest of this module is about this), we need to how the memory is being used to understand its contents.

### 1/3

**Integers**
Hopefully you remember all about integer mathematics. It is basically normal mathematics but division works the way you first learned to divide. It doesn't deal with messy numbers, instead any division `a / b = x remainder y`.

This leads to computers evaluating `1/3 + 1/3 + 1/3` as `0` (Since `1/3 = 0 remainder 1`). 

**Floats**
With floats we deal with those numbers after the decimal place. We know, from maths, that `1/3` is `0.33333 recurring`. But we also know our floats can only store a limited amout of precision, and with binary it is impossible to store `1/3` exactly, in binary it is `0.010101 recurring`. Since we have limited precision we cannot keep recurring, we stop at some point so our `1/3` as a float is slightly less than `1/3`. Which means, using floats, `1/3 + 1/3 + 1/3` is ever so slightly less than one.  

**1/3 Cuteness**

`1/3` in binary is `0.010101 recurring`  
When you multiply by `2` in binary you simply mover the digits one space to the left.  
`2/3` in binary is `0.101010 recurring`  
`1/3 + 2/3` in binary is therefore `0.111111 recurring`  

So `1/3` is `0.333333 recurring` in decimal and `0.111111 recurring` in binary.  

You don't need to remember this, I just find it cute :-).



### Basic Operations  

We looked at the following

1. Binary Recap
  * Base 2 Notation
  * Addition
  * Base 16 Notation
2. Storing Integers
   * Unsigned Integers
   * Signed Integers
3. Storing Floating Point Numbers
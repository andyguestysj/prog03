---
title: Primitives Vs Objects
permalink: /docs/prim-obj/
---

### Primitives

In Java the simplest type of data structure we can use are simple variables. These simple variables store a single piece of information such as a number, a character or a true/false boolean value. We call these **primitives** or **primitive types**. All data stored in Java is ultimately stored in primitives.   

Java has eight primitive types: `boolean`, `byte`, `char`, `short`, `int`, `long`, `float` and `double`.   

[Definitions on Wikipedia](https://en.wikibooks.org/wiki/Java_Programming/Primitive_Types#:~:text=Primitive%20types%20are%20the%20most,of%20data%20manipulation%20in%20Java)  

Primitives are stored in the stack, in the frame for the method they are created in.

### Objects

Objects in Java tend to be a collection of data elements and methods. The data elements in an object may be primitives, collections of primitives (arrays), objects or collections of objects.  

Java tries to hide how objects are stored in memory to make coding easier. It seems like objects are stored just like primitives but they are stored in a different area of memory, the **heap**, and are accessed differently.

#### Wrapper Classes

Java provides a set of classes that each store a single value of a primitive type, along with methods for operating on/with it. These are known as **wrapper classes** and there is a wrapper class for each primitive variable.  

**Primitive** : `byte`, `short`, `int`, `long`, `float`, `double`, `boolean`, `char`  
**Wrapper**   : `Byte`, `Short`, `Integer`, `Long`, `Float`, `Double`, `Boolean`, `Character`  

The purpose of wrapper classes is to allow primitives to be treated as objects, allowing us to treat all data the same way in code.

### Primitives Vs Objects

Primitives and objects are stored in different locations in memory. Most of the time we will only notice the difference between the two when we pass them to methods as parameters.  

When we pass a primitive type to a method a local version of that primitive is created in the method (in the method's frame) and the value of the primitive is copied in to the local version. 

```int number = 1;
increaseNumber(number);

public int increaseNumber(int input)
{
    input++;
    return input;
}```

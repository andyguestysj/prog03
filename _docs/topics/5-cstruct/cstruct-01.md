---
title: C Data Structures
permalink: /docs/cstruct-01/
---

C doesn't have classes and objects, it isn't an object oriented programming language. 

C does allow you to define custom data *structures*. These structures can contain variables, arrays, even more data structures. You can think of a *structure* as like a class without any methods.  

## Defining A Structure

```c
struct [structure tag] {
    member definition;
    member definition;
    ...
    member definition;
} [one or more structure variables]
```

The `struct` keyword is used to create a structure.  
The `structure tag` is the name you give the structure - equivalent to a class name.  
The `structure variables` are the names of specific structure instances - equivalent to object names.  

Either `structure tag` or `structure variables` can be left out but not both.  

```c
struct Books {
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
};
```

The code above creates a *data structure type* called `Books`. `Books` can be used as a variable type.

```c
struct Books Book1;
struct Books Book1;
```

Alternatively you can create a structure without naming it, using it to create variables without creating a data structure type that can be reused.  

```c
struct {
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
} book1, book2;
```

And you can create a named structure and make variables of that type all at the same time.  

```c
struct Books {
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
} book1, book2;
```

However you create your structure you can use `typedef` to define a type so you don't have to use the `struct` keyword everytime you want to create a variable of your data structure.  

```c
typedef struct Books Book;

Book book1, book2;
```

And finally you can bring all these together to make a new type in one.  

```c
typedef struct Book {
   char title[50];
   char author[50];
   char subject[100];
   int book_id;
} Book;
    
Book book1;
Book book2;
```

C likes to give you options!

## Accessing Struct Members

We access the members of a structure using the **member access operator (.)**.  

```c
#include <stdio.h>
#include <string.h>

typedef struct Book {
   char title[50];
   char author[50];
   char subject[100];
   int book_id;
} Book;

int main() {

  Book book1;

  // Store data in book1
  strcpy(book1.title, "Lovecraft Country");
  strcpy(book1.author, "Matt Ruff");
  strcpy(book1.subject, "Horror");
  book1.book_id = 19334;

}
```

Similarly you can retrieve the values 

```c
  printf("Title : %s\n", book1.title);
  printf("Author : %s\n", book1.author);
  printf("Subject : %s\n", book1.subject);
  printf("Book ID : %d\n", book1.book_id);
```

## Structures as Function Arguments

You can pass structures to function the same way you pass any other variable or pointer.  

```c
#include <stdio.h>
#include <string.h>

  typedef struct Book {
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
} Book;

void printBook( Book book );

int main(void) {
  
  Book book1;
  strcpy(book1.title, "Lovecraft Country");
  strcpy(book1.author, "Matt Ruff");
  strcpy(book1.subject, "Horror");
  book1.book_id = 19334;

  printBook(book1);


  return 0;
}

void printBook( Book book )
{
  printf("Title : %s\n", book.title);
  printf("Author : %s\n", book.author);
  printf("Subject : %s\n", book.subject);
  printf("Book ID : %d\n", book.book_id);
}
```

If you do not use the `typedef` keyword you will need to use `struct` throughout.  

```c
#include <stdio.h>
#include <string.h>

  struct Book {
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
};

void printBook( struct Book book );

int main(void) {
  
  struct Book book1;
  strcpy(book1.title, "Lovecraft Country");
  strcpy(book1.author, "Matt Ruff");
  strcpy(book1.subject, "Horror");
  book1.book_id = 19334;

  printBook(book1);


  return 0;
}

void printBook( struct Book book )
{
  printf("Title : %s\n", book.title);
  printf("Author : %s\n", book.author);
  printf("Subject : %s\n", book.subject);
  printf("Book ID : %d\n", book.book_id);
}
```

## Pointers to Structures

You can define pointers to structures in the same way you define a pointer to any other variable.

```c
#include <stdio.h>
#include <string.h>

typedef struct Book {
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
};

int main(void) {
  
  Book book1;
  Book *book1_ptr;

  *book1_ptr = &book1;
}
```

We can access the members of a structure directly from the pointer using the **indirection operator ->**.  

```c
#include <stdio.h>
#include <string.h>

typedef struct Book {
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
};

void printBook( Book *book );


int main(void) {
  
  Book book1;
  Book *book1_ptr;
  *book1_ptr = &book1;

  strcpy(book1.title, "Lovecraft Country");
  strcpy(book1.author, "Matt Ruff");
  strcpy(book1.subject, "Horror");
  book1.book_id = 19334;

  printBook(book1_ptr);

}

void printBook( struct Book book )
{
  printf("Title : %s\n", book.title);
  printf("Author : %s\n", book.author);
  printf("Subject : %s\n", book.subject);
  printf("Book ID : %d\n", book.book_id);
}
```

We can, of course, skip creating a pointer variable and get the address directly from the struct variable when we need it.  

```c
#include <stdio.h>
#include <string.h>

typedef struct Book {
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
};

void printBook( Book *book );


int main(void) {
  
  Book book1;
  
  strcpy(book1.title, "Lovecraft Country");
  strcpy(book1.author, "Matt Ruff");
  strcpy(book1.subject, "Horror");
  book1.book_id = 19334;

  printBook(&book);

}

void printBook( struct Book book )
{
  printf("Title : %s\n", book.title);
  printf("Author : %s\n", book.author);
  printf("Subject : %s\n", book.subject);
  printf("Book ID : %d\n", book.book_id);
}
```


## Structs within Structs

The members within a struct do not need to be simple primitive variables, they can also be other structs you have created.  

For example we could create a struct to store the corners of a `square` like this :

```c
typedef struct square {
    float corner_1_x;
    float corner_1_y;
    float corner_2_x;
    float corner_2_y;
    float corner_3_x;
    float corner_3_y;
    float corner_4_x;
    float corner_4_y;
} square;
```
but it is very clumsy. We would be better first defining a `point` that contains an x and a y value and using that in `square`.  

```c
typedef struct point {
    float x;
    float y;
} point;

typedef struct square {
    point corner1;
    point corner2;
    point corner3;
    point corner4;
} square;
```

Of course we'd be better off still is we used an array.  

```c
typedef struct point {
    float x;
    float y;
} point;

typedef struct square {
    point corners[4];
} square;
```

We use it something like this  

```c
#include <stdio.h>

typedef struct point {
    float x;
    float y;
} point;

typedef struct square {
    point corners[4];
} square;

void setPoint(square,int,float,float);
void printSquare(square);

int main(void) {

  square my_square;

  setPoint(my_square,0,1.0,1.0);
  setPoint(my_square,1,4.0,1.0);
  setPoint(my_square,2,4.0,4.0);
  setPoint(my_square,3,1.0,4.0);

  printSquare(my_square);
  return 0;
}

void setPoint(square a_square,int corner,float x,float y)
{
  a_square.corners[corner].x = x;
  a_square.corners[corner].y = y;  
}

void printSquare(square a_square)
{
  for (int i=0; i<4; i++)
  {
    printf("Corner %d (%f,%f)\n", i, a_square.corners[i].x, a_square.corners[i].y);
  }
}
```

which gives us the output 

```console
Corner 0 (0.000000,0.000000)
Corner 1 (0.000000,0.000000)
Corner 2 (0.000000,0.000000)
Corner 3 (-0.000000,0.000000)
```

That's the wrong output! What's gone wrong, why aren't we setting the values?  

Lets add the line `printf("Corner %d (%f,%f)\n", corner, a_square.corners[corner].x, a_square.corners[corner].y);` to the end of the setPoint function and see what happens.  

```console
Corner 0 (1.000000,1.000000)
Corner 1 (4.000000,1.000000)
Corner 2 (4.000000,4.000000)
Corner 3 (1.000000,4.000000)
Corner 0 (0.000000,0.000000)
Corner 1 (0.000000,0.000000)
Corner 2 (0.000000,0.000000)
Corner 3 (-0.000000,0.000000)
```

The first time the corners are printed out (from `setPoint`) the values are set but when we print them from `printSquare` the values have been rest to zero. What is going on?

Well the problem here is we pass the `square` data structure **by value**. That means, just like with primitive variables, a new local value is created and the values are copied in to it. It is the local variable version `a_square` that is changed, not the original on in `my_square`. If we want to change the values of a structure in a function we have to pass a pointer to the address of that structure variable to the function.  

```c
#include <stdio.h>

typedef struct point {
    float x;
    float y;
} point;

typedef struct square {
    point corners[4];
} square;

void setPoint(square*,int,float,float);
void printSquare(square);

int main(void) {

  square my_square;

  setPoint(&my_square,0,1.0,1.0);
  setPoint(&my_square,1,4.0,1.0);
  setPoint(&my_square,2,4.0,4.0);
  setPoint(&my_square,3,1.0,4.0);

  printSquare(my_square);
  return 0;
}

void setPoint(square *a_square,int corner,float x,float y)
{
  a_square->corners[corner].x = x;
  a_square->corners[corner].y = y;
}

void printSquare(square a_square)
{
  for (int i=0; i<4; i++)
  {
    printf("Corner %d (%f,%f)\n", i, a_square.corners[i].x, a_square.corners[i].y);
  }

}
```

Now our `setPoint` function works as intended.

```console
Corner 0 (1.000000,1.000000)
Corner 1 (4.000000,1.000000)
Corner 2 (4.000000,4.000000)
Corner 3 (1.000000,4.000000)
```

[Square & Point code in replit.com](https://replit.com/@andyguest/cStructSquare)



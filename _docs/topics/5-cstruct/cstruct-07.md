---
title: Stacks
permalink: /docs/cstruct-07/
---

A *stack* is a specific type of linked list. It is a data structure where data is added and removed at the end of its linked list. It operates on a Last In First Out principle.  

Think of a stack of plates. New plates are added to the top of the stack. When someone takes a plate they take the plate from the top of the stack.  

![Pushing and Popping a Stack](/assets/img/topic4/stack.jpg "Pushing and Popping a Stack")  

A stack can be implemented in many ways, here we will look at a linked last approach.  

## Stack Components

### Node Structure

We'll need a node structure. This is just our linked list node structure.

```c
typedef struct node {
    int data;
    struct node* next;
}node;
```

### Operations

We've already seen the two most fundamental operations of a stack
* **push()** − pushing (storing) an element on the stack.
* **pop()** − removing (accessing) an element from the stack.

To use the stack we'll need two more functions
* **peek()** − get the top data element of the stack, without removing it.
* **isEmpty()** − check if stack is empty.

And some basic functionality like creating a stack and initialising it.

## How a stack works

A stack begins as a simple empty linked list with a **head** pointer pointing to `NULL`.

![Empty Stack](/assets/img/topic4/stack-init.jpg "Empty Stack")  

Data is pushed to the stack.  

![Push first item to stack](/assets/img/topic4/stack-push-first-to-stack.jpg "Push first item to stack")  

Data is always pushed to the start of the stack.

![Push second item to stack](/assets/img/topic4/push-second-to-stack.jpg "Push second item to stack")  

You should think of the *head* of a stack as being the top of a stack.

When we pop an item from the stack we remove the top entry of the stack. The item popped is returned by the pop() function.

![Pop from the stack](/assets/img/topic4/stack-pop.jpg "Pop from the stack")  

## Stack Code

The code below is for a stack of integers. It will need to be modified to store a different data type.  

```c
#include<stdbool.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* next;
}node;
 
// Append the new data to the start of the stack
void push(int data, node** stack){
    // Create a new node
    node* new_node = (struct node*)malloc(sizeof(node)); 

    // Store the data in the new node
    new_node->data = data; 
    
    // Point the new node's next at the current top of the stack
    new_node->next = *stack;  
    
    // Make new node the top of the stack
    (*stack) = new_node;  
}

// Remove data from the top of the stack and return it
int pop(node** stack){
    if(*stack != NULL)
    {
        int popped = (*stack) -> data;
        node* tempPtr = *stack;
        *stack = (*stack) -> next;
        free(tempPtr);
        return popped;
    }
    else
    {
        printf("The stack is empty.\n");
        return -1;
    }
}

// Display the element at the top of the stack
// should always test for isEmpty()  first
int peek(node* stack){
    if(stack != NULL){
        return stack -> data;
    }
    else
    {
        printf("The stack is empty.\n");
        return -1;
    }
}

bool isEmpty(node* stack){
    if(stack != NULL){
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    node *Stack = NULL;

    push(1,&Stack);
    push(2,&Stack);
}


```

This code is available at [https://replit.com/@andyguest/cStack](https://replit.com/@andyguest/cStack)  



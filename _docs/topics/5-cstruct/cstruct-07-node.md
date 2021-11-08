---
title: Stacks - Node Based
permalink: /docs/cstruct-07-node/
---

A *stack* is a specific type of linked list. It is a data structure where data is added and removed at the end of its linked list. It operates on a Last In First Out principle.  

Think of a stack of plates. New plates are added to the top of the stack. When someone takes a plate they take the plate from the top of the stack.  

## Stack Code

The code below is for a stack of integers. It will need to be modified to store a different data type.  

```c
#include<stdbool.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* next;
}node;
 
// function to create a new note & return a pointer to it
node *NewNode(int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

// Append the new data to the start of the stack
void push(node *new_node, node** stack){
    // Point the new node's next at the current top of the stack
    new_node->next = *stack;  
    
    // Make new node the top of the stack
    (*stack) = new_node;  
}

// Remove data from the top of the stack and return it
node* pop(node** stack){
    if(*stack != NULL)
    {
        node* tempPtr = *stack;
        *stack = (*stack) -> next;
        return tempPtr;
    }
    else
    {
        printf("The stack is empty.\n");
        return NULL;
    }
}

// Display the element at the top of the stack
// should always test for isEmpty()  first
node* peek(node* stack){
    if(stack != NULL){
        return stack;
    }
    else
    {
        printf("The stack is empty.\n");
        return NULL;
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

    push(NewNode(1),&Stack);
    push(NewNode(2),&Stack);

    printf("%d\n",pop(&Stack)->data);
    printf("%d\n",pop(&Stack)->data);
}


```

This code is available at [https://replit.com/@andyguest/cStackNode](https://replit.com/@andyguest/cStackNode)  



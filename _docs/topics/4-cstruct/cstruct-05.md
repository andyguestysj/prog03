---
title: Doubly Linked Lists
permalink: /docs/cstruct-05/
---

Previously we looked at a linked list made up of nodes where each node contains data and a pointer to the next entry in the list.

![A Linked List](/assets/img/topic4/linklist.jpg "A Linked List")  

This structure has a number of advantages - it can grow and shrink as needed, it is easy to insert nodes at any point in the list, we can access any of the data providing we know the address of the first element in the list. There is one big disadvantage to the linked list though - if we want to access a node we have to start from the first node and work our way through the list.

It would be helpful if we could also go backwards in the list, go from a node to the one before it, not just the one after it. This is what a **doubly linked list** lets us do.

## Doubly Linked List

A *doubly linked list* (DLL) is a linked list with one addition, each node has a pointer to the previous node in the list.

![A Doubly Linked List](/assets/img/topic4/DLL1.png "A Doubly Linked List")  

```c
/* Node of a doubly linked list */
struct Node { 
    int data; 
    struct Node* next; // Pointer to next node in DLL 
    struct Node* prev; // Pointer to previous node in DLL 
};
```

The addition of the *prev* pointer allows us to move to the previous node from the current one. This ability to back track is advantageous because - 
* we can traverse forwards and backwards in a DLL
* insertion is easier - we don't need to keep track of the previous node, we can get it from the current one.
* likewise deletion is easier

Disadvantages
* Nodes are slightly larger, we are storing an extra pointer
* Actions often require the modification of two pointers per node rather than one with a singly linked list

## DLL Code

### New Node

<div class="row">
<div class="col-md-6"  markdown="1">
```c
void main()  
{  
  int i=1;  
}
```
</div>
<div class="col-md-6"  markdown="1">
</div>
</div>

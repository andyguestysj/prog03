---
title: Doubly Linked Lists
permalink: /docs/cstruct-06/
---

(Adapted from geeksforgeeks.org)

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

### Node Structure

DLLs have an extra pointer to `prev` node.  

<div class="row">
<div class="col-md-6"  markdown="1">
**Doubly Linked List**

```c
typedef struct Node { 
    int data; 
    struct Node* next; // Pointer to next node in DLL 
    struct Node* prev; // Pointer to previous node in DLL 
}Node;
```
</div>
<div class="col-md-6"  markdown="1">
**Singly Linked List**

```c
typedef struct Node { 
    int data; 
    struct Node* next; // Pointer to next node in DLL     
}Node;
```
</div>
</div>

### Heads

No difference here.  

<div class="row">
<div class="col-md-6"  markdown="1">
**Doubly Linked List**

```c
Node *head = NULL;
```

</div>
<div class="col-md-6"  markdown="1">
**Singly Linked List**

```c
Node *head = NULL;
```

</div>
</div>

### New Node

Creating a new node, that is separate from the list is much the same.  

<div class="row">
<div class="col-md-6"  markdown="1">
**Doubly Linked List**

```c
Node *NewNode(int data)
{
    Node *new = (Node *)malloc(sizeof(Node));
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
}
```

</div>
<div class="col-md-6"  markdown="1">
**Singly Linked List**

```c
Node *NewNode(int data)
{
    Node *new = (Node *)malloc(sizeof(Node));
    new->data = data;
    new->next = NULL;
}
```

</div>
</div>

### Add Node To List
Here's where the differences start to show. When we add a node to the list we have to ensure its `next` and `prev` pointers are set correctly. We also have to ensure the `next` pointer of the node *before* our new node's new position is correctly *and* we have to ensure the `prev` of the node *after* the new one is set correctly.

#### At Start

Inserting at the start is a simple process, we just need to ensure the `prev` pointer of the old first node is changed correctly.  

![Insert at start of DLL](/assets/img/topic4/DLL_add_front1.png "Insert at start of DLL")  

<div class="row">
<div class="col-md-6"  markdown="1">
**Doubly Linked List**

```c
void AddNewNodeAtStart(Node** head_ref, int data)
{
    Node *new = NewNode(data);

    // new will be the new first node. 
    // Its next should point to the old head
    // Its prev should point to NULL (nothing before the first node)
    new->next = (*head_ref);
    new->prev = NULL;

    if(*head_ref==NULL)
    { 
        // List was empty, so just need to change the head to point to the new node.
        (*head_ref) = new;        
    }
    else
    {
        // List was not empty
        // First change the prev of the old head to point to the new node
        (*head_ref)->prev = new;
        // Then change the head to point to the new node
        (*head_ref) = new;        
    }
}
```
</div>
<div class="col-md-6"  markdown="1">
**Singly Linked List**

```c
void AddNewNodeAtStart(Node** head_ref, int data)
{
    Node *new = NewNode(data);

    // new will be the new first node. 
    // Its next should point to the old head
    // Its prev should point to NULL (nothing before the first node)
    new->next = (*head_ref);
    new->prev = NULL;

    // Now update head to point to the new node.
    (*head_ref) = new;            
}
```
</div>
</div>

#### Insert After

Inserting a node after another node is relatively simple. There are lots of pointers you have to be careful to link up correctly though.  

![Insert after node](/assets/img/topic4/DLL_add_middle1.png "Insert after node")  

<div class="row">
<div class="col-md-6"  markdown="1">
**Doubly Linked List**

The code below assumes you have a function `Node* FindNode(Node *head, int search_value)` that returns a pointer to the first node in the list that has a `value` of `search_value`.

```c
void InsertNodeAfter(Node* prev_node, int data)
{
    Node *new = NewNode(data);

    if (prev_node==NULL)
    {
        printf("prev_node invalid\n");
        return;
    }
    
    // Set up the links in new
    new->prev = prev_node;
    new->next = prev_node->next;

    // Connect prev_node to new
    prev_node->next = new;

    if (new->next!=NULL)
    { 
        // here's the trippy one - we need to set the node after new's prev to point to new.
        // the node after new is new->next, for the prev is node->next->prev!
        new->next->prev = new;
    }
}
```

</div>
<div class="col-md-6"  markdown="1">
**Singly Linked List**

```c
void InsertNodeAfter(Node* prev_node, int data)
{
    Node *new = NewNode(data);

    if (prev_node==NULL)
    {
        printf("prev_node invalid\n");
        return;
    }
    
    // Set up the links in new    
    new->next = prev_node->next;
    prev_node->next = new;
}
```

</div>
</div>


#### Insert At End

Inserting a node after another node is relatively simple. There are lots of pointers you have to be careful to link up correctly though.  

![Insert node at end](/assets/img/topic4/DLL_add_end1.png "Insert node at end")  

<div class="row">
<div class="col-md-6"  markdown="1">
**Doubly Linked List**

```c
void InsertNodeAtEnd(Node** head_ref, int data)
{
    Node *new = NewNode(data);

    if (*head_ref==NULL)
    {
        // List is empty, same as insert at start
        new->prev=NULL;
        (*head_ref) = new;
        return;
    }

    // Get the first node address - we'll traverse to end from here
    Node *last = *head_ref; 

    // Traverse list till you get to the last node, the node where ->next==NULL
    while (last->next != NULL)
    {
        last = last->next;
    }

    // Change next of last node to new node
    last->next = new;
    // Change prev of new to point to last
    new->prev = last;
}
```

</div>
<div class="col-md-6"  markdown="1">
**Singly Linked List**

```c
void InsertNodeAtEnd(Node** head_ref, int data)
{
    Node *new = NewNode(data);

    if (*head_ref==NULL)
    {
        // List is empty, same as insert at start        
        (*head_ref) = new;
        return;
    }

    // Get the first node address - we'll traverse to end from here
    Node *last = *head_ref; 

    // Traverse list till you get to the last node, the node where ->next==NULL
    while (last->next != NULL)
    {
        last = last->next;
    }

    // Change next of last node to new node
    last->next = new;
}
```

</div>
</div>



### Deleting Nodes

Deleting nodes is a matter of ensuring the links are correctly changed and then freeing up the memory used by the node to be deleted.  

![Deleting a node from a DLL](/assets/img/topic4/dll-del.gif "Deleting a node from a DLL")  

Three possible cases
1. Node to be deleted is the fist node
2. Node to be deleted is the last node
3. Node to be deleted is another node
and a fourth case, that should be prevented
4. Node to be deleted is not in the list

**Algorithm** 
* Let the node to be deleted be del.  
* If node to be deleted is head node, then change the head pointer to next current head. 

```c
if headnode == del then
      headnode =  del.nextNode
```

* Set next of previous to del, if previous to del exists. 

```c
if del.nextNode != none 
      del.nextNode.previousNode = del.previousNode 
```

* Set prev of next to del, if next to del exists.

```c
if del.previousNode != none 
      del.previousNode.nextNode = del.next
```

We can do this with the code below.  

```c
void deleteNode(Node** head_ref, Node* del) 
{ 
    /* base case */
    if (*head_ref == NULL || del == NULL) 
        return; 
 
    /* If node to be deleted is head node */
    if (*head_ref == del) 
        *head_ref = del->next; 
 
    /* Change next only if node to be 
    deleted is NOT the last node */
    if (del->next != NULL) 
        del->next->prev = del->prev; 
 
    /* Change prev only if node to be 
    deleted is NOT the first node */
    if (del->prev != NULL) 
        del->prev->next = del->next; 
 
    /* Finally, free the memory occupied by del*/
    free(del); 
    return; 
} 
```


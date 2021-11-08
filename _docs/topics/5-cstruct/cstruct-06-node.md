---
title: Doubly Linked Lists Node Based
permalink: /docs/cstruct-06-node/
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

### Heads

No difference here.  

```c
Node *head = NULL;
```

### New Node

Creating a new node, that is separate from the list is much the same.  

```c
Node *NewNode(int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;

    return new_node;
}
```

### Add Node To List
Here's where the differences start to show. When we add a node to the list we have to ensure its `next` and `prev` pointers are set correctly. We also have to ensure the `next` pointer of the node *before* our new node's new position is correctly *and* we have to ensure the `prev` of the node *after* the new one is set correctly.

#### At Start

Inserting at the start is a simple process, we just need to ensure the `prev` pointer of the old first node is changed correctly.  


```c
void AddNewNodeAtStart(Node** head_ref, Node *new_node)
{
    // new_node will be the new first node. 
    // Its next should point to the old head
    // Its prev should point to NULL (nothing before the first node)

    new_node->next = (*head_ref);

    if(*head_ref==NULL)
    { 
        // List was empty, so just need to change the head to point to the new node.
        (*head_ref) = new_node;        
    }
    else
    {
        // List was not empty
        // First change the prev of the old head to point to the new node
        (*head_ref)->prev = new_node;
        // Then change the head to point to the new node
        (*head_ref) = new_node;        
    }
}
```

#### Insert After

Inserting a node after another node is relatively simple. There are lots of pointers you have to be careful to link up correctly though.  

```c
void InsertNodeAfter(Node* prev_node, Node *new_node)
{

    // we've already for prev_node, the node we want to insert after
    if (prev_node==NULL)
    {
        printf("prev_node invalid\n");
        return;
    }
    
    // Set up the links in new
    new_node->prev = prev_node;
    new_node->next = prev_node->next;

    // Connect prev_node to new
    prev_node->next = new_node;

    if (new_node->next!=NULL)
    { 
        // here's the trippy one - we need to set the node after new's prev to point to new.
        // the node after new is new->next, for the prev is node->next->prev!
        new_node->next->prev = new_node;
    }
}
```

#### Insert At End

Inserting a node after another node is relatively simple. There are lots of pointers you have to be careful to link up correctly though.  

```c
void InsertNodeAtEnd(Node** head_ref, Node *new_node)
{

    if (*head_ref==NULL)
    {
        // List is empty, same as insert at start
        new_node->prev=NULL;
        (*head_ref) = new_node;
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
    last->next = new_node;
    // Change prev of new to point to last
    new_node->prev = last;
}
```



### Deleting Nodes

Deleting nodes is a matter of ensuring the links are correctly changed and then freeing up the memory used by the node to be deleted.  

 
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


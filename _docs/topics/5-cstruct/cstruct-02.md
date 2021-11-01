---
title: C Linked Lists
permalink: /docs/cstruct-02/
---

In C we can create very flexible ways of storing data using a combination of pointers and data structures.  

We call these flexible ways of storing data **linked lists**.  

A linked list is made up of data structures, where a part of each structure is a link to the next entry in the list.  

![A simple linked list](/assets/img/topic4/linklist.jpg "The A simple linked list")

**Linked List Terminology**
* **node** - a data structure in a linked list - consists of data and one or more pointers to other entries in the linked list
* **head** - the first node in a linked list -  typically this is a pointer to the first node in the list
* **tail** - the last node in a linked list - the tail's *next* pointer is set to `NULL`
* **next** - a pointer connecting a node in a linked list to the next node in the list

The example above is the simplest version of a linked list. A *pointer* to the first *node* is stored in *head*. Each *node* in the list has a data member called *next* which stores a *pointer* to the next *node* in the list, except for the last *node* where it's *next* is set to `NULL`.  

Think of a simple linked list like this as a chain. Each link in the train is connected to the link before and after it. Data is stored in each link and part of that data is the address of the next link. In our code we store the address of the first link in the chain and then let each link keep track of the address of the next link.  

## Node
A node contains any amount of data and a pointer to the next node in the list. (Other types of linked lists may have more pointers to other nodes).  
The simplest possible node, storing a single integer value, would look something like this  

```c
typedef struct node {
  int val;

  struct node *next;
} node;
```

In this case the only data is an integer named `val`. `next` is a pointer to another *node* in the form of another struct of the same type. 

We can make a more useful linked list using our `Book` type from the previous page.

```c
typedef struct Book {
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;

   next  *Book;
} Book;
```

Here each node stores the details about a book and a pointer to the next book in the list.  

## Creating A New List

To create a new list we simply create a pointer variable called head and set it to `NULL`. 

```c
node *head = NULL;
```

We now have an empty list.  

### Creating a new node

When we want to create a new node we need to set aside space in memory that is big enough to hold one of the structs. We then set our data values as required and set the *next* pointer to `NULL`.  

```c
#include<stdlib.h>                    // We required stdlib.h for malloc

node *new_node = NULL;                // Create a pointer to a node structure, set it to NULL for safety
new_node =malloc(sizeof(node));       // Set aside space in memory for a node structure. If this fails new_node will be set to NULL

if (new_node != NULL)                 // Always ensure the node exists before accessing it.
{
  new_node->val = 1;                  // Set data values as required
  new_node->next = NULL;              // Set next (and any other pointers to NULL)
} 
```

A new node function might look something like this.  

```c
node* newNode(int value)
{
  node *new_node = NULL;                // Create a pointer to a node structure, set it to NULL for safety
  new_node =malloc(sizeof(node));       // Set aside space in memory for a node structure. If this fails new_node will be set to NULL

  if (new_node != NULL)                 // Always ensure the node exists before accessing it.
  {
    new_node->val = value;              // Set data values as required
    new_node->next = NULL;              // Set next (and any other pointers to NULL)
  } 
  return new_node;
}
```

If we were using our `Book` type.  

```c
Book* newBookNode(char title[50], char author[50], char subject[100], int ID)
{
  Book *new_node = NULL;      
  new_node =malloc(sizeof(Book));

  if (new_node != NULL)          
  {
    strcpy(new_node.title, title);
    strcpy(new_node.author, author);
    strcpy(new_node.subject, subject);
    new_node.book_id = ID;    

    new_node->next = NULL;       
  } 
  return new_node;
}
```



## Traversing the list

To traverse a list, that is to iterate through the list, we start at the `head` and keep moving through the *nodes* by using the `next` pointer until `next == NULL` and we have reached the last node.  

```c
node *temp = head;  // always work with a copy of head!

while (temp->next != NULL)   // If next is NULL we are on the last entry in the list (or we've broken our list!)
{
  temp = temp->next;         // Change our temp pointer from the current one to temp->next - "moving" us on to the next node
}
```

The code above does nothing, it just moves through the list. If we wanted to print out every value in order we would do this -  

```c
node *temp = head;  // always work with a copy of head!

while (temp->next != NULL)   // If next is NULL we are on the last entry in the list (or we've broken our list!)
{
  printf("%d\n",temp->val);
  temp = temp->next;         // Change our temp pointer from the current one to temp->next - "moving" us on to the next node
}
```

## Adding A New Node To The End Of The List

New nodes are typically added to the end of the list. To do this we traverse to *tail*, the end of the list, create a new node and connect the next of the *tail* to the new node, making the new node in to the new *tail*.  

![Insert at end of Linked List](/assets/img/topic4/Linkedlist_insert_last.png "Insert at end of Linked List")

Note that this will not work with an empty list. Add the first item with `newNode()`.  

```c
node* newNode(int value)
{
  node *new_node = NULL;                // Create a pointer to a node structure, set it to NULL for safety
  new_node =malloc(sizeof(node));       // Set aside space in memory for a node structure. If this fails new_node will be set to NULL

  if (new_node != NULL)                 // Always ensure the node exists before accessing it.
  {
    new_node->val = value;              // Set data values as required
    new_node->next = NULL;              // Set next (and any other pointers to NULL)
  } 
  return new_node;
} 

void addNodeToEndOfList(node *start, int value){   // and any other data 

  node *temp = start;
  while (temp->next != NULL)   // If next is NULL we are on the last entry in the list (or we've broken our list!)
  {    
    temp = temp->next;         // Change our temp pointer from the current one to temp->next - "moving" us on to the next node
  } 

  temp->next = newNode(value);

}

int main(){
  node *head = NULL;    // start with an empty list

  newNode(1);
  addNodeToEndOfList(head, 5);
  addNodeToEndOfList(head, 2);
  addNodeToEndOfList(head, 7);

  // The list should have four entries in it
  // [head]->[1]->[5]->[2]-[7]

}
```

An alternative addNodeToEndOfList that takes a pointer to head (a pointer to a pointer) rather than head itself which will work with an empty list

```c
void addNodeToEndOfListAlt(node **start, int value){   // and any other data 

  node *new_node = newNode(value);
  node *temp = *start;

  // list is empty
  if (*start==NULL)
  {
    *start = new_node;
    return;
  }

  while (temp->next != NULL)   // If next is NULL we are on the last entry in the list (or we've broken our list!)
  {    
    temp = temp->next;         // Change our temp pointer from the current one to temp->next - "moving" us on to the next node
  } 
  temp->next = new_node;
  return;
  

}
```

## Adding A New Node To The Start Of The List

Adding an entry to the start of the list is faster since we don't need to traverse the list first but riskier, we have to be careful to connect things up properly, the `next` of the new node as to point to the previous `head` value and then the `head` value has to point to the new node.

![Insert at start of Linked List](/assets/img/topic4/Linkedlist_insert_at_start.png "Insert at start of Linked List")

```c
  node *head = NULL;    // start with an empty list

  // So the list isn't empty
  newNode(5);
  addNodeToEndOfList(head, 2);

  // create a new node temp->4->NULL
  node *temp = newNode(4); 
  // set temp's next to head
  temp->next = head;
  // temp->4->5->2->NULL
  // set head equal to temp
  head = temp;
  // head->4->5->2->NULL
```

As a function there are two ways of doing this.

We can return the address of the new node value to store it in head

```c 
node *AddNodeToStartOfList(node *start, int value)
{
   node *temp = newNode(value); 
   temp->next = start;
   return temp;
}

head = AddNodeToStartOfList(head,4);
```

Alternatively we can pass a pointer to `head` and update it within the function

```c
void AddNodeToStartOfList(node **ptr_to_start, int value)
{
   node *temp = newNode(value); 
   temp->next = *ptr_to_start;
   *ptr_to_start = temp;
}

AddNodeToStartOfList(&head,4);
```

## Adding A New Node In The Middle of The List

Linked lists are flexible enough to allow you to insert entries directly in to the middle of the list.

![Insert in middle of Linked List](/assets/img/topic4/Linkedlist_insert_middle.png "Insert in middle of Linked List")

```c
void insertNode(node* head, int value)
{
  node *temp = head;
  node *before = NULL;
  node *after = NULL;

  // traverse till you are sitting on the node you want to insert after
  // this example inserts after the second node but any method is viable

  temp = temp->next;
  temp = temp->next;
  before = temp;      // Keep a pointer to the node that will be before the new node
  after = temp->next; // Keep a pointer to the node that will be after the new node

  temp = newNode(value);

  before->next = temp; // connect before to the new node
  temp->next = after;  // connect the new node to the after node
}
```

The hardest part of inserting a node into a linked list is finding the correct place to insert it. Otherwise it is just a matter of making sure it connects up properly.  

## Removing a Node

Removing a node is a little tricky, you have to find the node you want to remove, safely connect the node before it to the node after it, and then delete the node, freeing up the memory.  

The difficulty comes in a couple of different places. The node we want to remove might be the first one. If that is the case then we have to pass a pointer to `head` (a pointer to a pointer) rather than the `head` pointer itself.  

By the time we have found the node we want to remove our temp pointer has move on past the previous node so we always need to keep track of the previous node separately.  

Finally this code will only remove the first instance of `value` in the list.  

```c
void deleteNode(struct Node **head_ptr, int value) 
{ 
    // Store head node 
    node *temp = *head_ref // make temp = head
    node *prev = NULL; 
  
    // If head node itself holds the value to be deleted 
    if (temp != NULL && temp->val == value) 
    { 
        *head_ref = temp->next;   // Changed head 
        free(temp);               // free old head 
        return; 
    } 
  
    // Search for the value to be deleted, keep track of the 
    // previous node as we need to change 'prev->next' 
    while (temp != NULL && temp->val != value) 
    { 
        prev = temp; 
        temp = temp->next; 
    } 
  
    // If value was not present in linked list 
    if (temp == NULL) return; 
  
    // If we are here then we are on the node to be deleted
    // Unlink the node from linked list 
    prev->next = temp->next; 
  
    free(temp);  // Free memory 
} 
```

![Deletion from Linked List](/assets/img/topic4/Linkedlist_deletion.png "Deletion from Linked List")

## Swapping Two Nodes Round By Value

The easiest way to swap two nodes around is to swap the values within the nodes around. In our `node` example with only a single integer value this is trivially easy.  

```c
void SwapNodesByValue(node *node1, *node2)
{
  int temp;
  temp = node1->val;
  node1->val = node2->val;
  node2->val = temp;
}
```


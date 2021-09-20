---
title: Pointers To Pointers
permalink: /docs/cstruct-05/
---

*An interlude*

Pointers to Pointers are confusing. Hopefully this page will help clarify them.  

NB this page refers to nodes and Node because we are looking at linked lists. `Node` can be replaced by any struct type and it still works the same.  

All the examples below use the following struct.  

```c
typedef struct Node { 
    int data; 
    struct Node* next;     
} Node;
```

## Storing & Creating

### Storing / Creating Nodes

There are two ways to create nodes.  

The first is to create it directly using `Node a_node;`. This creates a node in the local frame on the stack. That might be fine but if you are creating a linked list you probably want the node to still exist after you exit the current function (unless the current function is main() of course!).  

So typically when we create a node we use `malloc`. This creates a node on the Heap and gives us the address of/pointer to that node. A node created on the Heap will remain there until we explicitly delete it using free() or we exit our program.  

We create a node on the heap as follows.  

```c
Node *node_ptr = (Node *) malloc(sizeof(Node));
```

This line of code is doing a number of things.
1. `malloc(sizeof(Node))` sets aside an area of the Heap that is the size of a Node and returns the address of the start of that area. Note it hasn't *create a node* just set aside memory space.
2. `(Node *) X` converts the address/pointer X to an address/pointer to a Node. It says X isn't just a pointer, it is a pointer to a Node.
3. `Node *node_ptr` creates a local variable `node_ptr` that can store the address of/a pointer to a Node.
4. Bringing it all together `Node *node_ptr = (Node *) malloc(sizeof(Node));` sets aside an area of the heap and stores that address in node_ptr as the address of a Node.

### Storing / Creating Pointers To Nodes

If we used `malloc()` to create a node than we already have a pointer to a node.  
If we created a node variable then we can create a pointer from it using the ampersand &.

```c
Node a_node;
Node *node_ptr = &a_node;
```

Typically though, when working with linked lists it is unusual to have a node variable, we deal with pointers and we get hold of those pointers by creating nodes or by traversing the list from `head` to find the node we are interested in.  

### Storing / Creating Pointers To Pointers

Sometimes we need a pointer to a pointer. Usually what we need is a pointer to the `head` variable (the variable storing the address of the first node in the list). We need a pointer to `head` to pass as a parameter to a function because that function might need to change which node `head` is pointing at. If we simply pass `head` to the function then any changes that function makes to `head` are not to head but to a local variable storing a copy of the data in head. Hence those changes are lost when the function exits.  

```c
void NodeFunc(Node *local_head);

Node *head = ... ;

NodeFunc(head);
```

When `NodeFunc(head)` is called a local variable is created in NodeFunc() called `local_head` and the value in `head` is copied in to it. This allows us to move through the list and change anything about the list except where `head` is pointing at.  

**head ->** [ first node ] -> [ second node ] -> .. [ last node ] -> NULL;

We can remove any node after [ first node ]. We can add a node at any point after [ First Node ]. We can change the contents of any node, including [ first node ] if it exists. What we can't do is change which node `head` is storing the address of. We can't remove [ first node ], we can't insert before [ first node ] and we can't even make a [ first node ] if the list is empty.  

To do that we need to be able to change `head` and the only way to change `head` outside of `head`'s local frame on the stack is to use a pointer to `head`. Since head is already a pointer, what we need is a pointer to a pointer.  

```c
Node ** ptr_to_ptr = &head;
```

We still need to identify the type of variable/structure that the pointer is ultimately pointing at but we indicate its a pointer to a pointer with **.  

Here naming starts to get confusing. We could call our pointer to head `head_ptr` but that gets confusing since we will normally call `head` the head pointer. We also run in to the situation where this variable could get out of sync with head.  

We get around this confusion by just storing `head`, a pointer to the first node in the list. If we need to access the node we can do it with `head->`. If we need a pointer to head we get it with `&head`.

## Calling Functions

The tl;dr version.  

```c
void Func1(Node aNode);
void Func2(Node *aNode);
void Func3(Node **aNode);

Node main_node;
Node *p_main_node = &main_node;
Node **p_p_main_node = &p_main_node;

// Not used often
Func1(main_node);
// Pass a pointer to the first node in the list - used for traversing/searching/printing etc 
Func2(p_main_node);
// Pass a pointer to the pointer to the first node in the list - used to modify the list, especially when you may need to change the first node in the list
Func3(p_p_main_node);

// More typically
Node *head = ...;

Func2(head);
Func3(\&head);
```

### With Variables, Including Structures As Variables

When a function has a parameter of `Node a_node` it expects to receive a node.
```c
void Func1(Node aNode);

Node main_node;

Func1(main_node);
```
In practice this is seldom used. 

### With Pointers

When a function has a parameter of `Node *a_node` it expects to receive a pointer to a node. There are two ways to do this
```c

void Node_Func(Node *a_node);

// Creates a node and stores it in node_variable
Node node_variable; 
// creates a pointer variable and stores the address/pointer to the node previously created.
Node *node_ptr = &node_variable; 

// Call the function using the pointer to the node, with no * or &
Node_Func(node_ptr);

// Call the function using the node variable and get its address using the &
Node_Func(&node_variable);
```

### With Pointers To Pointers

Some linked list functions use `Node **head_ref` as a parameter. `Node **head_ref` is a pointer that stores the address of a pointer that stores the address of the first node in the list.  

Node *head = ....;  

*head -> [ first node ] -> [ second node ] -> .. -> [ last node ] -> NULL  
**head_red -> *head -> [ first-node ] -> [ second node ] -> .. -> [ last node ] -> NULL  

`head` is the address of the first node in the list  
`&head` is the address of the variable storing the address of the first node in the list, i.e. it is the address of the variable head.  


If a function has a parameter of `Node **a_node` it expects to receive the address of a pointer variable that stores the address of a node. It requires this pointer to a pointer because it might need to change the address of the node being stored.

If we pass a pointer to a node `Node *node_ptr = &node_variable;` then we can use that pointer to change the contents of the node but if we want to change the node the pointer is pointing to we can't because the pointer is a variable passed by value and only changes locally. If we want to change what a pointer is storing then we have to pass a pointer *to that pointer*.

```c
void Node_Func(Node **a_node);

// Creates a node and stores it in node_variable
Node node_variable; 
// creates a pointer variable and stores the address/pointer to the node previously created.
Node *node_ptr = &node_variable; 
Node *ptr_ptr = &node_ptr;

// Call the function using the address of the node ptr using the &
Node_Func(&node_ptr);

// Call the function using the pointer to the pointer with no * or &
Node_Func(ptr_ptr);
```

Now when we are using linked lists we don't store any nodes locally, we keep them in the linked list, so we have no equivalent of `Node node_variable`. What we store instead is a pointer to the first node in the list, and we call that pointer `head`. `Node *head = ...;` where the address comes from adding and removing items from the list. We don't typically store a pointer to head in its own variable for two reasons, one its messy, and two if we do store them separately we would run the risk of them getting out of sync and the pointer to head not actually being to head. So instead when we need a pointer to head we get it using `&head`.

```c
void Func3(Node **aNode);

Node *head = ...;

Func3(\&head);
```

## Within Functions

### Node as Variable
If your function is in the form `void Func(Node a_node)` then you have a local variable called `a_node` which has a copy of the node passed as a parameter. You can access the components of the node using the `.` operator. Any changes you make to a_node are local only and are lost when you exit the function.

```c
void Func(Node a_node)
{
    a_node.data = 5;
    a_node.next = NULL;
}
```

### Pointer to Node
If your function is in the form `void Func(Node *a_node)` then you have a local variable called `a_node`, a pointer to a Node, which has a copy of the pointer to a node node passed as a parameter. You can access the components of the node using the `->` operator. Any changes you make to the Node are made to the original Node and remain after the function exits. If you change the Node that `a_node` is pointing at, that is a local change only and is lost when the function exits.  

```c
void Func(Node *a_node)
{
    a_node->data = 5;
    a_node->next = NULL;

    // The line below creates a new node. This new node will be orphaned when the function exits. The original pointer will still point to the previous Node and the values in the Node will be the ones from the changes above.
    a_node = NewNode(4);
}
```

### Pointer to a Pointer to Node
If your function is in the form `void Func(Node **a_node)` then you have a local variable called `a_node`, which stores the address of a pointer to a node. Typically in linked lists we will be using this to get the address of the variable `head` (rather than the address stored in `head` which is the address of the first node in the list).

We can use this double pointer to change anything about the list, including the address stored within `head` that indicates the address of the first node in the list.

```c
void Func(Node **a_node)
{
    // We have the address of head. We would never do this, we'd use a_node instead.
    Node * ptr_to_head = a_node;

    // We can get the first node in the list    
    Node *first = (*a_node);

    // Letting us change the contents of the first node
    first->data = 5;
    first->next = NULL;

    // Or we can do this directly from a_node
    (*a_node)->data = 5;
    (*a_node)->next = NULL;

    // Often for clarity we will create a temp or curr pointer to traverse the list
    Node *curr = (*a_node);
    
    // We can change the first entry in the list 
    Node *new_node = NewNode(4);
    new_node->next = (*a_node);
    (*a_node) = new_node;
}
```


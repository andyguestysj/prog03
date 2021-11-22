---
title: Binary Trees
permalink: /docs/cstruct-09/
---

Binary trees are tree structures where each node can have no more than two children nodes. Typically we refer to the children as the left and right child.  

The basic structure for a binary tree node is shown below. 

```c
// We will use the data value for the index in these examples
typedef struct node {
  int data; 

  struct node *left;
  struct node *right;
} node;
```

The code for creating a binary node is  

```c
#include <stdlib.h>

node* CreateNewNode(int data)
{
    node *temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->left = temp->right = NULL;

    return temp;
}
```

A simple binary tree might look like this.  

>      tree  
>      ----  
>       1    <-- root  
>     /   \     
>    2     3  
>   /   
>  4  

We could create it in code as follows.  

```c
int main()
{
    root = CreateNewNode(1);
    root->left = CreateNewNode(2);
    root->right = CreateNewNode(3);
    root->left->left = CreateNewNode(4);

    return 0;
}
```

## Binary Tree Functions

## Traversing A Binary Tree

With a simple linked list we can traverse it (travel though it) by starting at the first node and moving to the next node repeatedly till we reach a NULL. We never have to think about the route we take through the tree, there are never any decisions to make. With a binary tree at every node we have to decide whether to go left or right. And if we want to visit every node we have to visit both left *and* right. How do we do this? 

Well I'm afraid the answer is recursion. We can use recursion to visit every node in a binary search tree with a very simple recursive function.  

```c
void TraverseTree(node *anode)
{
    // Test only needed for the first call when anode == root
    if (anode!=NULL)
    {
        // if the current node has a left call TraverseTree(anode->left)
        if (anode->left!=NULL)
        {
            TraverseTree(anode->left);
        }

        // if the current node has a right call TraverseTree(anode->right)
        if (anode->right!=NULL)
        {
            TraverseTree(anode->right);
        }
    }
    else
    {
        // should only come here if TraverseTree(&root) is called when root == NULL
        printf("node is null\n");
    }  
}
```

The function above will visit every node in a binary search tree. It won't do anything with any of the nodes, it just visits them. If we want to do something with each node, print out its data for example, then we would add code to the function to do it. 

### Display Tree

```c
void DisplayTree(node *anode)
{
    // Test only needed for the first call when anode == root
    if (anode!=NULL)
    {
        printf("%d\n", anode->data);

        // if the current node has a left call TraverseTree(anode->left)
        if (anode->left!=NULL)
        {
            TraverseTree(anode->left);
        }

        // if the current node has a right call TraverseTree(anode->right)
        if (anode->right!=NULL)
        {
            TraverseTree(anode->right);
        }
    }
    else
    {
        // should only come here if TraverseTree(&root) is called when root == NULL
        printf("node is null\n");
    }  
}
```

### Destroy Tree

To dispose of a binary tree it is necessary to free every node in the tree starting from the leaves at the end of the branches and working backwards through the nodes. The way to do this is recursively as shown below.  

```c
void destroy_tree(node *leaf)
{
  if( leaf != NULL )
  {
      destroy_tree(leaf->left);
      destroy_tree(leaf->right);
      free( leaf );
  }
}
```


## Binary Tree Usage

**Morse Code** can be organised as a binary tree.  

![A Binary tree of Morse code](/assets/img/topic4/Morse-code-tree.svg "A Binary tree of Morse code")  

![Morse Code](/assets/img/topic4/morse.jpg "Morse Code")  
---
title: Trees
permalink: /docs/cstruct-08/
---

[Lecture recording](https://web.microsoftstream.com/video/bbe1af5c-8fce-4245-8245-2a9798ccd908)

The linked list based data structures we've looked at so far are useful. The can grow and shrink as required and data can be inserted anywhere very simply. They all have one major drawback though. If you want to access a specific node you have to start at the head of the list and work your way through the list until you find the node you are interested in. If the data you want is in the first node that's great and if its in the last node that's terrible. On average you'll have to visit half the nodes in the list to find what you are looking for. The longer the list, the worse this will be. Sure there has to be a better way of storing data?  

There is a better way, a tree structure, specifically a binary tree structure.  

## Tree Data Structure

In a tree data structure each node is potentially linked to a number of nodes "below" it. We refer to nodes as being linked to **parents** above them and **children** below them.

![A Generic Tree Structue](/assets/img/topic4/tree_0.png "A Generic Tree Data Structure")  

In the terminology of tree structures the data points are called **nodes** and the links between them are called **edges**. Our "head" node, node 1 in the image above, is called the **root** of the tree. 

![Edges & Nodes](/assets/img/topic4/nodes-edges_0.png "Edges & Nodes")  

We refer to the route taken from the root to any specific node as the **path** to that node. 

Any node without children are called **leaf nodes** or **external nodes**. Any node with at least one child node is called an **internal node**.  

![Height & Depth](/assets/img/topic4/height-depth_0.png "Height & Depth")  

The **height** of a node is the number of nodes between it and the lowest leaf below it.  
The **depth** of a node is the number of nodes above it.  
The **height** and **depth** of a tree are equal to the height of the root node.  

The **degree** of a node are the number of children it has. (Only children, not grandchildren etc).  

How we decide where to place nodes in a tree depends on what we are using it for. If we are using it to represent a file structure of directories and files then the root node would be the top level directory we were storing information on. Each node directly connected to the root node would represent either a folder/directory or a file. Files would be leaf nodes. Each node representing a directory would have children representing the folders and files within it and so on. This is exactly how the filesystem on a Unix/Linux system works. 

Having a layered structure makes it easier and faster to search for information. With a file system we can quickly follow a path to find the files in a folder. Unfortunately it doesn't make it any easier to find where a specific file is, we'd still have to search through every folder until we found the file.


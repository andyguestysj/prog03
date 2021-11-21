---
title: Exercises 2 
permalink: /docs/cstruct-11-tasks/
---

* [Setting up VSC](https://ysjprog03.netlify.app/docs/vsc/)  
* [Cloning a repo in VSC](https://ysjprog03.netlify.app/docs/vsc-cloning/)
* [Gitlab - Setup](https://ysjprog03.netlify.app/docs/gitlab-setup/)
* [Gitlab - Creating a New Repo](https://ysjprog03.netlify.app/docs/gitlab-save/)
* [Gitlab & VSC](https://ysjprog03.netlify.app/docs/gitlab-vsc/)


#### Exercise 1 

1. Create a new c project
2. Create a node structure that has the following components/fields
  * Name - a char array of size 20
  * DOBDay - an integer representing a day of the month
  * DOBMonth - an integer representing a month
  * DOBYear - an integer representing a year (4 digits)
  * Index - an integer
  * left & right - pointers to nodes of this structure
3. Create a function `int CreateIndex(int day, int month, int year)` that calculate and returns an index value as an **integer** in the form yyyymmdd
4. Create a function `node* CreateNode(char Name[20], int day, int month, int year)` that creates a new node (using malloc) and stores Name, day, month and year in the appropriate fields. It should set left and right to NULL. It should use the function from 3 to fill in the Index field.
5. Create a function `void InsertNode(node **root, node *new_node)` that inserts `new_node` in to a binary search tree. It should use the calculated `index` value to determine less than and greater than.
6. Create a function `void DisplayBirthday(node *anode)` that output a line of text in the format `Name : dd/mm/yyyy` for anode.
7. Create a function `void BirthdaysInOrder(node *anode)` that traverses the BST and displays the birthday information from earliest to latest using the function from 5.
8. Create a function `void BirthdaysBetween(node *anode, int index1, int index2)` that uses 6 to display two dates. The dates are stored in index1 and index2 using `CreateIndex`

---
title: Exercises 2
permalink: /docs/cstruct-07-tasks/
---

* [Setting up VSC](https://ysjprog03.netlify.app/docs/vsc/)  
* [Cloning a repo in VSC](https://ysjprog03.netlify.app/docs/vsc-cloning/)
* [Gitlab - Setup](https://ysjprog03.netlify.app/docs/gitlab-setup/)
* [Gitlab - Creating a New Repo](https://ysjprog03.netlify.app/docs/gitlab-save/)
* [Gitlab & VSC](https://ysjprog03.netlify.app/docs/gitlab-vsc/)


#### Exercise 1 

1. Create a project called "DoubleLinked"
2. Implement the doubly linked list described above
3. Add these nodes in order : 7, 3, 9, 10, 5
4. Create a PrintList(Node *head) function that prints the values in the nodes from first to last
5. Modify PrintList(Node *head) so that it prints the values from first to last then from last to first
6. Write void InsertNodeBefore(Node *next_node, int data) that inserts a new node in to the list before next_node.

#### Exercise 2

1. Return to your "DoubleLinked" project
2. Add in `deleteNode()` above and verify it works.
3. Create a new function `void deleteNodeAt(Node** head_ref, int position)` which will delete the node at position `position` in the list. i.e. if `position` is 0 delete the first node, if it is 1 delete the second node, etc. Your function should do nothing if it is asked to delete a node that doesn't exist.
4. Modify `void deleteNodeAt(Node** head_ref, int position)` so that negative values of position are treated as offsets from the end. i.e. if `position` is -1 then delete the last node, -2 delete the second last node, etc.

#### Exercise 3

1. Log in to replit.com
2. Clone and open [https://github.com/andyguestysj/cStack.git](https://github.com/andyguestysj/cStack.git)  
   alternative on replit [https://replit.com/@andyguest/cStack](https://replit.com/@andyguest/cStack)
3. Convert the stack and code so that it stores `char`s instead of `int`s
4. Write a function that takes a char array as a parameter and returns a char array with the original string backwards. Use a stack to do this.
5. Write a function that takes a char array string as input. The input is made up of letters, spaces and asterisks. Parse the string character by character. If the character is a letter or a space push it to the stack. If it is an asterisk, pop it from the stack and print it. Test your function with this string "TH\*E L\*L\*AMA CO\*ME\*S FIRST"
6. Modify your function from 8 so that after you've finished parsing the string you pop and print everything from the stack. Test it with "SH\*E\*KLL\*OFL\*O\*"

Extra Challenge

Read through [https://www.web4college.com/converters/infix-to-postfix-prefix.php](https://www.web4college.com/converters/infix-to-postfix-prefix.php)  
Try to implement the Infix to Postfix Algorithm.

[Infix to Postfix Algorithm](http://csis.pace.edu/~wolf/CS122/infix-postfix.htm)


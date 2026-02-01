# Q3 - reverse traversal linked list

singly linked list with recursive reverse traversal. the trick is you recurse all the way to the end and print on the way back out.

## node structure

struct Node has an int for data and a next pointer. thats it.

## functions

- newNode - mallocs a node, sets data, next is NULL
- append - walks to the end of the list and tacks on a new node
- printList - normal forward print
- reverseTraversal - recursive. base case is NULL. otherwise calls itself with head->next first, then prints head->data after returning. so the printing happens in reverse order

## main

made a list with 5 values (10 to 50), printed it normally, then called reverseTraversal to show it backwards

## output

```
Original list: 10 20 30 40 50 
Reverse traversal: 50 40 30 20 10 
```

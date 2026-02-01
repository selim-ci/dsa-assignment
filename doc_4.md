# Q4 - doubly linked list

same as a normal linked list but each node has a prev pointer too so you can go both directions.

## node structure

struct Node with int data, and two pointers - prev and next. when creating a new node both are set to NULL.

## functions

- newNode - allocates node, sets data, nulls out both pointers
- insertAfter - takes a node and a value. creates the new node, sets its next to prev_node->next and its prev to prev_node. then updates the surrounding nodes to point back to it. have to be careful if prev_node was the last node (next would be NULL)
- deleteNode - unlinks a node. makes the previous node skip over it and the next node point back past it. frees the memory. also handles edge case where the deleted node is the head
- printForward - walks from head to tail
- printBackward - first walks to the tail then goes backwards using prev pointers

## main

built a small list manually (10, 20, 30), showed it both ways, inserted 15 after the first node, deleted 20, showed results again

## output

```
Initial list:
Forward: 10 20 30 
Backward: 30 20 10 

After inserting 15 after 10:
Forward: 10 15 20 30 

After deleting 20:
Forward: 10 15 30 
Backward: 30 15 10 
```

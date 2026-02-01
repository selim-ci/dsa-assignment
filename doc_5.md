# Q5 - graph BFS and DFS

undirected graph using adjacency matrix. BFS uses a queue, DFS is recursive.

## adjacency matrix

2D int array where adj[i][j] = 1 means there's an edge between i and j. since its undirected we set both adj[i][j] and adj[j][i]. n is the number of vertices.

there's also a visited[] array that gets reset before each traversal.

## functions

- addEdge - sets both directions in the matrix
- BFS - uses an int array as a queue with front and rear pointers. marks start as visited, puts it in queue. loop: dequeue a vertex, print it, check all its neighbors and enqueue any unvisited ones and mark them visited
- dfsHelper - recursive. marks current node visited, prints it, then for each neighbor that hasn't been visited calls itself
- DFS - resets visited array then calls dfsHelper

## main

made a 6 node graph with edges 0-1, 0-2, 1-3, 1-4, 2-5. printed the matrix then ran both traversals from node 0.

## output

```
Graph adjacency matrix:
0 1 1 0 0 0 
1 0 0 1 1 0 
1 0 0 0 0 1 
0 1 0 0 0 0 
0 1 0 0 0 0 
0 0 1 0 0 0 

BFS: 0 1 2 3 4 5 
DFS: 0 1 3 4 2 5 
```

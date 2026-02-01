# Q7 - dijkstra's algorithm

finds shortest path from a source node to all others in a weighted graph. greedy approach, always picks the closest unvisited node next.

## data structures

weighted adjacency matrix same as Q5 but the values are the edge weights instead of just 0/1. three helper arrays:
- dist[] - current best known distance from source, starts as INF for everything except source which is 0
- visited[] - tracks which nodes are finalized
- parent[] - stores where we came from (not used in output here but useful for printing actual paths)

## functions

- minDist - scans all unvisited nodes, returns the index with the smallest dist value. this is the greedy selection step
- dijkstra - main function. initializes everything, then loops n-1 times. each time picks the closest unvisited node via minDist, marks it visited, then checks all its neighbors and updates their dist if going through the current node is shorter (relaxation)

## main

5 node weighted graph hardcoded as a matrix. printed the matrix then ran dijkstra from node 0.

## output

```
Graph (weighted adjacency matrix):
   0  10   0  30 100
  10   0  50   0   0
   0  50   0  20  10
  30   0  20   0  60
 100   0  10  60   0

Shortest distances from node 0:
  To 1: 10
  To 2: 50
  To 3: 30
  To 4: 60
```

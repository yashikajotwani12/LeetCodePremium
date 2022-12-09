Previously, we learned how to check the connectivity between two vertices with the “disjoint set” data structure. Now, let's switch gears and consider: Given a graph, how can we find all of its vertices, and how can we find all paths between two vertices?

The depth-first search algorithm is ideal in solving these kinds of problems because it can explore all paths from the start vertex to all other vertices. Let's start by considering an example. In Figure 7, there are five vertices [A, C, D, B, E]. Given two vertices A and B, there are two paths between them. One path is [A, C, D, B], and the other is [A, E, B].

In Graph theory, the depth-first search algorithm (abbreviated as DFS) is mainly used to:

Traverse all vertices in a “graph”;
Traverse all paths between any two vertices in a “graph”.


Complexity Analysis
Time Complexity: O(V + E)O(V+E). Here, VV represents the number of vertices, and EE represents the number of edges. We need to check every vertex and traverse through every edge in the graph.

Space Complexity: O(V)O(V). Either the manually created stack or the recursive call stack can store up to VV vertices.
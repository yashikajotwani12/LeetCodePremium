You might wonder: what is a spanning tree? A spanning tree is a connected subgraph in an undirected graph where all vertices are connected with the minimum number of edges.

After learning what a spanning tree is, you might have another question: what is a minimum spanning tree? A minimum spanning tree is a spanning tree with the minimum possible total edge weight in a “weighted undirected graph”. In Figure 10, a spanning tree formed by green edges [(A, E), (A, B), (B, C), (C, D)] is one of the minimum spanning trees in this weighted undirected graph. Actually, [(A, E), (E, D), (A, B), (B, C)] forms another minimum spanning tree of the weighted undirected graph. Thus, a “weighted undirected graph” can have multiple minimum spanning trees.

In this chapter, we will learn about the “cut property and two algorithms for constructing a “minimum spanning tree”:

Kruskal’s Algorithm
Prim’s algorithm


What is a “cut”? Although many theorems are named after people’s names, “cut” is not one of them. To understand the “cut property”, we need to understand two basic concepts.

First, in Graph theory, a “cut” is a partition of vertices in a “graph” into two disjoint subsets. Figure 11 illustrates a “cut”, where (B, A, E) forms one subset, and (C, D) forms the other subset.
Second, a crossing edge is an edge that connects a vertex in one set with a vertex in the other set. In Figure 11, (B, C), (A, C), (A, D), (E, D) are all “crossing edges”.


Figure 11. Graph with a cut

After knowing the basics of a graph cut, let’s delve into the “cut property”. The cut property provides theoretical support for Kruskal’s algorithm and Prim’s algorithm. So, what is the “cut property”? According to Wikipedia, the “cut property” refers to:

For any cut C of the graph, if the weight of an edge E in the cut-set of C is strictly smaller than the weights of all other edges of the cut-set of C, then this edge belongs to all MSTs of the graph.



Proof of the Cut Property
In the following video, we'll explain and prove the “cut property”.


/* There are n houses in a village. We want to supply water for all the houses by building wells and laying pipes.

For each house i, we can either build a well inside it directly with cost wells[i - 1] (note the -1 due to 0-indexing), or pipe in water from another well to it. The costs to lay pipes between houses are given by the array pipes where each pipes[j] = [house1j, house2j, costj] represents the cost to connect house1j and house2j together using a pipe. Connections are bidirectional, and there could be multiple valid connections between the same two houses with different costs.

Return the minimum total cost to supply water to all houses.

 */


/* Input: n = 3, wells = [1,2,2], pipes = [[1,2,1],[2,3,1]]
Output: 3
Explanation: The image shows the costs of connecting houses using pipes.
The best strategy is to build a well in the first house with cost 1 and connect the other houses to it with cost 2 so the total cost is 3.


Input: n = 2, wells = [1,1], pipes = [[1,2,1],[1,2,2]]
Output: 2
Explanation: We can supply water with cost two using one of the three options:
Option 1:
  - Build a well inside house 1 with cost 1.
  - Build a well inside house 2 with cost 1.
The total cost will be 2.
Option 2:
  - Build a well inside house 1 with cost 1.
  - Connect house 2 with house 1 with cost 1.
The total cost will be 2.
Option 3:
  - Build a well inside house 2 with cost 1.
  - Connect house 1 with house 2 with cost 1.
The total cost will be 2.
Note that we can connect houses 1 and 2 with cost 1 or with cost 2 but we will always choose the cheapest option.  */


Intuition

First of all, let us introduce the problem of the minimum spanning tree.

Given a connected, edge-weighted and undirected graph, a minimum spanning tree is a subset of edges that connect all vertices while the total weights of these edges are minimum among all possible subsets.

One can draw some similarities between the above definition and our problem here. Specifically, we can consider each house as a vertex in a graph, and the pipes between the houses as edges in the graph.

However, there is one major difference between them. In our problem, every vertex and every edge comes with a cost. While in the setting of MST, only the edges are associated with the costs.

To bridge the gap, as suggested in the hints, the trick is to add one virtual vertex to the existing graph. Along with the addition of vertex, we also add edges between the virtual vertex and the rest of the vertices. Finally, we reassign the cost of each vertex to the corresponding newly-added edge.


"disjoint set” data structure, also known as the “union-find” data structure. Note that others might refer to it as an algorithm.


The two important functions of a “disjoint set.”
In the introduction videos above, we discussed the two important functions in a “disjoint set”.

The find function finds the root node of a given vertex. For example, in Figure 5, the output of the find function for vertex 3 is 0.
The union function unions two vertices and makes their root nodes the same. In Figure 5, if we union vertex 4 and vertex 5, their root node will become the same, which means the union function will modify the root node of vertex 4 or vertex 5 to the same root node.
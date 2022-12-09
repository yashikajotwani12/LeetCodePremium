<!-- Complexity Analysis
Time Complexity: O(E⋅logE). Here, EE represents the number of edges.

At first, we need to sort all the edges of the graph in ascending order. Sorting will take O(ElogE) time.
Next, we can start building our minimum spanning tree by selecting which edges should be included. For each edge, we will look at whether both of the vertices of the edge belong to the same connected component; which is an O(\alpha(V))O(α(V)) operation, where α refers to the Inverse Ackermann function. In the worst case, the tree will not be complete until we reach the very last edge (the edge with the largest weight), so this process will take O(Eα(V)) time.
Therefore, in total, the time complexity is  O(ElogE+Eα(V))=O(ElogE).
Space Complexity: O(V). V represents the number of vertices. Keeping track of the root of every vertex in the union-find data structure requires O(V)O(V) space. However, depending on the sorting algorithm used, different amounts of auxiliary space will be required to sort the list of edges in place. For instance, Timsort (used by default in python) requires O(E) space in the worst-case scenario, while Java uses a variant of quicksort whose space complexity is O(logE) -->
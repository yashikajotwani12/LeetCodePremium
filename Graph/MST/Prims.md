Complexity Analysis
VV represents the number of vertices, and EE represents the number of edges.

Time Complexity: O(E \cdot \log V)O(E⋅logV) for Binary heap, and O(E+V \cdot \log V)O(E+V⋅logV) for Fibonacci heap.

For a Binary heap:
We need O(V + E)O(V+E) time to traverse all the vertices of the graph, and we store in the heap all the vertices that are not yet included in our minimum spanning tree.
Extracting minimum element and key decreasing operations cost O(\log V)O(logV) time.
Therefore, the overall time complexity is O(V + E) \cdot O(\log V) = O(E \cdot \log V)O(V+E)⋅O(logV)=O(E⋅logV).
For a Fibonacci heap:
Extracting minimum element will take O(\log V)O(logV) time while key decreasing operation will take amortized O(1)O(1) time, therefore, the total time complexity would be O(E + V \cdot \log V)O(E+V⋅logV).
Space Complexity: O(V)O(V). We need to store VV vertices in our data structure
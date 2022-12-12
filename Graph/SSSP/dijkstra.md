“Dijkstra’s algorithm” solves the “single-source shortest path” problem in a weighted directed graph with non-negative weights.

We take the starting point u as the center and gradually expand outward while updating the “shortest path” to reach other vertices.

“Dijkstra's Algorithm” uses a “greedy approach”. Each step selects the “minimum weight” from the currently reached vertices to find the “shortest path” to other vertices.

Complexity Analysis
VV represents the number of vertices, and EE represents the number of edges.

Time Complexity: O(E+VlogV) when a Fibonacci heap is used, or O(V + E \log V)O(V+ElogV) for a Binary heap.
If you use a Fibonacci heap to implement the “min-heap”, extracting minimum element will take O(logV) time while key decreasing operation will take amortized O(1)O(1) time, therefore, the total time complexity would be O(E+VlogV).
If you use a Binary heap, then the time complexity would be O(V + E \log V)O(V+ElogV).
Space Complexity: O(V)O(V). We need to store VV vertices in our data structure.
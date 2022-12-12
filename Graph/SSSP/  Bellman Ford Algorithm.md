Theorem 1: In a “graph with no negative-weight cycles” with N vertices, the shortest path between any two vertices has at most N-1 edges.

For simplicity, throughout the Bellman-Ford related videos, we will refer to a directed acyclic graph (DAG) as a "regular" graph. However, in general, we encourage you to use the terminology DAG since, in graph theory, a "regular graph" is a graph where every node has the same number of neighbors.

How does the Bellman-Ford algorithm detect “negative weight cycles”?
Although the “Bellman-Ford algorithm” cannot find the shortest path in a graph with “negative weight cycles”, it can detect whether there exists a “negative weight cycle” in the “graph”.

Detection method: After relaxing each edge N-1 times, perform the Nth relaxation. According to the “Bellman-Ford algorithm”, all distances must be the shortest after relaxing each edge N-1 times. However, after the Nth relaxation, if there exists distances[u] + weight(u, v) < distances(v) for any edge(u, v), it means there is a shorter path . At this point, we can conclude that there exists a “negative weight cycle”.



SPFA algorithm
To address the limitations, we introduce an improved variation of the Bellman-Ford algorithm by using a queue. This improvement is known as “the Shortest Path Faster Algorithm” (SPFA algorithm).

Instead of choosing among any untraversed edges, as one does by using the “Bellman-Ford” algorithm, the “SPFA” Algorithm uses a “queue” to maintain the next starting vertex of the edge to be traversed. Only when the shortest distance of a vertex is relaxed and that the vertex is not in the “queue”, we add the vertex to the queue. We iterate the process until the queue is empty. At this point, we have calculated the minimum distance from the given vertex to any vertices.

V represents the number of vertices, and EE represents the number of edges.

Time Complexity: we iterate through all the vertices, and in each iteration, we'll perform a relaxation operation for each appropriate edge. Therefore, the time complexity would be O(V \cdot E)O(V⋅E).

Space Complexity: O(V)O(V). We need to store VV vertices.

Note that the time complexity of the improved version of the algorithm for the worst-case scenario is the same as of the standard version of the Bellman-Ford Algorithm. However, on average, the SPFA tends to be faster.
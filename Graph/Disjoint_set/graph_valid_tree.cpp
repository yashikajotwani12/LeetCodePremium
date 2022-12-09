/* You have a graph of n nodes labeled from 0 to n - 1. You are given an integer n and a list of edges where edges[i] = [ai, bi] indicates that there is an undirected edge between nodes ai and bi in the graph.

Return true if the edges of the given graph make up a valid tree, and false otherwise.


Recall that a graph, G, is a tree iff the following two conditions are met:

G is fully connected. In other words, for every pair of nodes in G, there is a path between them.
G contains no cycles. In other words, there is exactly one path between each pair of nodes in G.



Depth-first search is a classic graph-traversal algorithm that can be used to check for both of these conditions:

G is fully connected if, and only if, we started a depth-first search from a single source and discovered all nodes in G during it.
G contains no cycles if, and only if, the depth-first search never goes back to an already discovered node. We need to be careful though not to count trivial cycles of the form A → B → A that occur with most implementations of undirected edges.

Depth-first search requires being able to look up the adjacent (immediate neighbours) of a given node. Like many graph interview problems though, the input format we're given doesn't allow us to quickly get the neighbours of a node. Therefore, our first step is to convert the input into an adjacency list. Recall that an adjacency list is where we have a list of sub-lists, where each sub-list is the list of the immediate neighbours for the i'th node.


An adjacency matrix would be an acceptable, although not ideal, representation for this problem. Often, we'd only use an adjacency matrix if we know that the number of edges is substantially higher than the number of nodes. We have no reason to believe that is the case here. Approach 2 will also provide some useful insight into this.
A linked representation, where you make actual nodes objects, would be an overly complicated representation and could suggest to an interviewer that you have a limited understanding of adjacency lists and adjacency matrices. They are not commonly used in interview questions.




Approach 2: Advanced Graph Theory + Iterative Depth-First Search
Intuition

Depending on how much graph theory you know, there's a better definition for determining whether or not a given graph is a tree.

For the graph to be a valid tree, it must have exactly n - 1 edges. Any less, and it can't possibly be fully connected. Any more, and it has to contain cycles. Additionally, if the graph is fully connected and contains exactly n - 1 edges, it can't possibly contain a cycle, and therefore must be a tree!


Going by this definition, our algorithm needs to do the following:

Check whether or not there are n - 1 edges. If there's not, then return false.
Check whether or not the graph is fully connected. Return true if it is, false if otherwise.




Approach 3: Advanced Graph Theory + Union Find


Intuition

In Approach 2, we used this definition for a tree:

For the graph to be a valid tree, it must have exactly n - 1 edges. Any less, and it can't possibly be fully connected. Any more, and it has to contain cycles. Additionally, if the graph is fully connected and contains exactly n - 1 edges, it can't possibly contain a cycle, and therefore must be a tree!

This definition simplified the problem down to checking whether or not the graph is fully connected. If it is, and if it contains n - 1 edges, then we know it's a tree. In the previous approaches, we used graph search algorithms to check whether or not all nodes were reachable, starting from a single source node.

Another way we could approach the problem is by considering each connected component to be a set of nodes. When an edge is put between two separate connected components, they are merged into a single connected component. We'll use the example n = 6 and edges = [(0, 5), (4, 0), (1, 2), (4, 5), (3, 2)]. Before we look at the edges, we have 6 sets 




Important Properties learned
* 1. Tree has n-1 edges
* 2. Disjoint Set can detect if there is cycle in graph
* 3. Graph with less than n-1 edges is definitely not connected
* 4. Graph with more than n-1 edges definitely has cycle




*/
class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<int> nodes(n,0);
        for(int i=0; i<n; i++) nodes[i] = i;
        for(int i=0; i<edges.size(); i++){
            int f = edges[i].first;
            int s = edges[i].second;
            while(nodes[f]!=f) f = nodes[f];
            while(nodes[s]!=s) s = nodes[s];
            if(nodes[f] == nodes[s]) return false;
            nodes[s] = f;
        }
        return edges.size() == n-1;
    }
};
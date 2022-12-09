/* There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.

You want to determine if there is a valid path that exists from vertex source to vertex destination.

Given edges and the integers n, source, and destination, return true if there is a valid path from source to destination, or false otherwise.

 */


// iterative bfs
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        unordered_map<int,vector<int>> graph; 
        for(auto e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        vector<bool> visited(n,0);        
        queue<int> q;
        q.push(start);
        visited[start] = 1; 
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            if(curr == end)
                return 1; 
            for(auto &node : graph[curr]){
                if(!visited[node]){
                    visited[node] = 1; 
                    q.push(node);
                }
            }
        }
        
        return false;
    }
};

// iterative dfs
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // Store all edges according to nodes in 'graph'.
        unordered_map<int, vector<int>> graph;
        for (auto& edge : edges) {
            int a = edge[0], b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        
        // Start from source node, add it to stack.
        // NOTE: 'stack' conflicts with the type name std::stack, 
        // so we use 'dfsStack' instead.
        vector<bool> seen(n);
        stack<int> dfsStack({source});
        seen[source] = true;
        
        while (!dfsStack.empty()) {
            int currNode = dfsStack.top();
            dfsStack.pop();
            
            if (currNode == destination) {
                return true;
            }
            
            // Add all unvisited neighbors of the current node to 'dfsStack' 
            // and mark them as visited.
            for (auto nextNode : graph[currNode]) {
                if (!seen[nextNode]) {
                    seen[nextNode] = true;
                    dfsStack.push(nextNode);
                }
            }
        }
        
        return false;
    }
};

// Approach 4: Disjoint Set Union (DSU)

// Algorithm
// Initialize the DSU data structure UnionFind containing all nodes. Each node i has:

// a distinct root, which means each point is individual.
// a group size of 1, which means each set only contains one node.
// the DSU structure also supports:

// find(x): find the root of the node x.
// union(x, y): if two given nodes x and y are not in the same group, we modify one of the roots as the other root, which means that the two groups containing x and y are merged into one group. Note that we use the union-by-rank method to optimize the time complexity, basically, we modify the root of the smaller group as the root of the larger group, please see Disjoint Set - Union by Rank for more information!
// Iterate over all edges. For each edge edge = [node_a, node_b], use the DSU data structure we initialized to connect node_a and node_b.

// Check if node source and node destination are in the same group.

// Implementation

class UnionFind {
    vector<int> root, rank;
public:
    UnionFind(int n) : root(n), rank(n, 1) {
        iota(root.begin(), root.end(), 0);
    }
    int find(int x) {
        if (x != root[x]) {
            root[x] = find(root[x]);
        }
        return root[x];
    }   
    void join(int x, int y) {
        int rootX = find(x), rootY = find(y);
        
        if (rootX != rootY) {
            if (rank[rootX] > root[rootY]) {
                swap(rootX, rootY);
            }
            // Modify the root of the smaller group as the root of the
            // larger group, also increment the size of the larger group.
            root[rootX] = rootY;
            rank[rootY] += rank[rootX];
        }
    }
};

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        UnionFind uf(n);

        for (auto& edge : edges) {
            uf.join(edge[0], edge[1]);
        }
        
        return uf.find(source) == uf.find(destination);
    }
};

Complexity Analysis
Let nnn be the number of nodes and mmm be the number of edges.

Time complexity: O(m⋅α(n))

The amortized complexity for performing mmm union find operations is O(m⋅α(n))O(m\cdot \alpha(n))O(m⋅α(n)) time where α\alphaα is the Inverse Ackermann Function.
To sum up, the overall time complexity is O(m⋅α(n))O(m\cdot \alpha(n))O(m⋅α(n)).
Space complexity: O(n)O(n)O(n)

We used two arrays root and rank to save the root and rank of each node in the DSU data structure, each of them takes O(n)O(n)O(n) space.
To sum up, the overall time complexity is O(n)O(n)O(n).
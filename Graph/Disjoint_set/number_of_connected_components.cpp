/* You have a graph of n nodes. You are given an integer n and an array edges where edges[i] = [ai, bi] indicates that there is an edge between ai and bi in the graph.

Return the number of connected components in the graph.
 */

class Solution {
public:
    void dfs(int src,  vector<int>adj[], vector<int>&vis)
    {
        if(vis[src]==1) return;
        vis[src] =1;
        for(auto i: adj[src])
        {
            if(vis[i]==0)
            {
                dfs(i, adj, vis);
            }
        }
        
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        
        int count=0;
        vector<int>adj[n+1];
        vector<int>vis(n+1, 0);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                count++;
                dfs(i,adj, vis);
            }
        }
        return count;
        
    }
};


// Approach 2: Disjoint Set Union (DSU)

/* Imagine we have a graph with N vertices and 0 edges. The number of connected components will be N in that graph.

Algorithm

Initialize a variable count with the number of vertices in the input.
Traverse all of the edges one by one, performing the union-find method combine on each edge. If the endpoints are already in the same set, then keep traversing. If they are not, then decrement count by 1.
After traversing all of the edges, the variable count will contain the number of components in the graph.

*/

class Solution {
public:
    int find(vector<int> &representative, int vertex) {
        if (vertex == representative[vertex]) {
            return vertex;
        }
        
        return representative[vertex] = find(representative, representative[vertex]);
    }
    
    int combine(vector<int> &representative, vector<int> &size, int vertex1, int vertex2) {
        vertex1 = find(representative, vertex1);
        vertex2 = find(representative, vertex2);
        
        if (vertex1 == vertex2) {
            return 0;
        } else {
            
            if (size[vertex1] > size[vertex2]) {
                size[vertex1] += size[vertex2];
                representative[vertex2] = vertex1;
            } else {
                size[vertex2] += size[vertex1];
                representative[vertex1] = vertex2;
            }
            return 1;
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> representative(n), size(n);
        
        for (int i = 0; i < n; i++) {
            representative[i] = i;
            size[i] = 1;
        }
        
        int components = n;
        for (int i = 0; i < edges.size(); i++) {
            components -= combine(representative, size, edges[i][0], edges[i][1]);
        }

        return components;
    }
};


// Here EEE = Number of edges, VVV = Number of vertices.

// Time complexity: O(E⋅α(n))O(E\cdotα(n))O(E⋅α(n)).

// Iterating over every edge requires O(E)O(E)O(E) operations, and for every operation, we are performing the combine method which is O(α(n))O(α(n))O(α(n)), where α(n) is the inverse Ackermann function.

// Space complexity: O(V)O(V)O(V).

// Storing the representative/immediate-parent of each vertex takes O(V)O(V)O(V) space. Furthermore, storing the size of components also takes O(V)O(V)O(V) space.
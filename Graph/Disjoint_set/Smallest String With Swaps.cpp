Approach 1: Depth-First Search (DFS)
class Solution {
public:
    // Maximum number of vertices
    static const int N = 100001;
    vector<int> adj[N];
    bool visited[N];
    
    void DFS(string& s, int vertex, vector<char>& characters, vector<int>& indices) {
        // Add the character and index to the list
        characters.push_back(s[vertex]);
        indices.push_back(vertex);
        
        visited[vertex] = true;
        
        // Traverse the adjacents
        for (int adjacent : adj[vertex]) {
            if (!visited[adjacent]) {
                DFS(s, adjacent, characters, indices);
            }
        }
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        // Build the adjacency list
        for (vector<int> edge : pairs) {
            int source = edge[0];
            int destination = edge[1];
            
            // Undirected edge
            adj[source].push_back(destination);
            adj[destination].push_back(source);
        }
        
        for (int vertex = 0; vertex < s.size(); vertex++) {
            // If not covered in the DFS yet
            if (!visited[vertex]) {
                vector<char> characters;
                vector<int> indices;
                
                DFS(s, vertex, characters, indices);
                // Sort the list of characters and indices
                sort(characters.begin(), characters.end());
                sort(indices.begin(), indices.end());

                // Store the sorted characters corresponding to the index
                for (int index = 0; index < characters.size(); index++) {
                    s[indices[index]] = characters[index];
                }
            }
        }
        
        return s;
    }
};



/* Approach 2: Disjoint Set Union (DSU)
Intuition

Remember, our first task is to determine which indices belong to the same connected component. In this approach, we will use the Union-Find data structure to accomplish this.

If you're not familiar with DSU, check out our Explore Card.

First, we will union all vertices that share an edge (vertices a and b share an edge if (a, b) or (b, a) exists in pairs). After which, all vertices with the same root will belong to the same component. This way, by looking at the root node for each vertex, we can put the vertices and the characters at these vertices (indices) in separate lists corresponding to the component they belong to. Then, similar to the previous approach, we will sort the list of characters that belong to the same component and place the ithi_{th}i 
th character at the ithi_{th}ith index in a string smallestString.

Note that we don't need to sort the list of indices in this approach because, as we iterate over vertices in ascending order, we will store the vertices that belong to the same component in ascending order.

Algorithm

Iterate over the pairs, for each pair (a, b) perform the union operation for vertices a and b.
Iterate over the indices from 0 to s.size() - 1. For each index (vertex) we will:
Perform the find operation on vertex to find the root.
Store the vertex in the list corresponding to root in the HashMap rootToComponent.
Iterate over each list in the HashMap rootToComponent:
For each list indices, iterate over the list and for each element store the corresponding character in s in the list of characters (characters). Here, each element in indices represents an index in s and each character in characters represents the characters at this index in s.
Sort the list and characters.
Iterate over the lists indices and characters, place the ithi_{th}i 
th
​
  character at the ithi_{th}i 
th
​
  index in the string smallestString.
Return smallestString.
 */

class UnionFind {
private:
    vector<int> root;
    vector<int> rank;
public:
    // Initialize the array root and rank
    // Each vertex is representative of itself with rank 1
    UnionFind(int sz) : root(sz), rank(sz) {
        for (int i = 0; i < sz; i++) {
            root[i] = i;
            rank[i] = 1;
        }
    }
    
    // Get the root of a vertex
    int find(int x) {
        if (x == root[x]) {
            return x;
        }
        return root[x] = find(root[x]);
    }

    // Perform the union of two components
    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] >= rank[rootY]) {
                root[rootY] = rootX;
                rank[rootX] += rank[rootY];
            } else {
                root[rootX] = rootY;
                rank[rootY] += rank[rootX];
            }
        }
    }
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        UnionFind uf(s.size());
        
        // Iterate over the edges
        for (vector<int> edge : pairs) {
            int source = edge[0];
            int destination = edge[1];
            
            // Perform the union of end points
            uf.unionSet(source, destination);
        }
        
        
        unordered_map<int, vector<int>> rootToComponent;
        // Group the vertices that are in the same component
        for (int vertex = 0; vertex < s.size(); vertex++) {
            int root = uf.find(vertex);
            // Add the vertices corresponding to the component root
            rootToComponent[root].push_back(vertex);
        }
        
        // String to store the answer
        string smallestString(s.length(), ' ');
        // Iterate over each component
        for (auto component : rootToComponent) {
            vector<int> indices = component.second;
            
            // Sort the characters in the group
            vector<char> characters;
            for (int index : indices) {
                characters.push_back(s[index]);
            }
            sort(characters.begin(), characters.end());
            
            // Store the sorted characters
            for (int index = 0; index < indices.size(); index++) {
                smallestString[indices[index]] = characters[index];
            }
        }
        
        return smallestString;
    }
};
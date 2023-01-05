Input: sentence1 = ["great","acting","skills"], sentence2 = ["fine","drama","talent"], similarPairs = [["great","good"],["fine","good"],["drama","acting"],["skills","talent"]]
Output: true
Explanation: The two sentences have the same length and each word i of sentence1 is also similar to the corresponding word in sentence2. 
class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        
    }
};
cclass Solution {
public:
    // Returns true if there is a path from source to dest.
    bool dfs(string& source, unordered_set<string>& visit,
             unordered_map<string, unordered_set<string>>& adj, string& dest) {
        visit.insert(source);
        if (source == dest) {
            return true;
        }
        for (auto neighbor : adj[source]) {
            if (!visit.count(neighbor) && dfs(neighbor, visit, adj, dest)) {
                return true;
            }
        }
        return false;
    }

    bool areSentencesSimilarTwo(vector<string>& sentence1, vector<string>& sentence2,
                                vector<vector<string>>& similarPairs) {
        if (sentence1.size() != sentence2.size()) {
            return false;
        }
        // Create the graph using each pair in similarPairs.
        unordered_map<string, unordered_set<string>> adj;
        for (auto& pair : similarPairs) {
            adj[pair[0]].insert(pair[1]);
            adj[pair[1]].insert(pair[0]);
        }
        // The number of nodes in the graph.
        int nodesCount = adj.size();
        for (int i = 0; i < sentence1.size(); i++) {
            if (sentence1[i] == sentence2[i]) {
                continue;
            }
            unordered_set<string> visit;
            if (adj.count(sentence1[i]) && adj.count(sentence2[i]) &&
                dfs(sentence1[i], visit, adj, sentence2[i])) {
                continue;
            }
            return false;
        }
        return true;
    }
};

Complexity Analysis
Here, nnn is the number of words in sentence1 and sentence2 and kkk is the number of similar pairs. Let mmm be the average length of words in sentence1, sentence2 as well as in similarPairs.

Time complexity: O(n⋅k⋅m)O(n \cdot k \cdot m)O(n⋅k⋅m)

We iterate over all the elements of similarPairs and insert a pair twice into adj. To hash each word of length mmm, we need O(m)O(m)O(m) time, and to put the same length word in the hash set, we need O(m)O(m)O(m) time again. Because there are kkk pairs of words, there can be at most 2⋅k2 \cdot k2⋅k words that can be hashed and added to the set. As a result, we require O(k⋅m)O(k \cdot m)O(k⋅m) time.
We iterate over all of sentence1's words to see if the corresponding words are equal or similar. If the words are not equal, we perform a DFS traversal over the graph with O(k)O(k)O(k) nodes and edges. As we know, a single DFS traversal takes O(V+E)O(V + E)O(V+E) time to traverse a graph with V nodes and E edges. In our case, we have O(k)O(k)O(k) edges and nodes, and each node is a string with an average size of mmm, so a single traversal would take O(k⋅m)O(k \cdot m)O(k⋅m) time. For nnn traversals, it would take O(n⋅k⋅m)O(n \cdot k \cdot m)O(n⋅k⋅m).
The total amount of time required is O(n⋅k⋅m+k⋅m)=O(n⋅k⋅m)O(n \cdot k \cdot m + k \cdot m) = O(n \cdot k \cdot m)O(n⋅k⋅m+k⋅m)=O(n⋅k⋅m).
Space complexity: O(k⋅m)O(k \cdot m)O(k⋅m)

Because we use similarPairs to create the graph, the number of nodes and edges can be O(k)O(k)O(k). To map O(k)O(k)O(k) words of size mmm, adj uses O(k⋅m)O(k \cdot m)O(k⋅m) space.
The recursion call stack used by dfs can have no more than O(k)O(k)O(k) elements. It would take up O(k)O(k)O(k) space in that case.
We also use a set visit, which requires O(k⋅m)O(k \cdot m)O(k⋅m) space because it could contain O(k)O(k)O(k) words in the worst case.

class Solution {
public:
    // Returns true if there is a path from node to dest.
    bool bfs(string& source, unordered_map<string, unordered_set<string>>& adj, string& dest) {
        unordered_set<string> visit;
        queue<string> q;
        q.push(source);
        visit.insert(source);

        while (!q.empty()) {
            string node = q.front();
            q.pop();
            for (auto& neighbor : adj[node]) {
                if (neighbor == dest) {
                    return true;
                }
                if (!visit.count(neighbor)) {
                    visit.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }
        return false;
    }

    bool areSentencesSimilarTwo(vector<string>& sentence1, vector<string>& sentence2,
                                vector<vector<string>>& similarPairs) {
        if (sentence1.size() != sentence2.size()) {
            return false;
        }
        // Create the graph using each pair in similarPairs.
        unordered_map<string, unordered_set<string>> adj;
        for (auto& pair : similarPairs) {
            adj[pair[0]].insert(pair[1]);
            adj[pair[1]].insert(pair[0]);
        }

        for (int i = 0; i < sentence1.size(); i++) {
            if (sentence1[i] == sentence2[i]) {
                continue;
            }
            if (adj.count(sentence1[i]) && adj.count(sentence2[i]) &&
                bfs(sentence1[i], adj, sentence2[i])) {
                continue;
            }
            return false;
        }
        return true;
    }
};
class UnionFind {
private:
    map<string, string> parent;
    map<string, int> rank;

public:
    void addWord(string x) {
        if (!parent.count(x)) {
            parent[x] = x;
            rank[x] = 0;
        }
    }

    bool isWordPresent(string x) {
        if (parent.count(x)) {
            return true;
        }
        return false;
    }

    string find(string x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSet(string x, string y) {
        string xset = find(x), yset = find(y);
        if (xset == yset) {
            return;
        } else if (rank[xset] < rank[yset]) {
            parent[xset] = yset;
        } else if (rank[xset] > rank[yset]) {
            parent[yset] = xset;
        } else {
            parent[yset] = xset;
            rank[xset]++;
        }
    }
};

class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& sentence1, vector<string>& sentence2,
                                vector<vector<string>>& similarPairs) {
        if (sentence1.size() != sentence2.size()) {
            return false;
        }

        UnionFind dsu;
        for (auto& pair : similarPairs) {
            // Create the graph using the hashed values of the similarPairs.
            dsu.addWord(pair[0]);
            dsu.addWord(pair[1]);
            dsu.unionSet(pair[0], pair[1]);
        }

        for (int i = 0; i < sentence1.size(); i++) {
            if (sentence1[i] == sentence2[i]) {
                continue;
            }
            if (dsu.isWordPresent(sentence1[i]) && dsu.isWordPresent(sentence2[i]) &&
                dsu.find(sentence1[i]) == dsu.find(sentence2[i])) {
                continue;
            }
            return false;
        }
        return true;
    }
};

Time complexity: O((n+k)⋅m)O((n + k) \cdot m)O((n+k)⋅m)

For TTT operations, the amortized time complexity of the union-find algorithm (using path compression with union by rank) is O(alpha(T))O(alpha(T))O(alpha(T)). Here, α(T)\alpha(T)α(T) is the inverse Ackermann function that grows so slowly, that it doesn't exceed 444 for all reasonable TTT (approximately T<10600 T < 10^{600}T<10 
600
 ). You can read more about the complexity of union-find here. Because the function grows so slowly, we consider it to be O(1)O(1)O(1). Since, we are performing union and find of strings with average length mmm, we consider it to be O(m)O(m)O(m).
We iterate over all the elements of similarPairs and add both the words in pair to dsu which takes O(m)O(m)O(m) each. We then perform union which also takes O(m)O(m)O(m) time per operation. Because there are kkk pairs, this step will take O(k⋅m)O(k \cdot m)O(k⋅m) time for all the pairs.
We iterate over all of sentence1's words to see if the words are equal. Because each word is of mmm length, this would take O(m)O(m)O(m) time for each word. It will take O(n⋅m)O(n \cdot m)O(n⋅m) time in total because there are nnn words. If the words are not equal, we perform a find operation that takes O(m)O(m)O(m) per find operation. It would take O(n⋅m)O(n \cdot m)O(n⋅m) time for nnn words.
As a result, the total time would be O((n+k)⋅m+k⋅m)=O((n+k)⋅m)O((n + k) \cdot m + k \cdot m) = O((n + k) \cdot m)O((n+k)⋅m+k⋅m)=O((n+k)⋅m).
Space complexity: O(k⋅m)O(k \cdot m)O(k⋅m)

Because there can be kkk similar pairs, there are O(k)O(k)O(k) words that are inserted in dsu. Since each word has average length mmm, parent and rank maps would take up O(k⋅m)O(k \cdot m)O(k⋅m) space.
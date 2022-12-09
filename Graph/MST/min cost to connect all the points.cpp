You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.

class Edge {
public:
    int point1;
    int point2;
    int cost;
    Edge(int point1, int point2, int cost)
        : point1(point1), point2(point2), cost(cost) {}
};

// Overload the < operator.
bool operator<(const Edge& edge1, const Edge& edge2) {
    return edge1.cost > edge2.cost;
}

class UnionFind {
public:
    UnionFind(int sz) : root(sz), rank(sz) {
        for (int i = 0; i < sz; i++) {
            root[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x) {
        if (x == root[x]) {
            return x;
        }
        return root[x] = find(root[x]);
    }

    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                root[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                root[rootX] = rootY;
            } else {
                root[rootY] = rootX;
                rank[rootX] += 1;
            }
        }
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }

private:
    vector<int> root;
    vector<int> rank;
};

class Solution {
public:
    // Kruskal's algorithm
    int minCostConnectPoints(vector<vector<int>>& points) {
        if (points.size() == 0) {
            return 0;
        }
        int sz = points.size();
        priority_queue<Edge> pq;
        UnionFind uf(sz);

        for (int i = 0; i < sz; i++) {
            vector<int>& coordinate1 = points[i];
            for (int j = i + 1; j < sz; j++) {
                vector<int>& coordinate2 = points[j];
                // Calculate the distance between two coordinates.
                int cost = abs(coordinate1[0] - coordinate2[0]) +
                            abs(coordinate1[1] - coordinate2[1]);
                Edge edge(i, j, cost);
                pq.push(edge);
            }
        }

        int result = 0;
        int count = sz - 1;
        while (!pq.empty() && count > 0) {
            Edge edge = pq.top();
            pq.pop();
            if (!uf.connected(edge.point1, edge.point2)) {
                uf.unionSet(edge.point1, edge.point2);
                result += edge.cost;
                count--;
            }
        }
        return result;
    }
};

int main() {
    vector<vector<int>> points = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
    Solution solution;
    cout << "Minimum Cost to Connect Points = " << solution.minCostConnectPoints(points) << endl;
    return 0;
}

`````````````````````````````````````````````````````````````````````````````````````````

class UnionFind {
public:
    vector<int> group;
    vector<int> rank;

    UnionFind(int size) {
        group = vector<int>(size);
        rank = vector<int>(size);
        for (int i = 0; i < size; ++i) {
            group[i] = i;
        }
    }

    int find(int node) {
        if (group[node] != node) {
            group[node] = find(group[node]);
        }
        return group[node];
    }

    bool join(int node1, int node2) {
        int group1 = find(node1);
        int group2 = find(node2);
        
        // node1 and node2 already belong to same group.
        if (group1 == group2) {
            return false;
        }

        if (rank[group1] > rank[group2]) {
            group[group2] = group1;
        } else if (rank[group1] < rank[group2]) {
            group[group1] = group2;
        } else {
            group[group1] = group2;
            rank[group2] += 1;
        }

        return true;
    }
};


class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int, pair<int, int>>> allEdges;
        
        // Storing all edges of our complete graph.
        for (int currNode = 0; currNode < n; ++currNode) {
            for (int nextNode = currNode + 1; nextNode < n; ++nextNode) {
                int weight = abs(points[currNode][0] - points[nextNode][0]) + 
                             abs(points[currNode][1] - points[nextNode][1]);
                
                allEdges.push_back({ weight, { currNode, nextNode }});
            }
        }
        
        // Sort all edges in increasing order.
        sort(allEdges.begin(), allEdges.end());
        
        UnionFind uf(n);
        int mstCost = 0;
        int edgesUsed = 0;
        
        for (int i = 0; i < allEdges.size() && edgesUsed < n - 1; ++i) {
            int node1 = allEdges[i].second.first;
            int node2 = allEdges[i].second.second;
            int weight = allEdges[i].first;
            
            if (uf.join(node1, node2)) {
                mstCost += weight;
                edgesUsed++;
            }
        }
        
        return mstCost;
    }
};


``````````````````````````````````````````````````````````````````````````````````
Approach 3: Prim's Algorithm (Optimized)
Intuition

Although the min-heap method is often used to implement Prim's algorithm (as it's fairly easy to understand), due to its use of a heap to store the edges, its time complexity is suboptimal. Thus, we will present a more efficient way of implementing Prim's algorithm, which eliminates the use of min-heap to find the next lowest-weighted edge.

In this approach, we use one $$minDist$$ array, where $$minDist[i]$$ stores the weight of the smallest weighted edge to reach the $$i^{th}$$ node from any node in the current tree. We will iterate over the $$minDist$$ array and greedily pick the node that is not in the MST and has the smallest edge weight. We will add this node to the MST, and for all of its neighbors, we will try to update the value in $$minDist$$.
We will repeat this process until all nodes are part of the MST.

Initially, we can start with any node, say node $$0$$. Thus we mark$$minDist[0] = 0$$, and for the remaining nodes, the min distance to reach them is $$\infty$$.
Just like in the previous approach, we assume a $$0$$ weighted temporary edge is used to reach the first node.

Thus in this method, we will use this new way of selecting the min weight edges (instead of using a heap). Just like the previous method, we will use the $$inMST$$ array to determine if adding the current edge will result in a cycle, and we can stop as soon as $$n$$ edges are included in MST (including our imaginary zero-weight edge to node 0).

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int mstCost = 0;
        int edgesUsed = 0;
        
        // Track nodes which are visited.
        vector<bool> inMST(n);
        
        vector<int> minDist(n, INT_MAX);
        minDist[0] = 0;
        
        while (edgesUsed < n) {
            int currMinEdge = INT_MAX;
            int currNode = -1;
            
            // Pick least weight node which is not in MST.
            for (int node = 0; node < n; ++node) {
                if (!inMST[node] && currMinEdge > minDist[node]) {
                    currMinEdge = minDist[node];
                    currNode = node;
                }
            }
            
            mstCost += currMinEdge;
            edgesUsed++;
            inMST[currNode] = true;
            
            // Update adjacent nodes of current node.
            for (int nextNode = 0; nextNode < n; ++nextNode) {
                int weight = abs(points[currNode][0] - points[nextNode][0]) + 
                             abs(points[currNode][1] - points[nextNode][1]);
                
                if (!inMST[nextNode] && minDist[nextNode] > weight) {
                    minDist[nextNode] = weight;
                }
            }
        }
        
        return mstCost;
    }
};

If NNN is the number of points in the input array.

Time complexity: O(N2)O(N^2)O(N 
2
 ).

We pick all $$N$$ nodes one by one to include in the MST. Picking each node takes $$O(N)$$ time and after picking a node, we iterate over all of its adjacent nodes, which also takes $$O(N)$$ time.
Thus, the overall time complexity is $$ O(N \cdot (N + N)) = O(N^2) $$.
Space complexity: O(N)O(N)O(N).

We use two arrays each of size $$N$$, $$inMST$$ and $$minDist$$.
Thus, the overall space complexity is $$O(N + N) = O(N)$$.
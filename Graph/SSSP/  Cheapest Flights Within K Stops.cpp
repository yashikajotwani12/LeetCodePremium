There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.


We can treat this as a graph problem where:

Cities can be thought of as nodes in a graph.
The connections between each of the cities can be treated as the edges, and finally,
The cost of going from one city to another would be the weight of the edges in the graph.
The problem is to find the shortest path from a source to a destination with a constraint of k stops. This is a very good problem to practice various graph algorithms.


Approach 1: Breadth First Search
Intuition
A breadth-first search is a good algorithm to use if we want to find the shortest path in an unweighted graph. The property of BFS is that the first time a node is reached during the traversal, it is reached at the minimum distance from the source. The same cannot be said for a weighted graph. For a weighted graph, a path having more edges does not necessarily mean the path is more expensive. Thus, we cannot employ a normal breadth-first search for weighted graphs.

A breadth-first search has no way of knowing if a particular discovery of a node would give us the cheapest path to that node. The only possible way for BFS (or DFS) to find the shortest path in a weighted graph is to search the entire graph and keep recording the minimum distance from the source to the destination node.

However, our problem limits the number of stops to k. As a result, we need not search the paths with lengths greater than k + 1. A breadth-first search can be used for this problem because the number of levels to be explored by the algorithm is bounded by k.

In this approach, we will perform a level-wise iteration over the nodes. We will explore all the nodes at the present level (say l) before moving on to the nodes at the next level (l + 1). This level would correspond to the number of stops that would be limited by k. When we move from a level of l to l + 1, we will increase the stops by 1. We are allowed a maximum of k stops, which means we could go up to a maximum level of k + 1 from the src node, trying to reach dst at the minimum price.

We can maintain an array dist which stores the minimum price to reach each node. When we want to move to a node, we will only consider edges where the total price after traversing the edge is less than the currently calculated dist[node]. This optimization helps us avoid TLE.

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<pair<int,int>>adj[n+1];
        for(vector<int>flight:flights)
        {
            int srci = flight[0];
            int desti = flight[1];
            int costi = flight[2];
            adj[srci].push_back({desti, costi});

        }
        vector<int> dist(n, numeric_limits<int>::max());

        queue<pair<int,int>>q;
        q.push({src,0 });
        int stops=0;

        while(stops<=k and !q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                auto[node, distance] = q.front();
                q.pop();
                for(auto &[neighbour, price]:adj[node])
                {
                    if(price + distance >= dist[neighbour])
                    {
                        continue;
                      
                    }
                      dist[neighbour] = price +distance;
                        q.push({neighbour, dist[neighbour]});
                }
            }
            stops++;
        }
        return dist[dst] == numeric_limits<int>::max()? -1:dist[dst];
        
    }
};

Approach 2: Bellman ford


Bellman Ford's algorithm is used to find the shortest paths from the source node to all other vertices in a weighted graph.
 It depends on the idea that the shortest path contains at most N - 1 edges (where N is the number of nodes in the graph) because the shortest path cannot have a cycle.

Algorithm
1.Intialize the dist array, storing the minimum price to reach a node from the src node. Intialize it with large values.
2. Set the distance to the source as 0.
3. Run an outer loop k + 1 times.
4. In each iteration, make a copy of dist named temp and loop over all the edges in the graph trying to relax each one of them.
5. At each edge {x, y}, if the cost of reaching x (which is dist[x]) plus the cost of the edge is less than dist[y], then we can relax this edge by updating temp[y].
We need to use another array temp so that the distances from the previous iteration stored in dist don't change.
After finishing an iteration, copy the temp array to the dist array.
Our answer should be in dist[dst] at the end of the outer loop. If dist[dst] hasn't changed from the initial large value, then we never reached it, so return -1.

class Solution{
    public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k)
    {
        vector<int>dist(n, numeric_limits<int>::max());
        dist[src] =0;

        for(int i=0;i<=k;i++)
        {
            vector<int>temp(dist);
            for(auto &i:flights)
            {
                if(dist[i[0]] != numeric_limits<int>::max())
                {
                    temp[i[1]] = min(temp[i[1]], dist[i[0]] + i[2]);
                }
            }
        }
    }
}


Dijkstra
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto it : flights) {
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        vector<int> dist(n,1e9);
        dist[src] = 0;
        
        // {stops{node,cost}}
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        
        while(!q.empty()){
            int stops = q.front().first;
            int node = q.front().second.first;
            int cost = q.front().second.second;
            q.pop();
            
            if(stops > k)
                break;
            
            for(auto it : adj[node]) {
                int adjNode = it.first;
                int adjWt = it.second;
                
                if(cost + adjWt < dist[adjNode]) {
                    dist[adjNode] = cost + adjWt;
                    q.push({stops+1,{adjNode,dist[adjNode]}});
                }
            }
        }
        
        
        if(dist[dst] == 1e9)
            return -1;
        return dist[dst];
    }
};
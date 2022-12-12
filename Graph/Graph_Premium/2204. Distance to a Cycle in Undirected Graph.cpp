/* You are given a positive integer n representing the number of nodes in a connected undirected graph containing exactly one cycle. The nodes are numbered from 0 to n - 1 (inclusive).

You are also given a 2D integer array edges, where edges[i] = [node1i, node2i] denotes that there is a bidirectional edge connecting node1i and node2i in the graph.

The distance between two nodes a and b is defined to be the minimum number of edges that are needed to go from a to b.

Return an integer array answer of size n, where answer[i] is the minimum distance between the ith node and any node in the cycle.
Constraints:

3 <= n <= 105
edges.length == n
edges[i].length == 2
0 <= node1i, node2i <= n - 1
node1i != node2i
The graph is connected.
The graph has exactly one cycle.
There is at most one edge between any pair of vertices. */

class Solution {
public:
    /*
    Idea:
    1) Find which nodes are in a cycle (remove nodes using onion peeling)
    2) Add those nodes in cycle to a queue and use BFS to find distance of each node to any node in cycle
    */
   vector<int> distanceToCycle(int n, vector<vector<int>>& edges) {
        vector<int> degree(n,0);
        vector<bool> visited(n,false);
        vector<int> graph[n];
        
        for(auto &edge: edges)
        {
            degree[edge[0]]++;
            degree[edge[1]]++;
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        //Remove nodes layer-by-layer, nodes in cycle, would not be visited as for them degree will never be zero
        queue<int> nodeQ;
        
        for(int i = 0; i<n; i++)
        {
            if(degree[i]==1)
            {
                nodeQ.push(i);
                visited[i] = true;
            }
        }
       
        while(!nodeQ.empty())
        {
            int currNode = nodeQ.front();
            nodeQ.pop();
            
            for(int i = 0; i<graph[currNode].size(); i++)
            {
                int nextNode = graph[currNode][i];
                
                //this for making sure we don't add already processed nodes (this might happen cause it's a undirected graph, and edge is stored in both nodes' graph)
                
                if(visited[nextNode]) continue;
                
                degree[nextNode]--;
                
                if(degree[nextNode]==1)
                {
                    nodeQ.push(nextNode);
                    visited[nextNode] = true;
                }
            }
        }
        
        
        //for storing distances
        vector<int> dist(n,0);
        
         //now queue is empty, push cycleNodes into the queue and mark them as visited again, mark non-cyclic nodes as unvisited
        
        for(int i =0; i<n; i++)
        {
            //if the node was not visited, it's cyclic
            if(!visited[i])
            {
                nodeQ.push(i);
                visited[i] = true;
                dist[i] = 0;
            }else{
                //non-cyclic nodes , mark as unvisited for next iteration
                visited[i] = false;
            }
        }
        
        //to keep a track of the shortest distance from any cyclic node
        int currDist = 0;
        
        while(!nodeQ.empty())
        {
            currDist++;
            
            int sz = nodeQ.size();
            
            while(sz--)
            {
                int frontNode = nodeQ.front();
                nodeQ.pop();
            
                for(int i = 0; i<graph[frontNode].size(); i++)
                {
                    int nextNode = graph[frontNode][i];
                    
                    if(visited[nextNode]) continue;
            
                    nodeQ.push(nextNode);
                    visited[nextNode] = true;
                    dist[nextNode] = currDist;  
                }
            }
        }
        
        return dist;
    }
};
/* 
To find the shortest distance between any node and a cyclic node, we can start by finding the cyclic nodes first.
Once those are found, we can perform BFS to get the shortest distance from any non-cyclic node to cyclic ones.

For finding cyclic nodes:

We can use DFS, will try that out and post it as well soon.
We can use an onion peeling method, where we remove those nodes having a degree 1. Then we go to their neighbours and decrease their degrees and check if they can be added to the queue, and repeat the process till our queue is empty. Here, we can be sure that cyclic nodes won't be added to our queue because their degree would at least be 2 always, even when we remove all their non-cyclic neighbours.


For finding distance:

Only the non-visited nodes in the previous step, would be cyclic ones, so now we can add them to the queue and perform BFS.
Also, we maintain the shortest distance to a cyclic node from each new non-cyclic node, by keeping a track of the iterations of the queue. As soon as we discover a node for the first time, we assign it the distance. */
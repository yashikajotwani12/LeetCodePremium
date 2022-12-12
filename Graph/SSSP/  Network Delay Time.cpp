/* You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

 */


/*  Constraints:

1 <= k <= n <= 100
1 <= times.length <= 6000
times[i].length == 3
1 <= ui, vi <= n
ui != vi
0 <= wi <= 100
All the pairs (ui, vi) are unique. (i.e., no multiple edges.) */

1. DFS
2. BFS
3. Dijkstra's Algo

2. BFS code

class Solution {
public:
    vector<pair<int,int>>adj[101];
    void bfs(vetcor<int>&ans,int k )
    {
        queue<int>q;
        q.push(k);
        ans[k] =0;
        while(!q.empty())
        {
            int currnode = q.front();
            q.pop();
            for(pair<int,int> i :adj[currnode])
            {
                int  neighbour = i.first;
                int time = i.second;

                int arrival = ans[currnode] + time;
                if(ans[neighbour] > arrival)
                {
                    ans[neighbour] = arrival;
                    q.push(neighbour);
                } 

            }
        }
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        for(vector<int>time:times)
        {
            int source = time[0];
            int dest = time[1];
            int tarveltime = time[2];
            adj[source].push_back({dest, tarveltime});
        }
        vector<int> ans(n+1, INT_MAX);

        bfs(ans, k);
        int res = INT_MIN;
        for(int i=1;i<=n;i++)
        {
            res = max(res, ans[i]);
        }
     
     return res == INT_MAX? -1:res;
        
    }
};

/* 3. Dijkstra Algo


Algorithm

Create an adjacency list such that adj[source] contains all destination nodes (dest) that the signal can travel to from the source node (source). For each destination node, there will be a pair (time, dest). Here, time denotes the time required for the signal to travel from source to dest.

For all nodes, initialize signalReceivedAt as a large value to signify that, so far, no signal has been received.

Initialize priority queue with the pair of starting node kkk and its distance 000, store its distance in signalReceivedAt as 000. While the priority queue is not empty:

Pop the top node currNode from the priority queue.
Traverse all outgoing edges connected to currNode.
Add the adjacent node neighborNode to the priority queue only if the current path takes less time than the value at signalReceivedAt[neighborNode]. Update the time at signalReceivedAt[neighborNode] to current path time.
Find the maximum value in the array signalReceivedAt. If any value in signalReceivedAt is still the large value we initialized the array with, then return -1 as that node is not reachable from k. Otherwise, return the maximum value in the array.
 */

class Solution {
public:
    vector<pair<int,int>>adj[101];
    void Dijkstra(vector<int>&ans, int k, int n)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push({0, k});
        ans[k]=0;
        while(!pq.empty())
        {
            int currNodetime = pq.top().first;
            int currnode = pq.top().second;
            pq.pop();
            if(currNodetime > ans[currnode])
            {
                continue;
            }

            for(pair<int,int>edge: adj[currnode])
            {
                int time = edge.first;
                int neighborNode = edge.second;

                if(ans[neighborNode] > time + currNodetime)
                {
                    ans[neighborNode] = time + currNodetime;
                }
            }
        }
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        for(vector<int>time:times)
        {
            int src = time[0];
            int dest = time[1];
            int traveltime = time[2];
            adj[src].push_back({traveltime, dest});
        }
        vector<int>ans(n+1, INT_MAX);
        Dijkstra(ans, k,n);
        int res =INT_MIN;
        for(int i=1;i<=n;i++)
        {
            res = max(res, ans[i]);
            

        }
        return res == INT_MAX?-1: res;
        
    }
};
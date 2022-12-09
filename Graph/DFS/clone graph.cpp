/* Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
Output: [[2,4],[1,3],[2,4],[1,3]]
Explanation: There are 4 nodes in the graph.
1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).


Approach 1: Depth First Search
Intuition

Note: As we can see this question has garnered a lot of negative reviews. It has a lot more dislikes than the likes. We have tried to improve the problem statement to make it more understandable. However, these are the kinds of situations you might get into in an interview when the problem statement might look a little absurd. What is important then is to ask the interviewer to clarify the problem. This problem statement was confusing to me as well initially and that's why I decided to write the solution hoping to clarify most of the doubts that the readers might have had.

The basic intuition for this problem is to just copy as we go. We need to understand that we are dealing with a graph and this means a node could have any number of neighbors. This is why neighbors is a list. What is also crucial to understand is that we don't want to get stuck in a cycle while we are traversing the graph. According to the problem statement, any given undirected edge could be represented as two directional edges. So, if there is an undirected edge between node A and node B, the graph representation for it would have a directed edge from A to B and another from B to A. After all, an undirected graph is a set of nodes that are connected together, where all the edges are bidirectional. How else would you say that A could be reached from B and B could be reached from A?


1. Cloned Graph has all nodes as newnodes and don't have node as reference to given original graph.
2. Graph has no practical edges, i.e no pointers for edges.
         (2,3)            (1,3)<---adj list
		  (1)-------------(2)
		    |              |
			|              |
			|              |
		  (4)-------------(3)
		  (1,3)          (2,4)
If i say '1' is my starting point and how should i jump to '2' for that i have to iterate through this adjacency list.


We need to traverse all node of original graph and as soon as we reach a node, we will make a copy node.
And recur for rest of the graph.
This is a typical recursion type problem implemented on Graph.
For 'Recursion' we use basically 'DFS' or 'BFS'.
I am using DFS

1. We use HashMap to solve it and using DFS.
2. Initially our hash map will be empty and we try to map the old node with the new node or the copy node.
3. We start with any entry point.
4. I am using '1' as my entry point.

Now lets see how its going i am starting with 1 and whenever i visited a new node i coloned it and put in there.
We are using DFS so algorithm is like 'it starts at the root node (select some arbitrary node as root node in the case of a graph) and explores as far as possible along each branch before backtracking.
So the basic idea is to start from the root or any arbitrary node and mark the node and move to the adjacentunmarked node and continue this loop until there is no unmarked adjacent node. 
Then backtrack and check for other unmarked nodes and traverse them. Finally, print the nodes in the path.'
So we are using HashMap to put all the visited node or old node there with clone one to.
 _________
| HashMap |
 ----------
|Old|Clone| 
| 1  | 1 |
|  2 | 2 |
|  3 | 3 |                                                     
|  4 | 4 |                                                                                                            
---------

Now i started with 1 so i cloned it and from 1 can go to 2 and 4 so i go 2 and when i visited 2 i cloned 2 and now fro  i have two choices either go to previous one that is 1 or discover 3 i.e new node
so accordingly to dfs i go to 3 and from 3 i can go to 4 i go there and cloned it. Now if we see fro each node we have viisted to a new node but what about 4. So here half part of Dfs is completed,
and now its time for recursive call to go back and now from here we check from current node i can go where and where.
And follow the same rules over there.

BUT BEFORE STARTING ANY CLONING WE HAVE TO CHECK THAT IF WE HAVE CLONED THAT NODE ALREADY THERE OR NOT. IF NOT THAN ONLY WE CLONED IT. 

Thats the only reason we are using hash map so that we don't need to clone again and again.
For every uncloned node we make a clone and iterate over the neighbors of original node using dfs traversal or bfs traversal.
 */
class Solution {
    public:
    Node* dfs(Node* cur,unordered_map<Node*,Node*>& mp)
    {
        vector<Node*> neighbour;
        Node* clone=new Node(cur->val);
        mp[cur]=clone;
            for(auto it:cur->neighbors)
            {
                if(mp.find(it)!=mp.end())   //already clone and stored in map
                {
                    neighbour.push_back(mp[it]);    //directly push back the clone node from map to neigh
                }
                else
                    neighbour.push_back(dfs(it,mp));
            }
            clone->neighbors=neighbour;
            return clone;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> mp;
        if(node==NULL)
            return NULL;
        if(node->neighbors.size()==0)   //if only one node present no neighbors
        {
            Node* clone= new Node(node->val);
            return clone; 
        }
        return dfs(node,mp);
    }
};


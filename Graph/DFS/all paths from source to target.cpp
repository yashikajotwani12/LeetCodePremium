/* Algorithm
The above idea might remind one of the Depth-First Search (DFS) traversal algorithm. Indeed, often the backtracking algorithm assumes the form of DFS, but with the additional step of backtracking.

And for the DFS traversal, we often adopt the recursion as its main form of implementation. With recursion, we could implement a backtracking algorithm in a rather intuitive and concise way. We break it down into the following steps:

Essentially, we want to implement a recursive function called backtrack(currNode, path) which continues the exploration, given the current node and the path traversed so far.

Within the recursive function, we first define its base case, i.e. the moment we should terminate the recursion. Obviously, we should stop the exploration when we encounter our target node. So the condition of the base case is currNode == target.

As the body of our recursive function, we should enumerate through all the neighbor nodes of the current node.

For each iteration, we first mark the choice by appending the neighbor node to the path. Then we recursively invoke our backtrack() function to explore deeper. At the end of the iteration, we should reverse the choice by popping out the neighbor node from the path, so that we could start all over for the next neighbor node.

Once we define our backtrack() function, it suffices to add the initial node (i.e. node with index 0) to the path, to kick off our backtracking exploration. */


class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int target = int(graph.size()) - 1;
        vector<int> path{0};
        vector<vector<int>> results;

        function<void(int, vector<int>&)> backtrack = [&](int currNode, vector<int>& path) {
            if (currNode == target) {
                results.push_back(vector(path));
                return;
            }
            for (int nextNode : graph[currNode]) {
                path.push_back(nextNode);
                backtrack(nextNode, path);
                path.pop_back();
            }
        };

        backtrack(0, path);
        return results;
    }
};


As a result, for a graph with NNN nodes, at maximum, there could be ∑i=0N−22i=2N−1−1\sum_{i=0}^{N-2}{2^i} = 2^{N-1} - 1∑ 
i=0
N−2
​
 2 
i
 =2 
N−1
 −1 number of paths between the starting and the ending nodes.

Time Complexity: O(2N⋅N)\mathcal{O}(2^N \cdot N)O(2 
N
 ⋅N)

As we calculate shortly before, there could be at most 2N−1−12^{N-1} - 12 
N−1
 −1 possible paths in the graph.

For each path, there could be at most N−2N-2N−2 intermediate nodes, i.e. it takes O(N)\mathcal{O}(N)O(N) time to build a path.

To sum up, a loose upper-bound on the time complexity of the algorithm would be (2N−1−1)⋅O(N)=O(2N⋅N)(2^{N-1} - 1) \cdot \mathcal{O}(N) = \mathcal{O}(2^N \cdot N)(2 
N−1
 −1)⋅O(N)=O(2 
N
 ⋅N), where we consider it takes O(N)\mathcal{O}(N)O(N) efforts to build each path.

To estimate a lower-bound on the time complexity, you can imagine an extreme but valid input: the edge set of the graph is {⟨i,j⟩∣0≤i<j<N}\{\langle i,j\rangle| 0 \le i < j < N\}{⟨i,j⟩∣0≤i<j<N}, that is, there exists an edge from node iii to jjj if and only if i<ji<ji<j. In this case, we can arbitrarily build a set of nodes from 1 to N−1N-1N−1 and construct a valid path by adding the starting point 0 and the end point N−1N-1N−1.

For each path of kkk intermediate nodes, we have to take O(k)O(k)O(k) time to build and deep copy the path to the result set. Thus, the total time complexity is at least ∑k=0N−2k⋅(N−2k)=2N−3⋅(N−2)\sum_{k=0}^{N-2}{k \cdot {N-2 \choose k}} = 2^{N-3} \cdot (N-2)∑ 
k=0
N−2
​
 k⋅( 
k
N−2
​
 )=2 
N−3
 ⋅(N−2), which is still O(2N⋅N)\mathcal{O}(2^N \cdot N)O(2 
N
 ⋅N).

Space Complexity: O(N)\mathcal{O}(N)O(N)

Since we also applied recursion in the algorithm, the recursion could incur additional memory consumption in the function call stack. The stack can grow up to NNN consecutive calls. Meanwhile, along with the recursive call, we also keep the state of the current path, which could take another O(N)\mathcal{O}(N)O(N) space. Therefore, in total, the recursion would require additional O(N)\mathcal{O}(N)O(N) space.

However, apart from our algorithm, since at most we could have 2N−1−12^{N-1}-12 
N−1
 −1 paths as the results and each path can contain up to NNN nodes, we need extra O(2N⋅N)\mathcal{O}(2^N \cdot N)O(2 
N
 ⋅N) space to store and return the results.


Approach 2: Top-Down Dynamic Programming
The backtracking approach applies the paradigm of divide-and-conquer, which breaks the problem down to smaller steps.

As one knows, there is another algorithm called Dynamic Programming (DP), which also embodies the idea of divide-and-conquer.

As it turns out, we could also apply the DP algorithm to this problem, although it is less optimal than the backtracking approach as one will see later.

More specifically, we adopt the Top-Down DP approach, where we take a laissez-faire strategy assuming that the target function would work out on its own.

Given a node currNode, our target function is allPathsToTarget(currNode), which returns all the paths from the current node to the target node.

The target function could be calculated by iterating through the neighbor nodes of the current node, which we summarize with the following recursive formula:

∀nextNode∈neighbors(currNode),allPathsToTarget(currNode)={currNode+allPathsToTarget(nextNode)}\forall \text{nextNode} \in \text{neighbors}(\text{currNode}), \\ \\ \text{allPathsToTarget}(\text{currNode}) = \{ \text{currNode} + \text{allPathsToTarget}(\text{nextNode}) \}∀nextNode∈neighbors(currNode),
allPathsToTarget(currNode)={currNode+allPathsToTarget(nextNode)}

The above formula can be read intuitively as: "the paths from the current node to the target node consist of all the paths starting from each neighbor of the current node."

Algorithm
Based on the above formula, we could implement a DP algorithm.

First of all, we define our target function allPathsToTarget(node).

Naturally our target function is a recursive function, whose base case is when the given node is the target node.

Otherwise, we iterate through its neighbor nodes, and we invoke our target function with each neighbor node, i.e. allPathsToTarget(neighbor)

With the returned results from the target function, we then prepend the current node to the downstream paths, in order to build the final paths.

With the above defined target function, we simply invoke it with the desired starting node, i.e. node 0.

Note that, there is an important detail that we left out in the above step. In order for the algorithm to be fully-qualified as a DP algorithm, we should reuse the intermediate results, rather than re-calculating them at each occasion.

Specially, we should cache the results returned from the target function allPathsToTarget(node), since we would encounter a node multiple times if there is an overlapping between paths. Therefore, once we know the paths from a given node to the target node, we should keep it in the cache for reuse. This technique is also known as memoization.

Implementation

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int target = int(graph.size()) - 1;
        map<int, vector<vector<int>>> memo;
        function<vector<vector<int>>(int)> allPathsToTarget = [&](int currNode) {
            if (memo.count(currNode)) return memo[currNode];
            vector<vector<int>> results;
            if (currNode == target) {
                results.push_back(vector<int>{target});
            } else {
                for (int nextNode : graph[currNode]) {
                    for (vector<int>& path : allPathsToTarget(nextNode)) {
                        vector<int> newPath{currNode};
                        newPath.insert(newPath.end(), path.begin(), path.end());
                        results.push_back(newPath);
                    }
                }
            }
            memo[currNode] = results;
            return results;
        };
        return allPathsToTarget(0);
    }
};

/* Complexity Analysis
Let NNN be the number of nodes in the graph. As we estimated before, there could be at most 2N−1−12^{N-1}-12 
N−1
 −1 number of paths.

Time Complexity: O(2N⋅N)\mathcal{O}(2^N \cdot N)O(2 
N
 ⋅N).

To estimate the overall time complexity, let us start from the last step when we prepend the starting node to each of the paths returned from the target function. Since we have to copy each path in order to create new paths, it would take up to NNN steps for each final path. Therefore, for this last step, it could take us O(2N−1⋅N)\mathcal{O}(2^{N-1} \cdot N)O(2 
N−1
 ⋅N) time.

Right before the last step, when the maximal length of the path is N−1N-1N−1, we should have 2N−22^{N-2}2 
N−2
  number of paths at this moment.

Deducing from the above two steps, again a loose upper-bound of the time complexity would be O(∑i=1N2i−1⋅i)=O(2N⋅N)\mathcal{O}(\sum_{i=1}^{N}{2^{i-1}\cdot i}) = \mathcal{O}(2^N \cdot N)O(∑ 
i=1
N
​
 2 
i−1
 ⋅i)=O(2 
N
 ⋅N)

Similar to the complexity analysis in Approach 1, we can also get a lower-bound of the time complexity as O(2N⋅N)\mathcal{O}(2^N \cdot N)O(2 
N
 ⋅N). So the time complexity should be O(2N⋅N)\mathcal{O}(2^N \cdot N)O(2 
N
 ⋅N).

The two approach might have the same asymptotic time complexity. However, in practice the DP approach is slower than the backtracking approach, since we copy the intermediate paths over and over.

Note that, the performance would be degraded further, if we did not adopt the memoization technique here.

Space Complexity: O(2N⋅N)\mathcal{O}(2^N \cdot N)O(2 
N
 ⋅N)

Similarly, since at most we could have 2N−1−12^{N-1}-12 
N−1
 −1 paths as the results and each path can contain up to NNN nodes, the space we need to store the results would be O(2N⋅N)\mathcal{O}(2^N \cdot N)O(2 
N
 ⋅N).

Since we also applied recursion in the algorithm, it could incur additional memory consumption in the function call stack. The stack can grow up to NNN consecutive calls. However, the space bottleneck in this approach is to memorize the results of intermedia calls of allPathsToTarget(node). The total memory cost for that is estimated as ∑i=1ni⋅2i=O(2N⋅N)\sum_{i=1}^n i \cdot 2^i = \mathcal{O}(2^N \cdot N)∑ 
i=1
n
​
 i⋅2 
i
 =O(2 
N
 ⋅N) like we analyzed in Approach 1.

Thus, the space complexity is O(2N⋅N)\mathcal{O}(2^N \cdot N)O(2 
N
 ⋅N) either with or without the space for the final returned result.
 */



class Solution {
public:
    // DFS
    void dfs(vector<vector<int>>& graph, int node, vector<int>& path,
             vector<vector<int>>& paths) {
        path.push_back(node);
        if (node == graph.size() - 1) {
            paths.emplace_back(path);
            return;
        }
        vector<int> nextNodes = graph[node];
        for (int nextNode : nextNodes) {
            dfs(graph, nextNode, path, paths);
            path.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        if (graph.size() == 0) {
            return paths;
        }
        vector<int> path;
        dfs(graph, 0, path, paths);
        return paths;
    }
};
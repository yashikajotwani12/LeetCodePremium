/* There are n people in a social group labeled from 0 to n - 1. You are given an array logs where logs[i] = [timestampi, xi, yi] indicates that xi and yi will be friends at the time timestampi.

Friendship is symmetric. That means if a is friends with b, then b is friends with a. Also, person a is acquainted with a person b if a is friends with b, or a is a friend of someone acquainted with b.

Return the earliest time for which every person became acquainted with every other person. If there is no such earliest time, return -1. */



Union-Find (a.k.a Disjoint-Set) is a data structure that keeps track of the connectivities among interconnected individuals efficiently. With Union-Find, one can quickly determine which group a specific individual belongs to. In addition, one can quickly merge two individuals together along with the two groups that they belong to.



In order to discover the earliest moment, we must first ensure that we read through the logs in chronological order. Since there is no mentioning whether the logs are ordered or not in the problem description, we need to sort them first.

Once the logs are sorted by time, we then iterate through them, while applying the Union-Find data structure.

For each log, we connect the two individuals that were involved in the log, by applying the union(a, b) function.
Each log adds more connections among the individuals. A connection is useful if the two individuals are separated (disjoint), or redundant if the two individuals are connected already via other individuals.
Initially, we treat each individual as a separate group. The number of groups decreases along with the useful merging operations. The moment when the number of groups is reduced to one is the earliest moment when everyone becomes connected (friends).



class Solution {
    vector<int>parent;
    int find(int x) {
        return parent[x] == x ? x : find(parent[x]);
    }
public:
    int earliestAcq(vector<vector<int>>& logs, int N) {
        
        sort(logs.begin(), logs.end());
        
        parent.resize(N, 0);
        for (int i = 0; i < N; i++)
            parent[i] = i;
        
        for (int i = 0; i < logs.size(); i++) {
            int x = find(logs[i][1]);
            int y = find(logs[i][2]);
            if (x != y) {
                N--;
                if (N == 1) return logs[i][0];
                parent[y] = x;
            }
        }
        
        return -1;
    }
};
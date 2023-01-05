You are given an empty 2D binary grid  of size m x n. The grid represents a map where 0's represent water and 1's represent land. Initially, all the cells of grid are water cells (i.e., all the cells are 0's).

We may perform an add land operation which turns the water at position into a land. You are given an array positions where positions[i] = [ri, ci] is the position (ri, ci) at which we should operate the ith operation.

Return an array of integers answer where answer[i] is the number of islands after turning the cell (ri, ci) into a land.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.


class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        
    }
};

Example 1:

Input: m = 3, n = 3, positions = [[0,0],[0,1],[1,2],[2,1]]
Output: [1,1,2,3]
Explanation: Initially, the 2d grid grid is filled with water. (Assume 0 represents water and 1 represents land).
0 0 0
0 0 0
0 0 0
Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land. 1 0 0
0 0 0   Number of islands = 1
0 0 0

// dfs solution
// Time:  O(k * m * n), k is the length of the positions
// Space: O(m * n)

class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<int> result;
        vector<vector<int>> grid(m, vector<int>(n));
        vector<vector<int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int count = 0;
        for (const auto& pos : positions) {
            int x = pos[0], y = pos[1];
            if (grid[x][y]) {
                result.emplace_back(count);
                continue;
            }
            grid[x][y] = 1;
            ++count;
            for (const auto& dir : dirs) {
                int i = x + dir[0], j = y + dir[1];
                if (i < 0 || i >= m || j < 0 || j >= n || !grid[i][j]) {
                    continue;
                }
                int p = findParent(parent, x * n + y);
                int q = findParent(parent, i * n + j);
                if (p != q) {
                    parent[p] = q;
                    --count;
                }
            }
            result.emplace_back(count);
        }
        return result;
    }


private:
    int findParent(vector<int>& parent, int i) {
        if (parent[i] == -1) {
            parent[i] = i;
        }
        if (parent[i] != i) {
            parent[i] = findParent(parent, parent[i]);
        }
        return parent[i];
    }
};

// union find solution
// Time:  O(k * m * n), k is the length of the positions
// Space: O(m * n)
class Solution2 {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<int> result;
        vector<vector<int>> grid(m, vector<int>(n));
        vector<vector<int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int count = 0;
        parent.resize(m * n, -1);
        rank.resize(m * n, 0);
        for (const auto& pos : positions) {
            int x = pos[0], y = pos[1];
            if (grid[x][y]) {
                result.emplace_back(count);
                continue;
            }
            grid[x][y] = 1;
            ++count;
            for (const auto& dir : dirs) {
                int i = x + dir[0], j = y + dir[1];
                if (i < 0 || i >= m || j < 0 || j >= n || !grid[i][j]) {
                    continue;
                }
                int p = findParent(x * n + y);
                int q = findParent(i * n + j);
                if (p != q) {
                    if (rank[p] > rank[q]) {
                        parent[q] = p;
                    } else if (rank[p] < rank[q]) {
                        parent[p] = q;
                    } else {
                        parent[p] = q;
                        ++rank[q];
                    }
                    --count;
                }
            }
            result.emplace_back(count);
        }
        return result;
    }

private:
    int findParent(int i) {
        if (parent[i] == -1) {
            parent[i] = i;
        }
        if (parent[i] != i) {
            parent[i] = findParent(parent[i]);
        }
        return parent[i];
    }

    vector<int> parent;
    vector<int> rank;
};

// Time:  O(k * m * n), k is the length of the positions
// Space: O(m * n)

class Solution3 {

public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<int> result;
        vector<vector<int>> grid(m, vector<int>(n));
        vector<vector<int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int count = 0;
        parent.resize(m * n, -1);
        rank.resize(m * n, 0);
        for (const auto& pos : positions) {
            int x = pos[0], y = pos[1];
            if (grid[x][y]) {
                result.emplace_back(count);
                continue;
            }
            grid[x][y] = 1;
            ++count;
            for (const auto& dir : dirs) {
                int i = x + dir[0], j = y + dir[1];
                if (i < 0 || i >= m || j < 0 || j >= n || !grid[i][j]) {
                    continue;
                }
                int p = findParent(x * n + y);
                int q = findParent(i * n + j);
                if (p != q) {
                    parent[p] = q;
                    --count;
                }
            }
            result.emplace_back(count);
        }
        return result;
    }

private:

    int findParent(int i) {
        if (parent[i] == -1) {
            parent[i] = i;
        }
        if (parent[i] != i) {
            parent[i] = findParent(parent[i]);
        }
        return parent[i];
    }

    vector<int> parent;
    vector<int> rank;
};


class UnionFind {
public:
  UnionFind(int N) {
    count = 0;
    for (int i = 0; i < N; ++i) {
      parent.push_back(-1);
      rank.push_back(0);
    }
  }

  bool isValid(int i) const {
    return parent[i] >= 0;
  }

  void setParent(int i) {
    parent[i] = i;
    ++count;
  }

  int find(int i) { // path compression
    if (parent[i] != i) parent[i] = find(parent[i]);
    return parent[i];
  }

  void Union(int x, int y) { // union with rank
    int rootx = find(x);
    int rooty = find(y);
    if (rootx != rooty) {
      if (rank[rootx] > rank[rooty]) parent[rooty] = rootx;
      else if (rank[rootx] < rank[rooty]) parent[rootx] = rooty;
      else {
        parent[rooty] = rootx; rank[rootx] += 1;
      }
      --count;
    }
  }

  int getCount() const {
    return count;
  }

private:
  vector<int> parent;
  vector<int> rank;
  int count; // # of connected components
};

class Solution {
public:
  vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
    vector<int> ans;
    UnionFind uf (m * n);

    for (auto& pos : positions) {
      int r = pos.first;
      int c = pos.second;
      // check pos's neighbors to see if they are in the existing islands or not
      vector<int> overlap; // how many existing islands overlap with 'pos'
      if (r - 1 >= 0 && uf.isValid((r-1) * n + c)) overlap.push_back((r-1) * n + c);
      if (r + 1 < m && uf.isValid((r+1) * n + c)) overlap.push_back((r+1) * n + c);
      if (c - 1 >= 0 && uf.isValid(r * n + c - 1)) overlap.push_back(r * n + c - 1);
      if (c + 1 < n && uf.isValid(r * n + c + 1)) overlap.push_back(r * n + c + 1);

      int index = r * n + c;
      uf.setParent(index);
      for (auto i : overlap) uf.Union(i, index);
      ans.push_back(uf.getCount());
    }

    return ans;
  }
};
You are given an m x n grid grid of values 0, 1, or 2, where:

each 0 marks an empty land that you can pass by freely,
each 1 marks a building that you cannot pass through, and
each 2 marks an obstacle that you cannot pass through.
You want to build a house on an empty land that reaches all buildings in the shortest total travel distance. You can only move up, down, left, and right.

Return the shortest travel distance for such a house. If it is not possible to build such a house according to the above rules, return -1.

The total travel distance is the sum of the distances between the houses of the friends and the meeting point.

The distance is calculated using Manhattan Distance, where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.

Input: grid = [[1,0,2,0,1],[0,0,0,0,0],[0,0,1,0,0]]
Output: 7
Explanation: Given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2).
The point (1,2) is an ideal empty land to build a house, as the total travel distance of 3+3+1=7 is minimal.
So return 7.

Input: grid = [[1,0]]
Output: 1

Input: grid = [[1]]
Output: -1

// if no empty cell then return -1
// if no building then return -1
// if no building can reach all empty cell then return -1

// BFS solution

// Time:  O(m * n * (m + n))
// Space: O(m * n)

// bfs solution
// Time:  O(m * n * (m + n))
// Space: O(m * n)

class Solution {

public:

    int shortestDistance(vector<vector<int>>& grid) {

        const int m = grid.size();

        const int n = grid[0].size();

        vector<vector<int>> dist(m, vector<int>(n));

        vector<vector<int>> reach(m, vector<int>(n));

        int num_buildings = 0;

        for (int i = 0; i < m; ++i) {

            for (int j = 0; j < n; ++j) {

                if (grid[i][j] == 1) {

                    ++num_buildings;

                    bfs(grid, i, j, dist, reach);

                }

            }

        }

        int shortest = numeric_limits<int>::max();

        for (int i = 0; i < m; ++i) {

            for (int j = 0; j < n; ++j) {

                if (grid[i][j] == 0 && reach[i][j] == num_buildings) {

                    shortest = min(shortest, dist[i][j]);

                }

            }

        }

        return shortest == numeric_limits<int>::max() ? -1 : shortest;

    }

private:

    void bfs(const vector<vector<int>>& grid, int x, int y,

             vector<vector<int>>& dist, vector<vector<int>>& reach) {

        const int m = grid.size();

        const int n = grid[0].size();

        queue<pair<int, int>> q;

        q.emplace(x, y);

        vector<vector<int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        vector<vector<bool>> lookup(m, vector<bool>(n));

        int distance = 0;

        while (!q.empty()) {

            ++distance;

            for (int i = q.size(); i > 0; --i) {

                const auto [x, y] = q.front(); q.pop();

                for (const auto& dir : dirs) {

                    const int nx = x + dir[0];

                    const int ny = y + dir[1];

                    if (nx < 0 || nx >= m || ny < 0 || ny >= n ||

                        grid[nx][ny] != 0 || lookup[nx][ny]) {

                        continue;

                    }

                    lookup[nx][ny] = true;

                    dist[nx][ny] += distance;

                    ++reach[nx][ny];

                    q.emplace(nx, ny);

                }

            }

        }

    }

};




// trying to find the shortest distance from all buildings
// we can use bfs to find the shortest distance from each building to all empty cell
Hard Problem
Companies: Amazon, Google

Given an n x n integer matrix grid, return the minimum sum of a falling path with non-zero shifts.

A falling path with non-zero shifts is a choice of exactly one element from each row of grid such that no two elements chosen in adjacent rows are in the same column.


Input: arr = [[1,2,3],[4,5,6],[7,8,9]]
Output: 13
Explanation: 
The possible falling paths are:
[1,5,9], [1,5,7], [1,6,7], [1,6,8],
[2,4,8], [2,4,9], [2,6,7], [2,6,8],
[3,4,8], [3,4,9], [3,5,7], [3,5,9]
The falling path with the smallest sum is [1,5,7], so the answer is 13.


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        const int n = grid.size();
        if(n == 1)
            return grid[0][0];
        
        vector<int>prev(n);
        //base case :
        for(int j = 0; j < n; j++)
            prev[j] = grid[0][j];
        
        for(int i = 1; i < n; i++){
            vector<int> curr(n);
            for(int j = 0; j < n; j++){
                int ans = INT_MAX;
                for(int k = 0; k < n; k++){
                    if(j == k)
                        continue;
                     ans = min(ans, prev[k] + grid[i][j]);
                }
                curr[j] = ans;
            }
            prev = curr;
        }
        return *min_element(prev.begin(), prev.end());
    }
};
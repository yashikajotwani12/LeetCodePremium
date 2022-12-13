class Solution {
public:
    int n, m;
    int rec(vector<vector<int>> &matrix, int i, int j, vector<vector<int>> &memo){
        if(i == n || j == m || i < 0 || j < 0) return INT_MAX;
        if(i == n-1){
            return matrix[i][j];
        }
        if(memo[i][j] != INT_MAX) return memo[i][j];
        
        int down = rec(matrix, i+1, j, memo);
        int downLeft = rec(matrix, i+1, j-1, memo);
        int downRight = rec(matrix, i+1, j+1, memo);
        
        return memo[i][j] = min(down, min(downLeft, downRight)) + matrix[i][j];
    }
    int minFallingPathSum(vector<vector<int>>& matrix){
        n = matrix.size(), m = matrix[0].size();
        int mini = INT_MAX;
        for(int i = 0; i < m; i++){
            vector<vector<int>> memo(101, vector<int> (101, INT_MAX));
            mini = min(mini, rec(matrix, 0, i, memo));
        }
        return mini;
    }
};
class Solution {
public:
    int n, m;
    int rec(vector<vector<int>> &matrix, int i, int j){
        if(i == n || j == m || i < 0 || j < 0) return INT_MAX;
        if(i == n-1){
            return matrix[i][j];
        }
        int down = rec(matrix, i+1, j);
        int downLeft = rec(matrix, i+1, j-1);
        int downRight = rec(matrix, i+1, j+1);
        
        return min(down, min(downLeft, downRight)) + matrix[i][j];
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        n = matrix.size(), m = matrix[0].size();
        int mini = INT_MAX;
        for(int i = 0; i < m; i++){
            mini = min(mini, rec(matrix, 0, i));
        }
        return mini;
    }
};
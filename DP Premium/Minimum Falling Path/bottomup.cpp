class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int> (m));
        
        for(int j = 0; j < m; j++) dp[0][j] = matrix[0][j];
        
        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                int up = dp[i-1][j];
                int upLeft = j-1 >= 0 ? dp[i-1][j-1] : INT_MAX;
                int upRight = j+1 < m ? dp[i-1][j+1] : INT_MAX;
                dp[i][j] = min(up, min(upLeft, upRight)) + matrix[i][j];
            }
        }
        // Picking the minimum answer
        return *min_element(begin(dp[n-1]), end(dp[n-1]));
    }
};
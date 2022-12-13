class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        // vector<vector<int>> dp(n, vector<int> (m));
        vector<int> prev(m), curr(m);
        
        for(int j = 0; j < m; j++) prev[j] = matrix[0][j];
        
        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                int up = prev[j];
                int upLeft = j-1 >= 0 ? prev[j-1] : INT_MAX;
                int upRight = j+1 < m ? prev[j+1] : INT_MAX;
                curr[j] = min(up, min(upLeft, upRight)) + matrix[i][j];
            }
            prev = curr;
        }
        // Picking the minimum answer
        return *min_element(begin(prev), end(prev));
    }
};
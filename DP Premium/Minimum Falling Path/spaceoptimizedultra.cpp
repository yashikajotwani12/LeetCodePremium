class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
            
        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                int up = matrix[i-1][j];
                int upLeft = j-1 >= 0 ? matrix[i-1][j-1] : INT_MAX;
                int upRight = j+1 < m ? matrix[i-1][j+1] : INT_MAX;
                matrix[i][j] = min(up, min(upLeft, upRight)) + matrix[i][j];
            }
        }
        // Picking the minimum answer
        return *min_element(begin(matrix[n-1]), end(matrix[n-1]));
    }
};
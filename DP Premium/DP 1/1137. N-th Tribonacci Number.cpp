Input: n = 4
Output: 4
Explanation:
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4

class Solution {
public:
    int tribonacci(int n) {
        // DP
        int dp[38] = {0, 1, 1};
        for(int i=3;i<=n;i++)
        {
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];

        }
        return dp[n];
        
    }
};


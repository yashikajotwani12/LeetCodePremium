You have two types of tiles: a 2 x 1 domino shape and a tromino shape. You may rotate these shapes.

Given an integer n, return the number of ways to tile an 2 x n board. Since the answer may be very large, return it modulo 109 + 7.

In a tiling, every square must be covered by a tile. Two tilings are different if and only if there are two 4-directionally adjacent cells on the board such that exactly one of the tilings has both squares occupied by a tile.

// https://www.youtube.com/watch?v=7cijrfUkQzc

class Solution {
public:
    int numTilings(int n) {
        if(n==1) return 1;
        else if(n==2) return 2;

        int modulo = 1e9+7;
        vector<int>dp(n+1);

        dp[1]=1;
        dp[2] =2;
        dp[3] = 5;
        for(int i=4;i<=n;i++)
        {
            dp[i] = (2*dp[i-1]%modulo + dp[i-3]%modulo) %modulo;
        }
        return dp[n];
    }
};
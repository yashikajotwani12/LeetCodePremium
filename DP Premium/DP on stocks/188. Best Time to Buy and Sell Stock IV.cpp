You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.


class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n==0) return 0;
        if(k >= n/2)
        {
            int maxp =0;
            for(int i=1;i<prices.size();i++)
            {
                if(prices[i] > prices[i-1])
                {
                    maxp += prices[i] - prices[i-1];
                }
            }
            return maxp;
        }

        }

        
        vector<vector<int>>dp(k+1, vector<int>(n,0));
        
};

Here, two approaches are introduced: Dynamic Programming approach, and Merging approach. Both are awesome, but the first method is more universal to other problems.

dp[day_number][used_transaction_number][stock_holding_status]
Because of three needed characteristics (day number, transaction number used, stock holding status), a three-dimensional array is our choice.
stock_holding_status = 0 means we don't hold any stock on that day.
stock_holding_status = 1 means we hold a stock on that day.

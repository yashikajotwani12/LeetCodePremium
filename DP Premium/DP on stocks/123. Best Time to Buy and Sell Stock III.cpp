Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.

Find the maximum profit you can achieve. You may complete at most two transactions.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==0) return 0;
        vector<int>left(n,0);
        vector<int>right(n,0);

        int minp = prices[0];
        for(int i=1;i<n;i++)
        {
            minp = min(minp, prices[i]);
            left[i] = max(left[i-1], prices[i] - minp);
        }

        int maxp = prices[n-1];
        for(int i=n-2;i>=0;i--)
        {
            maxp = max(maxp, prices[i]);
            right[i] = max(right[i+1], maxp - prices[i]);
        }

        int max_profits =0;
        for(int i=0;i<n;i++)
        {
            max_profits = max(max_profits, left[i]+right[i]);
        }

        return max_profits;
        
    }
};

Approach 1: Bidirectional Dynamic Programming
You may not engage in multiple transactions at the same time, (i.e. you must sell the stock before you buy again).

We could interpret this constraint as that there would be no overlapping in the sequence of transactions.

That being said, we can solve the problem in a divide-and-conquer manner, where we divide the original sequence of prices into two subsequences and then we calculate the maximum profit that we could gain from making a single transaction in each subsequence.

For a sequence of length n, we would have n possible divisions (including no division), each of the elements would be visited once in each division. As a result, the overall time complexity of this naive implementation would be O(N2).


In dynamic programming algorithms, normally we create an array of one or two dimensions to keep the intermediate optimal results. In this problem though, we would use two arrays, with one array keeping the results of sequence from left to right and the other array keeping the results of sequence from right to left. For the sake of name, we could call it bidirectional dynamic programming.

max_profits[i]=left_profits[i]+right_profits[i+1]


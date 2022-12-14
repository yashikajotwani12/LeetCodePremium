You are given two 0-indexed integer arrays nums and multipliers of size n and m respectively, where n >= m.

You begin with a score of 0. You want to perform exactly m operations. On the ith operation (0-indexed) you will:

Choose one integer x from either the start or the end of the array nums.
Add multipliers[i] * x to your score.
Note that multipliers[0] corresponds to the first operation, multipliers[1] to the second operation, and so on.
Remove x from nums.
Return the maximum score after performing m operations.

Input: nums = [1,2,3], multipliers = [3,2,1]
Output: 14
Explanation: An optimal solution is as follows:
- Choose from the end, [1,2,3], adding 3 * 3 = 9 to the score.
- Choose from the end, [1,2], adding 2 * 2 = 4 to the score.
- Choose from the end, [1], adding 1 * 1 = 1 to the score.
The total score is 9 + 4 + 1 = 14.


Input: nums = [-5,-3,-3,-2,7,1], multipliers = [-10,-5,3,4,6]
Output: 102
Explanation: An optimal solution is as follows:
- Choose from the start, [-5,-3,-3,-2,7,1], adding -5 * -10 = 50 to the score.
- Choose from the start, [-3,-3,-2,7,1], adding -3 * -5 = 15 to the score.
- Choose from the start, [-3,-2,7,1], adding -3 * 3 = -9 to the score.
- Choose from the end, [-2,7,1], adding 1 * 4 = 4 to the score.
- Choose from the end, [-2,7], adding 7 * 6 = 42 to the score. 
The total score is 50 + 15 - 9 + 4 + 42 = 102.

dp problem





class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        
    }
};

The logical intuition of why it is not optimal can be deduced from the following two cases:

Greedy is short-sighted. For the global optimum, we pick the local optimum. But picking this Local Optimum may restrict greater positive product afterward.

nums = [-10,1,1000,1,1,100], multipliers = [1,1,1]

If we pick 100 over -10, we would never ever be able to collect 1000. There are only three elements in multipliers, and we can collect 1000 by taking the left integers only. But selecting 100 at the first point restricts it.

Moreover, what if both ends of nums are identical? We don't know which one to favor. One may yield another score, another may yield a very different score.

nums = [2, 1000, -1, 2], multipliers = [1, 1]




class Solution {
public:
    int dp(vector<vector<int>>& memo, vector<int>& nums, vector<int>& multipliers, int op, int left) {
        // For Right Pointer
        int n = int(nums.size());
        if (op == int(multipliers.size())) {
            return 0;
        }

        // If already computed, return
        if (memo[op][left] != INT_MIN) {
            return memo[op][left];
        }

        int l = nums[left] * multipliers[op] + dp(memo, nums, multipliers, op + 1, left + 1);
        int r = nums[(n - 1) - (op - left)] * multipliers[op] + dp(memo, nums, multipliers, op + 1, left);

        return memo[op][left] = max(l, r);
    }

    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        vector memo(multipliers.size() + 1, vector<int>(multipliers.size() + 1, INT_MIN));
        // Zero operation done in the beginning
        return dp(memo, nums, multipliers, 0, 0);
    }
};


class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        // For Right Pointer
        int n = int(nums.size());
        // Number of Operations
        int m = int(multipliers.size());
        vector dp(m + 1, vector<int>(m + 1, 0));
        
        for (int op = m - 1; op >= 0; op--) {
            for (int left = op; left >= 0; left--) {
                dp[op][left] = max(multipliers[op] * nums[left] + dp[op + 1][left + 1],
                                   multipliers[op] * nums[n - 1 - (op - left)] + dp[op + 1][left]);
            }
        }
        
        return dp[0][0];
    }
};

Interview Tip: 
Always spend time on forming and analyzing Dynamic Programming Equation. For Dynamic Programming, forming an equation requires time. Writing code isn't tough in most cases. Moreover, by analyzing the equation, quite a few times, we can solve the problem using less space.
class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        // For Right Pointer
        int n = int(nums.size());
        // Number of Operations
        int m = int(multipliers.size());
        vector<int> dp(m + 1, 0);
        
        for (int op = m - 1; op >= 0; op--) {
            for (int left = 0; left <= op; left++) {
                dp[left] = max(multipliers[op] * nums[left] + dp[left + 1],
                               multipliers[op] * nums[n - 1 - (op - left)] + dp[left]);
            }
        }
        
        return dp[0];
    }
};
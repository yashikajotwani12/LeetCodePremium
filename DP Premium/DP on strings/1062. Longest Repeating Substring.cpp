/* The only difference between this (Medium) and 1044. Longest Duplicate Substring problem (Hard) is the runtime constraint. Here, we can solve it in O(n ^ 2), where the Hard version requires O(n log n) or better.

Here are the approaches we can use here:

DP - Longest Common Substring (LCS) pattern
Brute-Force with Pruning
Trie - (for this problem you may get MLE)
Binary Search and Rabin-Karp (O(n log n) thanks to the rolling hash)
Suffix Array (O(n log n) or even O(n) if you borrow Ukkonen's implementation)
 */
class Solution {
    public:
        int longestRepeatingSubstring(string s)
        {
            int n= s.size();
            vector<vector<int>>(n+1, vector<int>(n+1,0));

            for(int i=1;i<=n;i++)
            {
                for(int j=i; j<=n;j++)
                {
                    if(s[i-1] == s[j-1])
                    {
                        dp[i][j] = 1+ dp[i-1][j-1];
                    }
                    else{
                        dp[i][j] = 0;
                    }
                }
            }
            int ans =0;
            for(int i=1;i<=n;i++)
            {
                for(int j=i;j<=n;j++)
                {
                    ans = max(ans, dp[i][j]);
                }
            }
            return ans;
        }
};
int longestRepeatingSubstring(string S, int m_val = 0) {
	vector<vector<short>> dp(S.size() + 1, vector<short>(S.size() + 1));
	for (int i = 0; i < S.size(); ++i)
		for (int j = 0; j < i; ++j) {
			if (S[i] == S[j]) {
				auto val = dp[i + 1][j + 1] = 1 + dp[i][j];
				if (val > m_val) m_val = val;
			}
		}
	return m_val;
}



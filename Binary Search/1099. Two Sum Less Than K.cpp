Input: nums = [34,23,1,24,75,33,54,8], k = 60
Output: 58
Explanation: We can use 34 and 24 to sum 58 which is less than 60.

class Solution {
    public:
    int twoSumLessThanK(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int i=0, j= nums.size() -1;
        int ans = -1;
        while(i<j)
        {
            if(nums[i] + nums[j] < k)
            {
                ans = max(ans, nums[i] + nums[j]);
                i++;
            }
            else
            {
                j--;
            }
        }
        return ans;
    }
};

// counting sort
class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        int answer = -1;
        int count[1001] = {};
        for (int num : nums) {
            count[num]++;
        }
        int lo = 1;
        int hi = 1000;
        while (lo <= hi) {
            if (lo + hi >= k || count[hi] == 0) {
                hi--;
            } else {
                if (count[lo] > (lo < hi ? 0 : 1)) {
                    answer = max(answer, lo + hi);
                }
                lo++;
            }
        }
        return answer;
    }
};
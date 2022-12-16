Input: nums = [4,7,9,10], k = 1
Output: 5
Explanation: The first missing number is 5.
Given an integer array nums which is sorted in ascending order and all of its elements are unique and given also an integer k, return the kth missing number starting from the leftmost number of the array.


class Solution {
public:
    int missingElement(vector<int>& nums, int k) {

        int left = 0, right = nums.size()-1;
        while(left <= right)
        {
            int mid = left + (right - left)/2;
            if(nums[mid] - nums[0] - mid < k)
            {
                left = mid+1;
            }
            else
            {
                right = mid-1;
            }
        }
        return nums[0] + k + right;
        
    }
};
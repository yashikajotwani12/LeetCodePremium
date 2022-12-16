Input: nums = [2,4,5,5,5,5,5,6,6], target = 5
Output: true
Explanation: The value 5 appears 5 times and the length of the array is 9.
Thus, 5 is a majority element because 5 > 9/2 is true.

class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int n = nums.size();
        int l =0, r= n-1;
        int first = -1, last = -1;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            if(nums[mid] == target)
            {
                first = mid;
                r= mid-1;
            }
            else if(nums[mid] > target)
            {
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }


        }

        l =0, r= n-1;
        while(l<=r)
        {
            int mid = l+ (r-l)/2;
            if(nums[mid] == target)
            {
                last = mid;
                l = mid+1;
            }
            else if(nums[mid] > target)
            {
                r = mid-1;
            }
            else
            {
                l= mid+1;
            }
        }
        
        if(first == -1 or last == -1) return false;
        return (last-first+1) > n/2;
    }
};




bool isMajorityElement(vector<int>& n, int t) {
  return upper_bound(begin(n), end(n), t) - lower_bound(begin(n), end(n), t) > n.size() / 2;
}
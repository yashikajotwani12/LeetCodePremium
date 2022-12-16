Input: ribbons = [9,7,5], k = 3
Output: 5
Explanation:
- Cut the first ribbon to two ribbons, one of length 5 and one of length 4.
- Cut the second ribbon to two ribbons, one of length 5 and one of length 2.
- Keep the third ribbon as it is.
Now you have 3 ribbons of length 5.
class Solution {
public:
    int maxLength(vector<int>& ribbons, int k) {
        int left = 1, right = *max_element(ribbons.begin(), ribbons.end());
        while(left <= right)
        {
            int mid = left + (right - left )/2;
            int count =0;
            for(int ribbon:ribbons)
            {
                count += ribbon/mid;

            }
            if(count >= k)
            {
                left = mid+1;

            }else{
                right = mid-1;
            }
        }
        return right;
        
    }
};
// why we are taking left = 1 and not 0?
// because we are taking the max element of the ribbons array and we are taking the right boundary as max element of the ribbons array. so we can't take 0 as left boundary because we are dividing the ribbons array elements by mid and if we take 0 as left boundary then we will get 0 as the answer which is not possible.

why count += ribbon/mid;


bool isPossible(vector<int> &ribbons, int l, int k)
    {
        int count = 0;
        for (int ribbon : ribbons)
        {
            count += ribbon/l;
            if (count >= k) return true;
        }
        
        return count >= k;
    }
	
    int maxLength(vector<int>& ribbons, int k)
    {
        long long total = 0;
        for (int ribbon : ribbons) total += ribbon;
        
        if (total < k) return 0;
        
        int low = 1, high = total/k, mid = 0, ans = 0;
        
        while (low <= high)
        {
            mid = (low + high)/2;
            if (isPossible(ribbons, mid, k))
            {
                ans = mid;
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
        
        return ans;
    }
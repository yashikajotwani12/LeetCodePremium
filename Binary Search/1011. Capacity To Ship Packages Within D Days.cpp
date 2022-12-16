Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15
Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10

Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.


class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        while(left < right)
        {
            int mid = left + (right - left)/2;
            int need = 1, cur = 0;
            for(int weight : weights)
            {
                if(cur + weight > mid)
                {
                    need++;
                    cur = 0;
                }
                cur += weight;
            }
            if(need <= days)
            {
                right = mid;
            }
            else
            {
                left = mid+1;
            }
        }
        return left;
    }
};
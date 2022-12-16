You have one chocolate bar that consists of some chunks. Each chunk has its own sweetness given by the array sweetness.

You want to share the chocolate with your k friends so you start cutting the chocolate bar into k + 1 pieces using k cuts, each piece consists of some consecutive chunks.

Being generous, you will eat the piece with the minimum total sweetness and give the other pieces to your friends.

Find the maximum total sweetness of the piece you can get by cutting the chocolate bar optimally.

Google
Amazon
Facebook

Input: sweetness = [1,2,3,4,5,6,7,8,9], k = 5
Output: 6
Explanation: You can divide the chocolate to [1,2,3], [4,5], [6], [7], [8], [9]

// min the max sweetness

class Solution {
public:
    int maximizeSweetness(vector<int>& sweetness, int k) {
        int left = 1, right = accumulate(sweetness.begin(), sweetness.end(), 0)/(k+1);
        while(left < right)
        {
            int mid = left + (right - left + 1)/2;
            int cuts = 0, cur = 0;
            for(int sweet : sweetness)
            {
                cur += sweet;
                if(cur >= mid)
                {
                    cuts++;
                    cur = 0;
                }
            }
            if(cuts > k)
            {
                left = mid;
            }
            else
            {
                right = mid-1;
            }
        }
        return left;
    }
};

Here the task is to find the maximum possible minimum sum of all subarrays after dividing the array into k + 1 contiguous subarrays.

In this problem, the left boundary left is the minimum of sweetness, that is left = min(sweetness), since left is the smallest possible sweetness for this piece of chocolate. (There is no piece with sweetness less than left!)

The right boundary right is the total sweetness of the chocolate bar (total) divided by the number of people k + 1 , that is total / (k + 1). It is the largest possible sweetness we can get for ourselves. Note that if the sweetness of the chunk for us is larger than this value, say total / (k + 1) + 1, this will still be the smallest sweetness. Thus, the total sweetness is no less than (total / (k + 1) + 1) * (k + 1) which is strictly larger than total, meaning any value larger than total / (k + 1) is impossible.


herefore, we can assign the lower boundary left = min(sweetness) and the upper boundary right = total / (k + 1). The optimal minimum sweetness must be within this range.

Since we are looking for the maximum possible value, thus the middle value should be mid = (left + right + 1) / 2.


Why do we use mid = (left + right + 1) / 2 here instead of mid = (left + right) / 2?  Because we want to find the maximum possible value, so we need to make sure that the left boundary is always smaller than the right boundary. If we use mid = (left + right) / 2, then the left boundary will be equal to the right boundary when the total number of elements is even, which will cause the infinite loop.

/* // company
// Google
// instacart
// company
// Facebook
This is an interactive problem.

You have a sorted array of unique elements and an unknown size. You do not have an access to the array but you can use the ArrayReader interface to access it. You can call ArrayReader.get(i) that:

returns the value at the ith index (0-indexed) of the secret array (i.e., secret[i]), or
returns 231 - 1 if the i is out of the boundary of the array.
You are also given an integer target.

Return the index k of the hidden array where secret[k] == target or return -1 otherwise.

You must write an algorithm with O(log n) runtime complexity. */

Input: secret = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in secret and its index is 4.

This is the ArrayReader's API interface.
You should not implement it, or speculate about its implementation
  class ArrayReader {
    public:
      int get(int index);
};

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int left =0, right =1;
        while(reader.get(right) < target)
        {
            left = right;
            right *= 2;
        }
        while(left <= right)
        {
            int mid = left + (right - left)/2;
            if(reader.get(mid) == target)
            {
                return mid;
            }
            else if(reader.get(mid) > target)
            {
                right = mid-1;

            }
            else{
                left = mid+1;
            }
        }
        return -1;
        
    }
};

Prerequisites: left and right shifts

To speed up, one could use here bitwise shifts:

Left shift: x << 1. The same as multiplying by 2: x * 2.

Right shift: x >> 1. The same as dividing by 2: x / 2.


Define boundaries:


int left = 0, right = 1;
While target is on the right to the right boundary: reader.get(right) < target:

Set left boundary equal to the right one: left = right.

Extend right boundary: right *= 2. To speed up, use right shift instead of multiplication: right <<= 1.

Now the target is between left and right boundaries.


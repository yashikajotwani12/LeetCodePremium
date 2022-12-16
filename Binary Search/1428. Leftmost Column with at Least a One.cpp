/* 1428. Leftmost Column with at Least a One
Medium

company
Uber
company
Facebook
company
Amazon
A row-sorted binary matrix means that all elements are 0 or 1 and each row of the matrix is sorted in non-decreasing order.

Given a row-sorted binary matrix binaryMatrix, return the index (0-indexed) of the leftmost column with a 1 in it. If such an index does not exist, return -1.

You can't access the Binary Matrix directly. You may only access the matrix using a BinaryMatrix interface:

BinaryMatrix.get(row, col) returns the element of the matrix at index (row, col) (0-indexed).
BinaryMatrix.dimensions() returns the dimensions of the matrix as a list of 2 elements [rows, cols], which means the matrix is rows x cols.
Submissions making more than 1000 calls to BinaryMatrix.get will be judged Wrong Answer. Also, any solutions that attempt to circumvent the judge will result in disqualification.

For custom testing purposes, the input will be the entire binary matrix mat. You will not have access to the binary matrix directly.

Input: mat = [[0,0],[1,1]]
Output: 0
 */

// sorted rows
// binary search 



class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        
        vector<int>dim = binaryMatrix.dimensions();
        int n = dim[0], m = dim[1];
        int ans = INT_MAX;
        for(int i=0;i<n;i++)
        {
            int l = 0, r = m-1;
            while(l<=r)
            {
                int mid = l + (r-l)/2;
                if(binaryMatrix.get(i, mid) == 1)
                {
                    ans = min(ans, mid);
                    r = mid-1;
                }
                else
                {
                    l = mid+1;
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
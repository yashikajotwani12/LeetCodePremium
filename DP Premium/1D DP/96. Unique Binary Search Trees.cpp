class Solution {
public:
    int numTrees(int n) {
        long c =1;
        for(int i=0;i<n;i++)
        {
            c =c*2*(2*i+1)/ (i+2);
        }
        return (int)c;
    }
};
Input: n = 3
Output: 5

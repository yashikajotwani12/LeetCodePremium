Input: arr1 = [1,2,3,4,5], arr2 = [1,2,5,7,9], arr3 = [1,3,4,5,8]
Output: [1,5]
Explanation: Only 1 and 5 appeared in the three arrays.
class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {

        int i=0, j=0, k=0;
        vector<int>ans;

        while(i<arr1.size() and j< arr3.size() and k< arr3.size())
        {
            if(arr1[i] == arr2[j] and arr2[j] == arr3[k])
            {
                ans.push_back(arr1[i]);
                i++,j++,k++;

            }
            else
            {
                int maxm = max({arr1[i], arr2[j], arr3[k]});
                if(arr1[i] < maxm) i++;
                if(arr2[j] < maxm) j++;
                if(arr3[k] < maxm) k++;
            }

        }
        return ans;
        
    }
};
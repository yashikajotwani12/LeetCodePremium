/* We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].

You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.

If you choose a job that ends at time X you will be able to start another job that starts at time X.

Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
Output: 120
Explanation: The subset chosen is the first and fourth job. 
Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.
 */
class Solution {
public:
    int dp[50001];
    int maxp(vector<vector<int>>& jobs, vector<int>& startTime, int n, int position)
    {
        if(position == n) return 0;

        if(dp[position] !=-1) return dp[position];

        int nextIndex = lower_bound(startTime.begin(), startTime.end(), jobs[position][1]) - start.begin();
        int maxprofit = max(maxp(jobs, startTime, n, position + 1), jobs[position][2] + maxp(jobs, startTime, n, nextIndex));


        return dp[position] = maxprofit;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>>jobs;
        memset(dp, -1, sizeof(dp));

        for(int i=0;i<profit.size();i++)
        {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }

        sort(jobs.begin(), jobs.end());

        for(int i=0;i<profit.size();i++)
        {
            startTime[i] = jobs[i][0];
        }

        return maxp(jobs, startTime, profit.size(), 0);
        

    }
};

// Algorithm

// Store the startTime, endTime and profit of each job in jobs.
// Sort the jobs according to their starting time.
// Iterate over jobs from left to right, where position is the index of the current job. For each job, we must compare two options:
// i. Skip the current job (earn 0 profit) and move on to consider the job at the index position + 1.
// ii. Schedule the current job (earn profit for the current job) and move on to the next non-conflicting job whose index is nextIndex. nextIndex is determined by using binary search in the startTime array.
// Return the maximum profit of the two choices and record this profit in the array memo (memoization).

// dp memoization
// dp bottom up
// sorting priority_queue
class Solution {
public:
    int findMaxProfit(vector<vector<int>>& jobs) {
        int n = jobs.size(), maxProfit = 0;
        // min heap having {endTime, profit}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        for (int i = 0; i < n; i++) {
            int start = jobs[i][0], end = jobs[i][1], profit = jobs[i][2];
            
            // keep popping while the heap is not empty and
            // jobs are not conflicting
            // update the value of maxProfit
            while (pq.empty() == 0 && start >= pq.top()[0]) {
                maxProfit = max(maxProfit, pq.top()[1]);
                pq.pop();
            }
            
            // push the job with combined profit
            // if no non-conflicting job is present maxProfit will be 0
            pq.push({end, profit + maxProfit});
        }
        
        // update the value of maxProfit by comparing with
        // profit of jobs that exits in the heap
        while (pq.empty() == 0) {
            maxProfit = max(maxProfit, pq.top()[1]);
            pq.pop();
        }
        
        return maxProfit;
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        
        // storing job's details into one list 
        // this will help in sorting the jobs while maintaining the other parameters
        for (int i = 0; i < profit.size(); i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        
        sort(jobs.begin(), jobs.end());
        return findMaxProfit(jobs);
    }
};
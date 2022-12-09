/* You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1 */


// In this problem, one can see that BFS would be a better fit.

// Because the process of rotting could be explained perfectly with the BFS procedure, i.e. the rotten oranges will contaminate their neighbors first, before the contamination propagates to other fresh oranges that are farther away


// The secret in doing BFS traversal without a queue lies in the technique called in-place algorithm, which transforms input to solve the problem without using auxiliary data structure.

// Actually, we have already had a taste of in-place algorithm in the previous implementation of BFS, where we directly modified the input grid to mark the oranges that turn rotten, rather than using an additional visited table.
/* 
The idea is that at each round of the BFS, we mark the cells to be visited in the input grid with a specific timestamp.

By round, we mean a snapshot in time where a group of oranges turns rotten. */



Time Complexity: {O}(N^2M^2) where N×M is the size of the input grid.


In the in-place BFS traversal, for each round of BFS, we would have to iterate through the entire grid.

The contamination propagates in 4 different directions. If the orange is well adjacent to each other, the chain of propagation would continue until all the oranges turn rotten.

In the worst case, the rotten and the fresh oranges might be arranged in a way that we would have to run the BFS loop over and over again, which could amount to NM2\frac{NM}{2}NM times which is the longest propagation chain that we might have, i.e. the zigzag walk in a 2D grid as shown in the following graph


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<int> dir ={-1, 0, 1, 0, -1};
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>>q;
        int fresh = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 2) q.push({i,j});
                if(grid[i][j] == 1) fresh++;
            }
        }
        int ans =-1;
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                pair<int,int> p = q.front();
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int r = p.first + dir[i];
                    int c = p.second + dir[i+1];
                    if( r >=0 and r<m and c>=0 and c<n and grid[r][c] == 1)
                    {
                        grid[r][c] =2;
                        q.push({r,c});
                        fresh--;
                        
                    }
                }
                
            }
            ans++;
        }
        if(fresh>0) return -1; //if fresh>0 that means there are fresh oranges left
        if(ans==-1) return 0; //we initialised with -1, so if there were no oranges it'd take 0 mins.
        return ans;
    }
};

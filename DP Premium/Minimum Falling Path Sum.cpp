/* Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).


Approach 2: Top Down Dynamic Programming */

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int minFallingSum = INT_MAX;
        vector<vector<optional<int>>> memo(
            matrix.size(), vector<optional<int>>(matrix.size(), nullopt));

        // start a DFS (with memoization) from each cell in the top row
        for (int startCol = 0; startCol < matrix.size(); startCol++) {
            minFallingSum = min(minFallingSum, findMinFallingPathSum(
                                                   matrix, 0, startCol, memo));
        }
        return minFallingSum;
    }

    int findMinFallingPathSum(vector<vector<int>>& matrix, int row, int col,
                              vector<vector<optional<int>>>& memo) {
        // base cases
        if (col < 0 || col == matrix.size()) {
            return INT_MAX;
        }
        // check if we have reached the last row
        if (row == matrix.size() - 1) {
            return matrix[row][col];
        }
        // check if the results are calculated before
        if (memo[row][col] != nullopt) {
            return (memo[row][col]).value_or(0);
        }

        // calculate the minimum falling path sum starting from each possible
        // next step
        int left = findMinFallingPathSum(matrix, row + 1, col - 1, memo);
        int middle = findMinFallingPathSum(matrix, row + 1, col, memo);
        int right = findMinFallingPathSum(matrix, row + 1, col + 1, memo);

        int minSum = min(left, min(middle, right)) + matrix[row][col];

        memo[row][col] = minSum;
        return minSum;
    }
};

Time Complexity: O(N2)O(N^2)O(N 
2
 )

For every cell in the matrix, we will compute the result only once and update the memo. For the subsequent calls, we are using the stored results that take O(1)O(1)O(1) time. There are N2N^2N 
2
  cells in the matrix, and thus N2N^2N 
2
  dp states. So, the time complexity is O(N2)O(N^2)O(N 
2
 ).

Space Complexity: O(N2)O(N^2)O(N 
2
 )

The recursive call stack uses O(N)O(N)O(N) space. As the maximum depth of the tree is NNN, we can’t have more than NNN recursive calls on the call stack at any time. The 2D matrix memo uses O(N2)O(N^2)O(N 
2
 ) space. Thus, the space complexity is O(N)+O(N2)=O(N2)O(N) + O(N^2) = O(N^2).


Approach 3: Bottom-Up Dynamic Programming (Tabulation)

To compute the minimum falling path for a certain cell (row, col), we must have pre-computed values for the minimum falling path for cells (row + 1, col - 1), (row + 1, col) and (row + 1, col + 1). For this, we will iterate from (n−1)th row to 0th row and from 0 th column to (n−1)th column.

dp[row][col] = min(dp[row + 1][col - 1],
                    dp[row + 1][col],
                    dp[row + 1][col + 1]) + value of current (row, col) in matrix


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size() + 1,
                               vector<int>(matrix.size() + 1, 0));
        for (int row = matrix.size() - 1; row >= 0; row--) {
            for (int col = 0; col < matrix.size(); col++) {
                if (col == 0) {
                    dp[row][col] = min(dp[row + 1][col], dp[row + 1][col + 1]) +
                                   matrix[row][col];
                } else if (col == matrix.size() - 1) {
                    dp[row][col] = min(dp[row + 1][col], dp[row + 1][col - 1]) +
                                   matrix[row][col];
                } else {
                    dp[row][col] =
                        min(dp[row + 1][col],
                            min(dp[row + 1][col + 1], dp[row + 1][col - 1])) +
                        matrix[row][col];
                }
            }
        }
        int minFallingSum = INT_MAX;
        for (int startCol = 0; startCol < matrix.size(); startCol++) {
            minFallingSum = min(minFallingSum, dp[0][startCol]);
        }
        return minFallingSum;
    }
};

TC: o n^2 
SC : o n^2


Approach 4: Bottom-Up Dynamic Programming (Tabulation) (Space Optimized)

currentRow[col] = min(dp[col - 1],
                      dp[col],
                      dp[col + 1]) + value of current (row, col) in matrix

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<int> dp(matrix.size() + 1, 0);
        for (int row = matrix.size() - 1; row >= 0; row--) {
            vector<int> currentRow(matrix.size() + 1, 0);
            for (int col = 0; col < matrix.size(); col++) {
                if (col == 0) {
                    currentRow[col] =
                        min(dp[col], dp[col + 1]) + matrix[row][col];
                } else if (col == matrix.size() - 1) {
                    currentRow[col] =
                        min(dp[col], dp[col - 1]) + matrix[row][col];
                } else {
                    currentRow[col] =
                        min(dp[col], min(dp[col + 1], dp[col - 1])) +
                        matrix[row][col];
                }
            }
            dp = currentRow;
        }
        int minFallingSum = INT_MAX;
        for (int startCol = 0; startCol < matrix.size(); startCol++) {
            minFallingSum = min(minFallingSum, dp[startCol]);
        }
        return minFallingSum;
    }
};

Let N be the length of matrix.

Time Complexity: O(N2)
Space Complexity: O(N).

We are using two 1D arrays of size NNN. So, the space complexity is O(N)O(N)O(N).
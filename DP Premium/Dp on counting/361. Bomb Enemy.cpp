/* Given an m x n matrix grid where each cell is either a wall 'W', an enemy 'E' or empty '0', return the maximum enemies you can kill using one bomb. You can only place the bomb in an empty cell.

The bomb kills all the enemies in the same row and column from the planted point until it hits the wall since it is too strong to be destroyed.

Input: grid = [["0","E","0","0"],["E","0","W","E"],["0","E","0","0"]]
Output: 3

Input: grid = [["W","W","W"],["0","0","0"],["E","E","E"]]
Output: 1

Google
 */

brute force
-- placing a bomb on each empty cell to see how many enemies it will kill

Approach 2: Dynamic Programming
Intuition

As one might notice in the above brute-force approach, there are some redundant calculations during the iteration. More specifically, for any row or column that does not have any wall in-between, the number of enemies that we can kill remains the same for any empty on that particular row or column. While in our brute-force approach, we would iterate the same row or column over and over, regardless the situation of the cells.

In order to reduce or even eliminate the redundant calculation, one might recall one of the well-known techniques called Dynamic Programming.
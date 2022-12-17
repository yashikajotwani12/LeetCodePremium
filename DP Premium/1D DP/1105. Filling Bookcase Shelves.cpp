You are given an array books where books[i] = [thicknessi, heighti] indicates the thickness and height of the ith book. You are also given an integer shelfWidth.

We want to place these books in order onto bookcase shelves that have a total width shelfWidth.

We choose some of the books to place on this shelf such that the sum of their thickness is less than or equal to shelfWidth, then build another level of the shelf of the bookcase so that the total height of the bookcase has increased by the maximum height of the books we just put down. We repeat this process until there are no more books to place.

Note that at each step of the above process, the order of the books we place is the same order as the given sequence of books.

For example, if we have an ordered list of 5 books, we might place the first and second book onto the first shelf, the third book on the second shelf, and the fourth and fifth book on the last shelf.
Return the minimum possible height that the total bookshelf can be after placing shelves in this manner.

Input: books = [[1,1],[2,3],[2,3],[1,1],[1,1],[1,1],[1,2]], shelf_width = 4
Output: 6
Explanation:
The sum of the heights of the 3 shelves is 1 + 3 + 2 = 6.
Notice that book number 2 does not have to be on the first shelf.

vector<vector<int>> memo;
int dp(int i,vector<vector<int>>& books,int shelfwidth,int width,int h)
{
    if(i>=books.size())
        return h;
    if(memo[i][width]!=-1)
        return memo[i][width];
    int q=h+dp(i+1,books,shelfwidth,books[i][0],books[i][1]);
    if(width+books[i][0]<=shelfwidth)
        q=min(q,dp(i+1,books,shelfwidth,width+books[i][0],max(h,books[i][1])));
    return memo[i][width]=q;
}
int minHeightShelves(vector<vector<int>>& books, int shelf_width) 
{
    memo.resize(books.size(),vector<int>(shelf_width+1,-1));
    return dp(0,books,shelf_width,0,0);
}
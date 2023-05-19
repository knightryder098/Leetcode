/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 *
 * https://leetcode.com/problems/surrounded-regions/description/
 *
 * algorithms
 * Medium (36.96%)
 * Likes:    7063
 * Dislikes: 1509
 * Total Accepted:    534.2K
 * Total Submissions: 1.4M
 * Testcase Example:  '[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]'
 *
 * Given an m x n matrix board containing 'X' and 'O', capture all regions that
 * are 4-directionally surrounded by 'X'.
 *
 * A region is captured by flipping all 'O's into 'X's in that surrounded
 * region.
 *
 *
 * Example 1:
 *
 *
 * Input: board =
 * [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
 * Output:
 * [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
 * Explanation: Notice that an 'O' should not be flipped if:
 * - It is on the border, or
 * - It is adjacent to an 'O' that should not be flipped.
 * The bottom 'O' is on the border, so it is not flipped.
 * The other three 'O' form a surrounded region, so they are flipped.
 *
 *
 * Example 2:
 *
 *
 * Input: board = [["X"]]
 * Output: [["X"]]
 *
 *
 *
 * Constraints:
 *
 *
 * m == board.length
 * n == board[i].length
 * 1 <= m, n <= 200
 * board[i][j] is 'X' or 'O'.
 *
 *
 */

// @lc code=start
class Solution
{
public:
    void dfs(int i, int j, vector<vector<char>> &board, vector<vector<int>> &visited)
    {   
        if(board[i][j]!='O')return;
        visited[i][j] = 1;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};
        for (int x = 0; x < 4; x++)
        {
            int ni = i + dr[x];
            int nj = j + dc[x];
            if (ni < 0 || ni == board.size() || nj < 0 || nj == board[0].size() || visited[ni][nj]==1)continue;

                if(board[ni][nj]=='O')dfs(ni, nj, board, visited);
            
        }
    }
    void solve(vector<vector<char>> &board)
    {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));

        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0||j==0||i==n-1||j==m-1){
                    if(board[i][j]=='O')dfs(i,j,board,visited);
                }
            }
        }




        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (visited[i][j]==1)
                    board[i][j] = 'O';
                else
                    board[i][j] = 'X';
            }
        }
        
    }
};
// @lc code=end

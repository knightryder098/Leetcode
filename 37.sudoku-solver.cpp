/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 *
 * https://leetcode.com/problems/sudoku-solver/description/
 *
 * algorithms
 * Hard (57.88%)
 * Likes:    7791
 * Dislikes: 208
 * Total Accepted:    455.9K
 * Total Submissions: 787.6K
 * Testcase Example:  '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 *
 * A sudoku solution must satisfy all of the following rules:
 *
 *
 * Each of the digits 1-9 must occur exactly once in each row.
 * Each of the digits 1-9 must occur exactly once in each column.
 * Each of the digits 1-9 must occur exactly once in each of the 9 3x3
 * sub-boxes of the grid.
 *
 *
 * The '.' character indicates empty cells.
 *
 *
 * Example 1:
 *
 *
 * Input: board =
 * [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
 * Output:
 * [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
 * Explanation: The input board is shown above and the only valid solution is
 * shown below:
 *
 *
 *
 *
 *
 * Constraints:
 *
 *
 * board.length == 9
 * board[i].length == 9
 * board[i][j] is a digit or '.'.
 * It is guaranteed that the input board has only one solution.
 *
 *
 */

// @lc code=start
class Solution
{
public:
    bool possible(char val, int i, int j, vector<vector<char>> &board)
    {
        for (int x = 0; x < 9; x++)
        {
            if (board[i][x] == val)
                return false;
            if (board[x][j] == val)
                return false;
        }

        int ni = i - i % 3, nj = j - j % 3;

        for (int xx = 0; xx < 3; xx++)
        {
            for (int yy = 0; yy < 3; yy++)
            {
                if (board[ni + xx][nj + yy] == val)
                    return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<char>> &board, int i, int j)
    {
        if (i == 9)
            return true;
        if (j == 9)
            return solve(board, i + 1, 0);
        if (board[i][j] != '.')
            return solve(board, i, j + 1);
        for (char ch = '1'; ch <= '9'; ch++)
        {
            if (possible(ch, i, j, board))
            {
                board[i][j] = ch;
                if (solve(board, i, j + 1))
                    return true;
                board[i][j] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board, 0, 0);
    }
};
// @lc code=end

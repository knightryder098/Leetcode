/*
 * @lc app=leetcode id=1572 lang=cpp
 *
 * [1572] Matrix Diagonal Sum
 *
 * https://leetcode.com/problems/matrix-diagonal-sum/description/
 *
 * algorithms
 * Easy (80.38%)
 * Likes:    2298
 * Dislikes: 30
 * Total Accepted:    201.4K
 * Total Submissions: 247.3K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a square matrix mat, return the sum of the matrix diagonals.
 *
 * Only include the sum of all the elements on the primary diagonal and all the
 * elements on the secondary diagonal that are not part of the primary
 * diagonal.
 *
 *
 * Example 1:
 *
 *
 * Input: mat = [[1,2,3],
 * [4,5,6],
 * [7,8,9]]
 * Output: 25
 * Explanation: Diagonals sum: 1 + 5 + 9 + 3 + 7 = 25
 * Notice that element mat[1][1] = 5 is counted only once.
 *
 *
 * Example 2:
 *
 *
 * Input: mat = [[1,1,1,1],
 * [1,1,1,1],
 * [1,1,1,1],
 * [1,1,1,1]]
 * Output: 8
 *
 *
 * Example 3:
 *
 *
 * Input: mat = [[5]]
 * Output: 5
 *
 *
 *
 * Constraints:
 *
 *
 * n == mat.length == mat[i].length
 * 1 <= n <= 100
 * 1 <= mat[i][j] <= 100
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int diagonalSum(vector<vector<int>> &mat)
    {
        int a = 0, b = 0;
        int n=mat.size();
        for (int i = 0; i < n; i++)
        {   
            if(i==n-1-i)a+=mat[i][i];
            else a += mat[i][i] + mat[i][n - i - 1];
        }
        return a;
    }
};
// @lc code=end
static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL)

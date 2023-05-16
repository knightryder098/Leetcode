/*
 * @lc app=leetcode id=877 lang=cpp
 *
 * [877] Stone Game
 *
 * https://leetcode.com/problems/stone-game/description/
 *
 * algorithms
 * Medium (69.77%)
 * Likes:    2609
 * Dislikes: 2528
 * Total Accepted:    186.7K
 * Total Submissions: 267.6K
 * Testcase Example:  '[5,3,4,5]'
 *
 * Alice and Bob play a game with piles of stones. There are an even number of
 * piles arranged in a row, and each pile has a positive integer number of
 * stones piles[i].
 *
 * The objective of the game is to end with the most stones. The total number
 * of stones across all the piles is odd, so there are no ties.
 *
 * Alice and Bob take turns, with Alice starting first. Each turn, a player
 * takes the entire pile of stones either from the beginning or from the end of
 * the row. This continues until there are no more piles left, at which point
 * the person with the most stones wins.
 *
 * Assuming Alice and Bob play optimally, return true if Alice wins the game,
 * or false if Bob wins.
 *
 *
 * Example 1:
 *
 *
 * Input: piles = [5,3,4,5]
 * Output: true
 * Explanation:
 * Alice starts first, and can only take the first 5 or the last 5.
 * Say she takes the first 5, so that the row becomes [3, 4, 5].
 * If Bob takes 3, then the board is [4, 5], and Alice takes 5 to win with 10
 * points.
 * If Bob takes the last 5, then the board is [3, 4], and Alice takes 4 to win
 * with 9 points.
 * This demonstrated that taking the first 5 was a winning move for Alice, so
 * we return true.
 *
 *
 * Example 2:
 *
 *
 * Input: piles = [3,7,2,3]
 * Output: true
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= piles.length <= 500
 * piles.length is even.
 * 1 <= piles[i] <= 500
 * sum(piles[i]) is odd.
 *
 *
 */

// @lc code=start

class Solution
{
public:
    bool helper(vector<int> &piles, int i, int j, int alice, int bob, bool flag, vector<vector<vector<int>>> &dp)
    {
        if (i == j)
        {
            return true;
        }

        if (dp[i][j][flag] != -1)
            return dp[i][j][flag];

        if (flag == 1)
        {
            // alice
            return dp[i][j][flag] = helper(piles, i + 1, j, alice + piles[i], bob, 0,dp) || helper(piles, i, j - 1, alice + piles[j], bob, 0,dp);
        }
        else
        {
            return dp[i][j][flag] = helper(piles, i + 1, j, alice, bob + piles[i], 1,dp) || helper(piles, i, j - 1, alice, bob + piles[j], 1,dp);
        }
    }
    bool stoneGame(vector<int> &piles)
    {
        // int n = piles.size();
        // int alice = 0, bob = 0;
        // vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(2, -1)));
        // return helper(piles, 0, n - 1, alice, bob, 0, dp);
        return true;
    }
};
// @lc code=end

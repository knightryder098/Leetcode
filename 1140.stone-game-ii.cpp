/*
 * @lc app=leetcode id=1140 lang=cpp
 *
 * [1140] Stone Game II
 *
 * https://leetcode.com/problems/stone-game-ii/description/
 *
 * algorithms
 * Medium (64.60%)
 * Likes:    1894
 * Dislikes: 383
 * Total Accepted:    54.1K
 * Total Submissions: 81.8K
 * Testcase Example:  '[2,7,9,4,4]'
 *
 * Alice and Bob continue their games with piles of stones.  There are a number
 * of piles arranged in a row, and each pile has a positive integer number of
 * stones piles[i].  The objective of the game is to end with the most
 * stones. 
 * 
 * Alice and Bob take turns, with Alice starting first.  Initially, M = 1.
 * 
 * On each player's turn, that player can take all the stones in the first X
 * remaining piles, where 1 <= X <= 2M.  Then, we set M = max(M, X).
 * 
 * The game continues until all the stones have been taken.
 * 
 * Assuming Alice and Bob play optimally, return the maximum number of stones
 * Alice can get.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: piles = [2,7,9,4,4]
 * Output: 10
 * Explanation:  If Alice takes one pile at the beginning, Bob takes two piles,
 * then Alice takes 2 piles again. Alice can get 2 + 4 + 4 = 10 piles in total.
 * If Alice takes two piles at the beginning, then Bob can take all three piles
 * left. In this case, Alice get 2 + 7 = 9 piles in total. So we return 10
 * since it's larger. 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: piles = [1,2,3,4,5,100]
 * Output: 104
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= piles.length <= 100
 * 1 <= piles[i] <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int helper(int p,int i,int m,vector<int>&piles,vector<vector<vector<int>>>&dp){
        int n=piles.size();
        if(i==n)return 0;
        if(dp[i][m][p]!=-1)return dp[i][m][p];
        int res = p == 1 ? 1000000 : -1, s = 0;
            for (int x = 1; x <= min(2 * m, n - i); x++) {
                s += piles[i + x - 1];
                if (p == 0) {
                    res = max(res, s + helper(1, i + x, max(m, x),piles,dp));
                }
                else {
                    res = min(res, helper(0, i + x, max(m, x),piles,dp));
                }
            }
            return dp[i][m][p]=res;
    }
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(n+1,vector<int>(2,-1)));
        return helper(0,0,1,piles,dp);
    }
};
// @lc code=end


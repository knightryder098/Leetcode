/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 *
 * https://leetcode.com/problems/word-break-ii/description/
 *
 * algorithms
 * Hard (45.39%)
 * Likes:    6035
 * Dislikes: 503
 * Total Accepted:    513.9K
 * Total Submissions: 1.1M
 * Testcase Example:  '"catsanddog"\n["cat","cats","and","sand","dog"]'
 *
 * Given a string s and a dictionary of strings wordDict, add spaces in s to
 * construct a sentence where each word is a valid dictionary word. Return all
 * such possible sentences in any order.
 *
 * Note that the same word in the dictionary may be reused multiple times in
 * the segmentation.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
 * Output: ["cats and dog","cat sand dog"]
 *
 *
 * Example 2:
 *
 *
 * Input: s = "pineapplepenapple", wordDict =
 * ["apple","pen","applepen","pine","pineapple"]
 * Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
 * Explanation: Note that you are allowed to reuse a dictionary word.
 *
 *
 * Example 3:
 *
 *
 * Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
 * Output: []
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 20
 * 1 <= wordDict.length <= 1000
 * 1 <= wordDict[i].length <= 10
 * s and wordDict[i] consist of only lowercase English letters.
 * All the strings of wordDict are unique.
 * Input is generated in a way that the length of the answer doesn't exceed
 * 10^5.
 *
 *
 */

// @lc code=start
class Solution
{
public:
    void helper(string curr, int i, string s, map<string, bool> &lola, vector<string> &ans)
    {
        if (i == s.length())
        {
            curr.pop_back();
            ans.push_back(curr);
            return;
        }

        string word="";
        for(int x=i;x<s.length();x++){
            word+=s[x];
            if(lola[word]){
                helper(curr+word+" ", x+1, s, lola, ans);
            }
        }
        
    }
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        map<string, bool> lola;
        for (auto x : wordDict)
            lola[x] = true;
        vector<string> ans;
        helper("", 0, s, lola, ans);
        return ans;
    }
};
// @lc code=end

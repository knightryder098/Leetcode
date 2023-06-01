/*
 * @lc app=leetcode id=763 lang=cpp
 *
 * [763] Partition Labels
 *
 * https://leetcode.com/problems/partition-labels/description/
 *
 * algorithms
 * Medium (79.73%)
 * Likes:    9500
 * Dislikes: 350
 * Total Accepted:    468.1K
 * Total Submissions: 587K
 * Testcase Example:  '"ababcbacadefegdehijhklij"'
 *
 * You are given a string s. We want to partition the string into as many parts
 * as possible so that each letter appears in at most one part.
 *
 * Note that the partition is done so that after concatenating all the parts in
 * order, the resultant string should be s.
 *
 * Return a list of integers representing the size of these parts.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "ababcbacadefegdehijhklij"
 * Output: [9,7,8]
 * Explanation:
 * The partition is "ababcbaca", "defegde", "hijhklij".
 * This is a partition so that each letter appears in at most one part.
 * A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it
 * splits s into less parts.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "eccbbbbdec"
 * Output: [10]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 500
 * s consists of lowercase English letters.
 *
 *
 */

// @lc code=start
class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        vector<pair<int, int>> lola(26, {1e9, -1e9});
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            int xx = s[i] - 'a';
            lola[xx].first = min(lola[xx].first, i);
            lola[xx].second = max(lola[xx].second, i);
        }

        vector<pair<int, int>> tmp;
        for (int i = 0; i < 26; i++)
        {
            if (lola[i].first != 1e9 and lola[i].second != -1e9)
                tmp.push_back(lola[i]);
        }
        sort(begin(tmp), end(tmp));
        vector<int> ans;
        int start = tmp[0].first;
        int end = tmp[0].second;
        for (int i = 1; i < tmp.size(); i++)
        {
            if (tmp[i].first <= end)
            {
                start = min(start, tmp[i].first);
                end = max(end, tmp[i].second);
            }
            else
            {
                ans.push_back(end - start + 1);
                start = tmp[i].first;
                end = tmp[i].second;
            }
        }
        ans.push_back(end - start + 1);
        return ans;
    }
};
// @lc code=end

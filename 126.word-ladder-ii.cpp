/*
 * @lc app=leetcode id=126 lang=cpp
 *
 * [126] Word Ladder II
 *
 * https://leetcode.com/problems/word-ladder-ii/description/
 *
 * algorithms
 * Hard (27.48%)
 * Likes:    5267
 * Dislikes: 671
 * Total Accepted:    341.2K
 * Total Submissions: 1.2M
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * A transformation sequence from word beginWord to word endWord using a
 * dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... ->
 * sk such that:
 *
 *
 * Every adjacent pair of words differs by a single letter.
 * Every si for 1 <= i <= k is in wordList. Note that beginWord does not need
 * to be in wordList.
 * sk == endWord
 *
 *
 * Given two words, beginWord and endWord, and a dictionary wordList, return
 * all the shortest transformation sequences from beginWord to endWord, or an
 * empty list if no such sequence exists. Each sequence should be returned as a
 * list of the words [beginWord, s1, s2, ..., sk].
 *
 *
 * Example 1:
 *
 *
 * Input: beginWord = "hit", endWord = "cog", wordList =
 * ["hot","dot","dog","lot","log","cog"]
 * Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
 * Explanation: There are 2 shortest transformation sequences:
 * "hit" -> "hot" -> "dot" -> "dog" -> "cog"
 * "hit" -> "hot" -> "lot" -> "log" -> "cog"
 *
 *
 * Example 2:
 *
 *
 * Input: beginWord = "hit", endWord = "cog", wordList =
 * ["hot","dot","dog","lot","log"]
 * Output: []
 * Explanation: The endWord "cog" is not in wordList, therefore there is no
 * valid transformation sequence.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= beginWord.length <= 5
 * endWord.length == beginWord.length
 * 1 <= wordList.length <= 500
 * wordList[i].length == beginWord.length
 * beginWord, endWord, and wordList[i] consist of lowercase English
 * letters.
 * beginWord != endWord
 * All the words in wordList are unique.
 * The sum of all shortest transformation sequences does not exceed 10^5.
 *
 *
 */

// @lc code=start
class Solution
{
public:
    void makepath(vector<string>&curr,string endWord,unordered_map<string,set<string>>&graph,vector<vector<string>>&ans,int len,unordered_set<string>&visited){
        if(curr.size()==len and curr.back()==endWord){
            ans.push_back(curr);
        }

        for(auto word:graph[curr.back()]){
            if(visited.find(word)==visited.end()){
                curr.push_back(word);
                visited.insert(word);
                makepath(curr,endWord,graph,ans,len,visited);
                curr.pop_back();
                visited.erase(word);
            }
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {

        unordered_map<string, set<string>> graph;
        queue<string> q;
        unordered_set<string> dict(begin(wordList), end(wordList));
        q.push(beginWord);
        unordered_set<string> visited;
        visited.insert(beginWord);
        int len=0,step=1;

        bool flag=true;
        while (!q.empty())
        {   
            int sz=q.size();
            for(int xx=0;xx<sz;xx++){

          
            string curr = q.front();
            q.pop();

            if(curr==endWord and flag){
                len=step;
                flag=false;
            }

            // try changing each charracter of curr and check ifits
            // present in dict , add it to queue

            for (int i = 0; i < curr.size(); i++)
            {
                string tmp = curr;
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    tmp[i] = ch;
                    if (dict.find(tmp) != dict.end())
                    {
                        visited.insert(tmp);
                        graph[curr].insert(tmp);
                        q.push(tmp);
                    }
                }
            }

            }
            // after visiting all matching string for curr
            // remove it from dict
            for (auto x : visited)
            {
                dict.erase(x);
            }
            visited.clear();
            step++;
        }

        vector<vector<string>>ans;
        visited.clear();
        vector<string>curr;
        curr.push_back(beginWord);
        visited.insert(beginWord);
        makepath(curr,endWord,graph,ans,len,visited);
        // cout<<len;
        return ans;
    }
};
// @lc code=end

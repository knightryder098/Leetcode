/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 *
 * https://leetcode.com/problems/word-ladder/description/
 *
 * algorithms
 * Hard (37.28%)
 * Likes:    10348
 * Dislikes: 1792
 * Total Accepted:    910.2K
 * Total Submissions: 2.4M
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
 * the number of words in the shortest transformation sequence from beginWord
 * to endWord, or 0 if no such sequence exists.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: beginWord = "hit", endWord = "cog", wordList =
 * ["hot","dot","dog","lot","log","cog"]
 * Output: 5
 * Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot"
 * -> "dog" -> cog", which is 5 words long.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: beginWord = "hit", endWord = "cog", wordList =
 * ["hot","dot","dog","lot","log"]
 * Output: 0
 * Explanation: The endWord "cog" is not in wordList, therefore there is no
 * valid transformation sequence.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= beginWord.length <= 10
 * endWord.length == beginWord.length
 * 1 <= wordList.length <= 5000
 * wordList[i].length == beginWord.length
 * beginWord, endWord, and wordList[i] consist of lowercase English
 * letters.
 * beginWord != endWord
 * All the words in wordList are unique.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>lola;
        lola.push({beginWord,1});
        unordered_set<string>dict(begin(wordList),end(wordList));
        dict.erase(beginWord);
        while(!lola.empty()){
            string word=lola.front().first;
            int steps=lola.front().second;
            lola.pop();
            if(word==endWord)return steps;
            for(int i=0;i<word.length();i++){
                char origin=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(dict.find(word)!=dict.end()){
                        dict.erase(word);
                        lola.push({word,steps+1});
                    }
                }
                word[i]=origin;
            }
        }
        return 0;
    }
};
// @lc code=end


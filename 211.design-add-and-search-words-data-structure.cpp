/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Design Add and Search Words Data Structure
 *
 * https://leetcode.com/problems/design-add-and-search-words-data-structure/description/
 *
 * algorithms
 * Medium (44.03%)
 * Likes:    6896
 * Dislikes: 388
 * Total Accepted:    529.2K
 * Total Submissions: 1.2M
 * Testcase Example:  '["WordDictionary","addWord","addWord","addWord","search","search","search","search"]\n' +
  '[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]'
 *
 * Design a data structure that supports adding new words and finding if a
 * string matches any previously added string.
 *
 * Implement the WordDictionary class:
 *
 *
 * WordDictionary() Initializes the object.
 * void addWord(word) Adds word to the data structure, it can be matched
 * later.
 * bool search(word) Returns true if there is any string in the data structure
 * that matches word or false otherwise. word may contain dots '.' where dots
 * can be matched with any letter.
 *
 *
 *
 * Example:
 *
 *
 * Input
 *
 * ["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
 * [[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
 * Output
 * [null,null,null,null,false,true,true,true]
 *
 * Explanation
 * WordDictionary wordDictionary = new WordDictionary();
 * wordDictionary.addWord("bad");
 * wordDictionary.addWord("dad");
 * wordDictionary.addWord("mad");
 * wordDictionary.search("pad"); // return False
 * wordDictionary.search("bad"); // return True
 * wordDictionary.search(".ad"); // return True
 * wordDictionary.search("b.."); // return True
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= word.length <= 25
 * word in addWord consists of lowercase English letters.
 * word in search consist of '.' or lowercase English letters.
 * There will be at most 2 dots in word for search queries.
 * At most 10^4 calls will be made to addWord and search.
 *
 *
 */

// @lc code=start
class WordDictionary
{
public:
    struct Node
    {
    private:
        Node *child[26];
        bool flag = false;

    public:
        bool contains(char &ch) { return child[ch - 'a'] != NULL; }
        void putNode(char &ch, Node *newNode){child[ch - 'a'] = newNode;}
        Node *getNext(char &ch) { return child[ch - 'a']; }
        void setflag() { flag = true; }
        bool getflag() { return flag; }
    } *root;
    WordDictionary()
    {
        root = new Node();
    }

    void addWord(string word)
    {
        Node *tmp = root;
        for (auto &ch : word)
        {
            if (!tmp->contains(ch))
            {
                tmp->putNode(ch, new Node());
            }
            tmp = tmp->getNext(ch);
        }
        tmp->setflag();
    }

    bool search(string word)
    {
        Node *tmp = root;
        return searchHelper(word, 0, tmp);
    }

    bool searchHelper(string &word, int i, Node *curr)
    {
        if (i == word.length())
            return curr->getflag();
        char ch = word[i];
        if (ch != '.')
        {
            if (!curr->contains(ch))
                return false;
            return searchHelper(word, i + 1, curr->getNext(ch));
        }
        else
        {
            // try out all possible chacaters
            Node *tmp = curr;
            for (int j = 0; j < 26; j++)
            {
                char xx = j + 'a';
                curr = tmp->getNext(xx);
                if (curr and searchHelper(word, i + 1, curr))
                    return true;
            }
            return false;
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

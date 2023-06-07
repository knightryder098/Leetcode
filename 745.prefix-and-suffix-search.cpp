/*
 * @lc app=leetcode id=745 lang=cpp
 *
 * [745] Prefix and Suffix Search
 *
 * https://leetcode.com/problems/prefix-and-suffix-search/description/
 *
 * algorithms
 * Hard (41.20%)
 * Likes:    2168
 * Dislikes: 466
 * Total Accepted:    90.2K
 * Total Submissions: 219.1K
 * Testcase Example:  '["WordFilter","f"]\n[[["apple"]],["a","e"]]'
 *
 * Design a special dictionary that searches the words in it by a prefix and a
 * suffix.
 * 
 * Implement the WordFilter class:
 * 
 * 
 * WordFilter(string[] words) Initializes the object with the words in the
 * dictionary.
 * f(string pref, string suff) Returns the index of the word in the dictionary,
 * which has the prefix pref and the suffix suff. If there is more than one
 * valid index, return the largest of them. If there is no such word in the
 * dictionary, return -1.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input
 * ["WordFilter", "f"]
 * [[["apple"]], ["a", "e"]]
 * Output
 * [null, 0]
 * Explanation
 * WordFilter wordFilter = new WordFilter(["apple"]);
 * wordFilter.f("a", "e"); // return 0, because the word at index 0 has prefix
 * = "a" and suffix = "e".
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= words.length <= 10^4
 * 1 <= words[i].length <= 7
 * 1 <= pref.length, suff.length <= 7
 * words[i], pref and suff consist of lowercase English letters only.
 * At most 10^4 calls will be made to the function f.
 * 
 * 
 */

// @lc code=start

class Trie{
    public:
        struct Node{
            private:
                Node *child[27];
                int endidx;
            public:
                bool contains(char &ch){
                    return child[ch-'a']!=NULL;
                }
                void putnode(char &ch,Node *newNode){
                    child[ch-'a']=newNode;
                }
                Node *getNext(char &ch){
                    return child[ch-'a'];
                }
                void setIdx(int i){
                    endidx=i;
                }
                int getIdx(){
                    return endidx;
                }
        }*root;
        
        Trie(){
            root=new Node();
        }

        void insert(string &word, int i){
            Node *tmp=root;
            for(auto &ch:word){
                if(!tmp->contains(ch)){
                    tmp->putnode(ch,new Node());
                }
                tmp=tmp->getNext(ch);
                tmp->setIdx(i);
            }
        }

        int startwith(string &word){
            Node *tmp=root;
            for(auto &ch:word){
                if(!tmp->contains(ch)){
                    return -1;
                }
                tmp=tmp->getNext(ch);
            }
            return tmp->getIdx();
        }
};



class WordFilter {
    Trie trie;
public:

    WordFilter(vector<string>& words) {
        int len=words.size();
        for(int i=0;i<len;i++){
            string str=words[i];
            int n=str.length();
            for(int j=0;j<=n;j++){
                string currWord=str.substr(j)+'{'+str;
                trie.insert(currWord,i);
            }
        }
    }
    
    int f(string pref, string suff) {
        string word=suff+'{'+pref;
        return trie.startwith(word);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */
// @lc code=end


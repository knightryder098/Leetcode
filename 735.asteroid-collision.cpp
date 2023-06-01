/*
 * @lc app=leetcode id=735 lang=cpp
 *
 * [735] Asteroid Collision
 *
 * https://leetcode.com/problems/asteroid-collision/description/
 *
 * algorithms
 * Medium (44.47%)
 * Likes:    5085
 * Dislikes: 475
 * Total Accepted:    275.6K
 * Total Submissions: 620.3K
 * Testcase Example:  '[5,10,-5]'
 *
 * We are given an array asteroids of integers representing asteroids in a
 * row.
 * 
 * For each asteroid, the absolute value represents its size, and the sign
 * represents its direction (positive meaning right, negative meaning left).
 * Each asteroid moves at the same speed.
 * 
 * Find out the state of the asteroids after all collisions. If two asteroids
 * meet, the smaller one will explode. If both are the same size, both will
 * explode. Two asteroids moving in the same direction will never meet.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: asteroids = [5,10,-5]
 * Output: [5,10]
 * Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never
 * collide.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: asteroids = [8,-8]
 * Output: []
 * Explanation: The 8 and -8 collide exploding each other.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: asteroids = [10,2,-5]
 * Output: [10]
 * Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide
 * resulting in 10.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= asteroids.length <= 10^4
 * -1000 <= asteroids[i] <= 1000
 * asteroids[i] != 0
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>ans;
       stack<int>lola;
       for(auto x:asteroids){
        if(x>0 ||lola.empty())lola.push(x);
        else{
            while(!lola.empty() and lola.top()>0 and lola.top()<abs(x)){
                lola.pop();
            }
            if(!lola.empty() and lola.top()==abs(x))lola.pop();
            else{
                if(lola.empty()||lola.top()<0)lola.push(x);
            }
        }
       }
       while(lola.size()){
        ans.push_back(lola.top());
        lola.pop();
       }
       reverse(begin(ans),end(ans));
       return ans;
    }
};
// @lc code=end


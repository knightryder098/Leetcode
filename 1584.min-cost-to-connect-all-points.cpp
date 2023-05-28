/*
 * @lc app=leetcode id=1584 lang=cpp
 *
 * [1584] Min Cost to Connect All Points
 *
 * https://leetcode.com/problems/min-cost-to-connect-all-points/description/
 *
 * algorithms
 * Medium (64.06%)
 * Likes:    3623
 * Dislikes: 84
 * Total Accepted:    161.2K
 * Total Submissions: 251.7K
 * Testcase Example:  '[[0,0],[2,2],[3,10],[5,2],[7,0]]'
 *
 * You are given an array points representing integer coordinates of some
 * points on a 2D-plane, where points[i] = [xi, yi].
 * 
 * The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan
 * distance between them: |xi - xj| + |yi - yj|, where |val| denotes the
 * absolute value of val.
 * 
 * Return the minimum cost to make all points connected. All points are
 * connected if there is exactly one simple path between any two points.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
 * Output: 20
 * Explanation: 
 * 
 * We can connect the points as shown above to get the minimum cost of 20.
 * Notice that there is a unique path between every pair of points.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: points = [[3,12],[-2,5],[-4,1]]
 * Output: 18
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= points.length <= 1000
 * -10^6 <= xi, yi <= 10^6
 * All pairs (xi, yi) are distinct.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
       map<pair<int,int>,vector<pair<pair<int,int>,int>>>graph;
        for(int i=0;i<points.size();i++){
            int pi=points[i][0],pj=points[i][1];
            for(int j=i+1;j<points.size();j++){
                int chi=points[j][0],chj=points[j][1];

                int len=abs(pi-chi)+abs(pj-chj);
                graph[{pi,pj}].push_back({{chi,chj},len});
                graph[{chi,chj}].push_back({{pi,pj},len});
            }
        }

        int ans=0;
        priority_queue<pair<int,pair<int,int>>>pq;
        pq.push({0,{points[0][0],points[0][1]}});
        map<pair<int,int>,bool>visited;
        while(!pq.empty()){
            auto it=pq.top();pq.pop();
            int len=-1*it.first;
            pair<int,int>parent=it.second;

            if(visited[parent]==false){
                visited[parent]=true;
                ans+=len;
                for(auto child:graph[parent]){
                    pq.push({-child.second,child.first});
                }
            }
        }
        return ans;
    }
};
// @lc code=end


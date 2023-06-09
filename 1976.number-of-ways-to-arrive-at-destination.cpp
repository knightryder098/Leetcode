/*
 * @lc app=leetcode id=1976 lang=cpp
 *
 * [1976] Number of Ways to Arrive at Destination
 *
 * https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/
 *
 * algorithms
 * Medium (30.51%)
 * Likes:    1958
 * Dislikes: 71
 * Total Accepted:    31.7K
 * Total Submissions: 104.1K
 * Testcase Example:  '7\n' +
  '[[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]'
 *
 * You are in a city that consists of n intersections numbered from 0 to n - 1
 * with bi-directional roads between some intersections. The inputs are
 * generated such that you can reach any intersection from any other
 * intersection and that there is at most one road between any two
 * intersections.
 *
 * You are given an integer n and a 2D integer array roads where roads[i] =
 * [ui, vi, timei] means that there is a road between intersections ui and vi
 * that takes timei minutes to travel. You want to know in how many ways you
 * can travel from intersection 0 to intersection n - 1 in the shortest amount
 * of time.
 *
 * Return the number of ways you can arrive at your destination in the shortest
 * amount of time. Since the answer may be large, return it modulo 10^9 + 7.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 7, roads =
 * [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]
 * Output: 4
 * Explanation: The shortest amount of time it takes to go from intersection 0
 * to intersection 6 is 7 minutes.
 * The four ways to get there in 7 minutes are:
 * - 0 ➝ 6
 * - 0 ➝ 4 ➝ 6
 * - 0 ➝ 1 ➝ 2 ➝ 5 ➝ 6
 * - 0 ➝ 1 ➝ 3 ➝ 5 ➝ 6
 *
 *
 * Example 2:
 *
 *
 * Input: n = 2, roads = [[1,0,10]]
 * Output: 1
 * Explanation: There is only one way to go from intersection 0 to intersection
 * 1, and it takes 10 minutes.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 200
 * n - 1 <= roads.length <= n * (n - 1) / 2
 * roads[i].length == 3
 * 0 <= ui, vi <= n - 1
 * 1 <= timei <= 10^9
 * ui != vi
 * There is at most one road connecting any two intersections.
 * You can reach any intersection from any other intersection.
 *
 *
 */

// @lc code=start

#define ll long long int
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = 1e9 + 7;
        vector<vector<pair<int, int>>> graph(n, vector<pair<int, int>>());
        for (auto x : roads)
        {
            graph[x[0]].push_back({x[1], x[2]});
            graph[x[1]].push_back({x[0], x[2]});
        }

        vector<ll> dist(n, 1e12), ways(n, 0);
        ways[0] = 1;
        dist[0] = 0;
        priority_queue<pair<ll, int>> q;
        q.push({0, 0});
        while (!q.empty())
        {
            auto it = q.top();
            q.pop();
            ll distance = -1*(ll)(it.first);
            int node = it.second;

            for (auto x : graph[node])
            {
                int v = x.first;
                ll cost = x.second;

                ll newDis = distance + cost;
                if (newDis < dist[v])
                {
                    dist[v] = newDis;
                    q.push({-newDis, v});
                    ways[v] = ways[node];
                }
                else if (newDis == dist[v])
                {
                    ways[v]=(ways[v]+ ways[node])%mod;
                }
            }
        }
        return ways[n - 1]%mod;
    }
};
// @lc code=end

/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 *
 * https://leetcode.com/problems/flood-fill/description/
 *
 * algorithms
 * Easy (62.30%)
 * Likes:    7159
 * Dislikes: 708
 * Total Accepted:    720.8K
 * Total Submissions: 1.2M
 * Testcase Example:  '[[1,1,1],[1,1,0],[1,0,1]]\n1\n1\n2'
 *
 * An image is represented by an m x n integer grid image where image[i][j]
 * represents the pixel value of the image.
 *
 * You are also given three integers sr, sc, and color. You should perform a
 * flood fill on the image starting from the pixel image[sr][sc].
 *
 * To perform a flood fill, consider the starting pixel, plus any pixels
 * connected 4-directionally to the starting pixel of the same color as the
 * starting pixel, plus any pixels connected 4-directionally to those pixels
 * (also with the same color), and so on. Replace the color of all of the
 * aforementioned pixels with color.
 *
 * Return the modified image after performing the flood fill.
 *
 *
 * Example 1:
 *
 *
 * Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
 * Output: [[2,2,2],[2,2,0],[2,0,1]]
 * Explanation: From the center of the image with position (sr, sc) = (1, 1)
 * (i.e., the red pixel), all pixels connected by a path of the same color as
 * the starting pixel (i.e., the blue pixels) are colored with the new color.
 * Note the bottom corner is not colored 2, because it is not 4-directionally
 * connected to the starting pixel.
 *
 *
 * Example 2:
 *
 *
 * Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0
 * Output: [[0,0,0],[0,0,0]]
 * Explanation: The starting pixel is already colored 0, so no changes are made
 * to the image.
 *
 *
 *
 * Constraints:
 *
 *
 * m == image.length
 * n == image[i].length
 * 1 <= m, n <= 50
 * 0 <= image[i][j], color < 2^16
 * 0 <= sr < m
 * 0 <= sc < n
 *
 *
 */

// @lc code=start
class Solution
{
public:
    void dfs(vector<vector<int>> &image, int i, int j,int currcol, int newcol)
    {
        image[i][j] = newcol;
        vector<int> dr = {0, -1, 0, 1};
        vector<int> dc = {-1, 0, 1, 0};
        for (int x = 0; x < 4; x++)
        {
            int ni = i + dr[x];
            int nj = j + dc[x];
            if (ni < 0 || ni == image.size() || nj < 0 || nj == image[0].size() || image[ni][nj] == newcol||currcol!=image[ni][nj])
                continue;

            dfs(image, ni, nj,currcol, newcol);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        // dfs(image, sr, sc,image[sr][sc], color);
        queue<pair<int,int>>lola;
        int currcol=image[sr][sc];
        lola.push({sr,sc});
        while(!lola.empty()){
            int i=lola.front().first;
            int j=lola.front().second;
            lola.pop();
            image[i][j]=color;
            vector<int> dr = {0, -1, 0, 1};
            vector<int> dc = {-1, 0, 1, 0};

            for(int x=0;x<4;x++){
                int ni=i+dr[x];
                int nj=j+dc[x];
                if(ni<0||ni==image.size()||nj<0||nj==image[0].size()||image[ni][nj]==color||currcol!=image[ni][nj])
                    continue;
                lola.push({ni,nj});
            }

        }
        return image;
    }
};
// @lc code=end

/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(begin(nums),end(nums));
        int n=nums.size();
        int sum=nums[0]+nums[1]+nums[2];
        for(int i=0;i<n-2;i++){
            int j=i+1,k=n-1;
            while(j<k){
                int tmp=nums[i]+nums[j]+nums[k];
                if(abs(target-tmp)<abs(target-sum))sum=tmp;
                if(tmp>target)k--;
                else if(tmp<target)j++;
                else 
                return target;
            }
        }
        return sum;
    }
};
// @lc code=end


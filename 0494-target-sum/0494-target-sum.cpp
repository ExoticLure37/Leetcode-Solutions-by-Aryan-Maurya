class Solution {
public:
    int n;
    unordered_map<string,int> dp;
    int solve(int idx,vector<int> &nums,int target,int tmp){
        if(idx==n)  return tmp==target;

        string key=to_string(idx)+"#"+to_string(tmp);
        if(dp.find(key)!=dp.end())  return dp[key];

        int a=solve(idx+1,nums,target,tmp+nums[idx]);
        int b=solve(idx+1,nums,target,tmp-nums[idx]);

        return dp[key]=a+b;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        n=nums.size();

        int res=solve(0,nums,target,0);
        return res;
    }
};
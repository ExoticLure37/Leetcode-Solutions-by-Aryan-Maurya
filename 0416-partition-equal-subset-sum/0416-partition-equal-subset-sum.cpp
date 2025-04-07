class Solution {
public:
    int k;
    int dp[201][10001];
    bool solve(int idx,vector<int> &nums,int sum){
        if(idx>nums.size() || sum>k)    return false;

        if(idx==nums.size())    return sum==k;

        if(dp[idx][sum]!=-1)    return dp[idx][sum];

        bool include=solve(idx+1,nums,sum+nums[idx]);
        bool exclude=solve(idx+1,nums,sum);

        return dp[idx][sum]=include|exclude;
    }

    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);

        if(sum&1)   return false;
        k=sum/2;

        memset(dp,-1,sizeof(dp));

        bool res=solve(0,nums,0);
        return res;
    }
};
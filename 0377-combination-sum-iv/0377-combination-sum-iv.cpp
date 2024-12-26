class Solution {
public:
    // int dp[201][1001];
    // int solve(vector<int> &nums,int idx,int target){
    //     if(target==0)    return target==0;
    //     if(target<0 || idx>=nums.size())    return 0;
    //     if(dp[idx][target]!=-1) return dp[idx][target];
    //     long long take=solve(nums,idx,target-nums[idx]);
    //     // long long take2=solve(nums,idx+1,target-nums[idx]);
    //     long long notake=solve(nums,idx+1,target);
    //     return dp[idx][target]=(take+notake);
    // }
    int combinationSum4(vector<int>& nums, int target) {
        // memset(dp,-1,sizeof(dp));
        long long mod=1e18+7;
        sort(nums.begin(),nums.end());
        vector<long long >dp(target+1,0);
        dp[0]=1;
        for(int curr=1;curr<=target;curr++){
            for(int i=0;i<nums.size();i++){
                if(curr-nums[i]>=0){
                    dp[curr]+=dp[curr-nums[i]];
                    dp[curr]%=mod;
                }
            }
        } 
        return dp[target];
    }
};
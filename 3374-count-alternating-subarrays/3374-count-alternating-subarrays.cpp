class Solution {
public:
    int n;
    // long long solve(vector<int> &nums,vector<int> &dp,int idx)
    // {
    //     if(idx>=n)  return 0;
    //     if(dp[idx]!=-1) return dp[idx];

    //     if(idx==0 || nums[idx]!=nums[idx-1])
    //     {
    //         p = solve(nums,dp,idx+1)
    //     }
    // }
    long long countAlternatingSubarrays(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        n=nums.size();
        long long ans=1;
        if(nums.size()==1)    return ans;
        vector<int> dp(n,0);
        dp[0]=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]!=nums[i-1])
            {
                dp[i]=dp[i-1]+1;
            }
            else
            {
                dp[i]=1;
            }
        }
        ans = accumulate(dp.begin(),dp.end(),0ll);
        return ans;
    }
};
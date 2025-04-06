class Solution {
public:
    int n;
    vector<int> res;
    void solve(int idx,vector<int> &nums, vector<int> &ans,vector<int> &dp)
    {
        if(idx==n)
        {
            if(ans.size() > res.size())    res = ans;
            return;
        }
        // if(dp[idx][prev+1]==-1)    return dp[idx][prev+1];

        int p1 = INT_MAX,p2 = INT_MAX;
        if((ans.size() == 0 || nums[idx] % ans.back()  == 0) && dp[idx] < (int)ans.size()+1){
            dp[idx] = ans.size()+1;
            ans.push_back(nums[idx]);
            solve(idx+1, nums, ans, dp);
            ans.pop_back();
        }
        solve(idx+1,nums,ans,dp);

        // dp[idx][prev+1] = max(p1,p2);
        // return dp[idx][prev+1];
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        n = nums.size();
        // vector<vector<int> > dp(n,vector<int> (n,-1));
        int prev=-1;
        vector<int> ans;
        sort(nums.begin(),nums.end());
        vector<int> dp(n,-1); 
        solve(0,nums,ans,dp);
        // ans = max(ans,p);
        return res;
    }
};
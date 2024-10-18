class Solution {
public:
int mx=0;
    int n;
    void getmax(vector<int> &nums)
    {
        int o=0;
        for(int i=0;i<n;i++)
            o|=nums[i];
        mx=o;
        return ;
    }
    int solve(vector<int> &nums,int idx,int tmp)
    {
        if(idx>=n)  return tmp==mx;
        // if(tmp==mx) return 1;
        // if(dp[idx][tmp]!=-1)    return dp[idx][tmp];
        int p=solve(nums,idx+1,tmp|nums[idx]);
        int q=solve(nums,idx+1,tmp);
        return p+q;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        n=nums.size();
        getmax(nums);
        // vector<vector<int> > dp(n,vector<int>(n+1,-1));
        int res=solve(nums,0,0);
        return res;
    }
};
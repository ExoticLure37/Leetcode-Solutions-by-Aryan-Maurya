class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n=nums.size();
        vector<int> vis(n,0);
        int prev=nums[0];
        vis[0]=1;
        for(int i=1;i+1<n;i++)
        {
            if(nums[i]>prev)    
            {
                vis[i]=1;
                prev=nums[i];
            }
        }

        long long ans=0;
        prev=n-1;
        for(int i=n-2;i>=0;i--)
        {
            if(vis[i]==1)
            {
                long long val = (long long)(prev-i)*(long long)nums[i];
                ans+=val;
                prev=i;
            }
        }
        return ans;
    }
};
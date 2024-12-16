class Solution {
public:
    int dp[501];
    int n;
    int solve(vector<int> &arr,int idx,int k){
        if(idx==n)  return 0;
        if(dp[idx]!=-1) return dp[idx];
        int ans=0,mx=0;
        int lim=min(idx+k,n);
        for(int i=idx;i<lim;i++){
            mx=max(mx,arr[i]);
            ans=max(ans,mx*(i-idx+1)+solve(arr,i+1,k));
        }
        return dp[idx]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp,-1,sizeof(dp));
        n=arr.size();
        return solve(arr,0,k);
    }
};
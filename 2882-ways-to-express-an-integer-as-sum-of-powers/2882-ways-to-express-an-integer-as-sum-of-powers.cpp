class Solution {
public:
    int mod = 1e9 + 7;
    int dp[301][301];
    int solve(int n, int x, int i) {
        if(n==0)    return 1;
        if(n<0 || pow(i,x)>n)   return 0;
        if(dp[n][i]!=-1)    return dp[n][i];
        long long take=solve(n-pow(i,x),x,i+1)%mod;
        long long notake=solve(n,x,i+1)%mod;
        return dp[n][i]=(take+notake)%mod;
    }

    int numberOfWays(int n, int x) {
        memset(dp,-1,sizeof(dp));
        return solve(n, x, 1);
    }
};

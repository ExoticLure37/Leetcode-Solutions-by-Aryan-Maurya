class Solution {
public:
    int mod=1e9+7;
    int numTilings(int n) {
        vector<int> dp(1001,0);
        dp[0]=0,dp[1]=1,dp[2]=2,dp[3]=5;
        
        for(int i=4;i<=n;i++){
            dp[i]=((dp[i-1]*2)%mod+dp[i-3])%mod;
        }

        return dp[n];
    }
};
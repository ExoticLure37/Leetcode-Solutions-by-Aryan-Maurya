class Solution {
public:
    int mod=1e9+7;
    long long dp[2501][1001];
    int n;
    long long solve(int idx,int sum,vector<vector<int>>& types,int target){
        if(sum>target)  return 0;
        if(idx==n)   return sum==target;
        if(dp[idx][sum]!=-1)    return dp[idx][sum]%mod;
        long long incl=0,excl=0;
        for(int i=1;i<=types[idx][0];i++){
            if(sum+(i*types[idx][1]) <= target){
                incl+=solve(idx+1,sum+(i*types[idx][1]),types,target)%mod;
            }
            else    break;
        }
        excl=solve(idx+1,sum,types,target)%mod;
        dp[idx][sum]=(incl+excl)%mod;
        return dp[idx][sum];
    }
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        n=types.size();
        memset(dp,-1,sizeof(dp));
        int res=solve(0,0,types,target);
        return res;
    }
};
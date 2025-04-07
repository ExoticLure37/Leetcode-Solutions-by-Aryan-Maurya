class Solution {
public:
    int n,m;
    int dp[71][8001];
    int solve(int i,vector<vector<int> > &mat,int target,int sum){
        if(i>=n)  return abs(sum-target);

        if(dp[i][sum]!=-1)  return dp[i][sum];

        int a=INT_MAX;
        for(int col=0;col<m;col++){
            a=min(a,solve(i+1,mat,target,sum+mat[i][col]));
        }

        return dp[i][sum]=a;
    }
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        n=mat.size();
        m=mat[0].size();

        memset(dp,-1,sizeof(dp));
        int res=solve(0,mat,target,0);

        return res;
    }
};
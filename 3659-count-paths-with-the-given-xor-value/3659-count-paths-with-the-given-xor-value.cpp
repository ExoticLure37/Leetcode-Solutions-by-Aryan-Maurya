class Solution {
public:
    int dp[301][301][16];
    int n,m;
    int mod=1e9+7;
    int solve(int x,int y,int xr,vector<vector<int> > &grid,int k){
        if(x==n-1 && y==m-1){    
            xr^=grid[x][y];
            return xr==k;
        }
        if(x>=n || y>=m)    return 0;

        if(dp[x][y][xr]!=-1)    return dp[x][y][xr];
        int p=0,q=0;
        if(x+1<n)   p=solve(x+1,y,xr^grid[x][y],grid,k)%mod;
        if(y+1<m)   q=solve(x,y+1,xr^grid[x][y],grid,k)%mod;

        return dp[x][y][xr]=(p+q)%mod;
    }
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        memset(dp,-1,sizeof(dp));

        n=grid.size();
        m=grid[0].size();

        int res=0;
        res=solve(0,0,0,grid,k);
        return res;
    }
};
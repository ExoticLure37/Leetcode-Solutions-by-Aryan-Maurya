class Solution {
public:
    int n,m;
    long long dp[501][501][3];    //row col {0,1,2}
    int dx[2]={0,+1};
    int dy[2]={+1,0};
    long long solve(int x,int y,vector<vector<int> > &coins,int spell){
        if(x>=n || y>=m)    return INT_MIN;
        if(x==n-1 && y==m-1){
            if(coins[x][y]<0 && spell>0)    return 0;
            return coins[x][y];
        }
        if(dp[x][y][spell]!=-1)    return dp[x][y][spell];
        long long down=INT_MIN,right=INT_MIN,p=INT_MIN;
        right=solve(x,y+1,coins,spell)+coins[x][y];
        down=solve(x+1,y,coins,spell)+coins[x][y];
        if(spell>0 && coins[x][y]<0){
            right=max(right,solve(x,y+1,coins,spell-1));
            down=max(down,solve(x+1,y,coins,spell-1));
        }
        return dp[x][y][spell]=max(right,down);
    }
    int maximumAmount(vector<vector<int>>& coins) {
        n=coins.size();
        m=coins[0].size();
        memset(dp,-1,sizeof(dp));
        long long res=solve(0,0,coins,2);
        return res;
    }
};
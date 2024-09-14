class Solution {
public:
    int n,m;
    int dx[4]={-1,0,+1,0};
    int dy[4]={0,+1,0,-1};
    void dfs(int x,int y,vector<vector<int> > & grid,vector<vector<int> > &vis,int& ans)
    {
        vis[x][y]=1;
        ans+=grid[x][y];
        for(int k=0;k<4;k++)
        {
            int nx = x+dx[k];
            int ny = y+dy[k];

            if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && grid[nx][ny]!=0)
            {
                dfs(nx,ny,grid,vis,ans);
            }
        }
    }
    int findMaxFish(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        n=grid.size();
        m=grid[0].size();
        vector<vector<int> > vis(n,vector<int> (m,0));
        int res=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]!=0)
                {
                    int val = 0;
                    dfs(i,j,grid,vis,val);
                    res = max(res,val);
                }
            }
        }
        return res;
    }
};
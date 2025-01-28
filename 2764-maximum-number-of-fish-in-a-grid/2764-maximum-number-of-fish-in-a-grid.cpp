class Solution {
public:
    int n,m;
    int dx[4]={-1,0,+1,0};
    int dy[4]={0,+1,0,-1};

    bool valid(int nx,int ny){
        return nx>=0 && nx<n && ny>=0 && ny<m;
    }

    void dfs(int x,int y, vector<vector<int> > &vis,vector<vector<int> > &grid,int& sum){
        vis[x][y]=1;

        sum += grid[x][y];
        
        for(int k=0;k<4;k++){
            int nx = x+dx[k];
            int ny = y+dy[k];

            if(valid(nx,ny) && vis[nx][ny]==0 && grid[nx][ny]!=0){
                dfs(nx,ny,vis,grid,sum);
            }
        }

        return ;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        int res=0;

        vector<vector<int> > vis(n,vector<int> (m,0));    

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]!=0){
                    int sum = 0;

                    dfs(i,j,vis,grid,sum);
                    res=max(res,sum);
                    cout<<endl;
                }
            }
        }

        return res;
    }
};
class Solution {
public:
    int n,m;
    int dx[4]={-1,0,+1,0};
    int dy[4]={0,-1,0,+1};

    void DFS(int x,int y,vector<vector<int> > &vis,vector<vector<int> >& grid){
        vis[x][y]=1;
        grid[x][y]=1;
        
        for(int k=0;k<4;k++){
            int nx=x+dx[k];
            int ny=y+dy[k];

            if(nx>=0 && nx<n && ny>=0 && ny<m && vis[nx][ny]==0 && grid[nx][ny]==0){
                DFS(nx,ny,vis,grid);
            }
        }
    }

    void DFS2(int i,int j,vector<vector<int> > &vis,vector<vector<int> >& grid){
        vis[i][j]=1;

        for(int k=0;k<4;k++){
            int nx=i+dx[k];
            int ny=j+dy[k];

            if(nx>=0 && nx<n && ny>=0 && ny<m && vis[nx][ny]==0 && grid[nx][ny]==0){
                DFS2(nx,ny,vis,grid);
            }
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();

        vector<vector<int> > vis(n,vector<int> (m,0));

        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0 && (i==0 || i==n-1 || j==0 || j==m-1)){
                    DFS(i,j,vis,grid);
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0 && vis[i][j]==0){
                    DFS2(i,j,vis,grid);
                    ans++;
                }
            }
        }

        return ans;
    }
};
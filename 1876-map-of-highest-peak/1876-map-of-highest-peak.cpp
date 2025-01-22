class Solution {
public:
    int dx[4]={-1,0,+1,0};
    int dy[4]={0,-1,0,+1};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n=isWater.size();
        int m=isWater[0].size();

        vector<vector<int>> vis(n,vector<int> (m,0));
        vector<vector<int>> dist(n,vector<int> (m,0));

        queue<pair<int,pair<int,int> > >q;      // {step,{x,y}};
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j]==1){
                    vis[i][j]=1;
                    q.push({0,{i,j}});
                }
            }
        }

        while(q.size()){
            auto node=q.front();
            q.pop();
            int step=node.first;
            int x=node.second.first;
            int y=node.second.second;

            // cout<<"x="<<x<<" y="<<y <<" step="<<step<<endl;
            dist[x][y]=step;

            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];

                if(nx>=0 && nx<n && ny>=0 && ny<m && vis[nx][ny]==0){
                    vis[nx][ny]=1;
                    q.push({step+1,{nx,ny}});
                }
            }
        }

        return dist;
    }
};
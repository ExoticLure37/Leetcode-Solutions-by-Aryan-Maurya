class Solution {
public:
    int dx[4]={-1,0,+1,0};
    int dy[4]={0,-1,0,+1};
    int trapRainWater(vector<vector<int>>& height) {
        int n=height.size();
        int m=height[0].size();
        vector<vector<int> > vis(n,vector<int> (m,0));

        priority_queue<pair<int,pair<int,int> > ,vector<pair<int,pair<int,int> >> \
        ,greater<pair<int,pair<int,int> >> > pq; 

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1 || j==0 || j==m-1){
                    vis[i][j]=1;
                    pq.push({height[i][j],{i,j}});    
                }
            }
        }

        int water=0;
        while(pq.size()){
            auto node=pq.top();
            pq.pop();
            int w=node.first;
            int r=node.second.first;
            int c=node.second.second;

            for(int k=0;k<4;k++){
                int nr=r+dx[k];
                int nc=c+dy[k];

                if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]==0){
                    water+=max(0,w-height[nr][nc]);
                    if(w>height[nr][nc])    pq.push({w,{nr,nc}});
                    else    pq.push({height[nr][nc],{nr,nc}});
                    vis[nr][nc]=1;
                }
            }
        }

        return water;
    }
};
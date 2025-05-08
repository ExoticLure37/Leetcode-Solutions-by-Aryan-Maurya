class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        if (grid[0][1] > 1 && grid[1][0] > 1) {
            return -1;
        }

        priority_queue<tuple<long long,int,int>,vector<tuple<long long,int,int>> ,greater<tuple<long long,int,int>> > pq;
        vector<vector<long long> > dist(n,vector<long long> (m,INT_MAX));

        pq.push({0,0,0});
        dist[0][0]=0;

        int dx[4]={-1,0,+1,0};
        int dy[4]={0,+1,0,-1};

        while(pq.size()){
            auto [time,x,y]=pq.top();
            pq.pop();

            // if(x==n-1 && y==m-1)    return time;

            for(int i=0;i<4;i++){
                int xx=x+dx[i],yy=y+dy[i];

                if(xx>=0 && xx<n && yy>=0 && yy<m){
                    long long p=(time-grid[xx][yy])%2==0?1:0;
                    long long t=max(time+1,(long long)grid[xx][yy]+p);

                    if(t<dist[xx][yy]){
                        dist[xx][yy]=t;
                        pq.push({t,xx,yy});
                    }
                }
            }
        }

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<dist[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        return dist[n-1][m-1];
    }
};
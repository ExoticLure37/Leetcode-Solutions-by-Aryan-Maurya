class Solution {
public:
    int minTimeToReach(vector<vector<int>>& g) {
        int n=g.size();
        int m=g[0].size();

        priority_queue<tuple<int,int,int,int>,vector<tuple<int,int,int,int>> ,greater<tuple<int,int,int,int>> > pq;
        vector<vector<int> > dist(n,vector<int> (m,INT_MAX));

        int dx[4]={-1,0,+1,0};
        int dy[4]={0,-1,0,+1};

        pq.push({0,0,0,0});  // time x y turn
        dist[0][0]=0;

        while(pq.size()){
            auto [t,x,y,d]=pq.top();
            pq.pop();

            // if(x==n-1 && y==n-1)    return t;

            for(int i=0;i<4;i++){
                int xx=x+dx[i],yy=y+dy[i];

                if(xx>=0 && xx<n && yy>=0 &&  yy<m){
                    long long p=max(t,g[xx][yy])+1;
                    if(d&1) p++;
                    if(p<dist[xx][yy]){
                        dist[xx][yy]=p;
                        pq.push({dist[xx][yy],xx,yy,d+1});
                    }
                }
            }
        }

        return dist[n-1][m-1];
    }
};
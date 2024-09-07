class Solution {
public:
    int dx[8]={0,-1,-1,-1,0,+1,+1,+1};
    int dy[8]={-1,-1,0,+1,+1,+1,0,-1};
    void gameOfLife(vector<vector<int>>& b) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n=b.size();
        int m=b[0].size();
        
        vector<vector<int> > a;
        a=b;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int alive=0,dead=0;
                // cout << a[i][j]<<" ";
                for(int k=0;k<8;k++)
                {
                    int nx = i+dx[k];
                    int ny = j+dy[k];

                    if(nx>=0 && nx<n && ny>=0 && ny<m)
                    {
                        if(b[nx][ny]==1)    alive++;
                        else    dead++;
                    }
                }
                // cout << " for " << i << " "<<j <<" alive= " <<alive<<endl;
                if(alive<2 && b[i][j]==1) a[i][j]=0;
                else if(b[i][j]==1 && (alive==2 || alive==3))   a[i][j]=1;
                else if(b[i][j]==1 && alive>3)  a[i][j]=0;
                else if(b[i][j]==0 && alive==3) a[i][j]=1;
            }
            cout << endl;
        }
        b=a;
        // return b;
    }
};
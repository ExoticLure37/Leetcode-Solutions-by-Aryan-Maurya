class Solution {
public:
    int n;;
    int t[301][11];
    int solve(vector<int> &j,int idx,int d)
    {
        if(d==1)
            {
                int mx=j[idx];
                for(int i=idx;i<n;i++)  mx=max(mx,j[i]);
                return mx;
            }
            
        if(t[idx][d]!=-1)   return t[idx][d];
        int mx=j[idx];
        int fin=INT_MAX;
        for(int i=idx;i<=n-d;i++)
        {
            mx = max(j[i],mx);
            int res=mx+solve(j,i+1,d-1);
            fin=min(fin,res);
        }
        return t[idx][d]=fin;
    }
    int minDifficulty(vector<int>& j, int d) {
        memset(t,-1,sizeof(t));
        n=j.size();
        if(j.size()<d)  return -1;
        return solve(j,0,d);
        
    }
};
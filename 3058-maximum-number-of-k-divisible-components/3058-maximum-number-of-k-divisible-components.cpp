class Solution {
public:
    long long cnt=0;
    long long mod=1e9+7;
    long long solve(int node,vector<vector<int> >& adjLs,vector<int> &values,vector<int> &vis,int k){
        vis[node]=1;
        long long val=values[node];
        for(auto neigh:adjLs[node]){
            if(vis[neigh]!=1)   val+=solve(neigh,adjLs,values,vis,k);
        }
        if(val%k==0){
            cnt++;
            return 0;
        }
        return val;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int> > adjLs(n);
        for(auto c:edges){
            adjLs[c[0]].push_back(c[1]);
            adjLs[c[1]].push_back(c[0]);
        }
        vector<int> vis(n,0);
        cnt=0;
        long long res=solve(0,adjLs,values,vis,k);
        return cnt;
    }
};
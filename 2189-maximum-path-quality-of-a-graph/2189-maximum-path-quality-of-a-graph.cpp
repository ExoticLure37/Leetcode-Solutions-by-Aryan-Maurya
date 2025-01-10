class Solution {
public:
    int res=0;
    void dfs(int src,int currTime,int currVal,int maxTime,vector<int> &v,vector<vector<pair<int,int> >>& adj){
        if(currTime>maxTime)    return;
        currVal+=v[src];
        if(src==0)  res=max(res,currVal);
        int tmp=v[src];
        v[src]=0;
        for(auto neigh:adj[src]){
            dfs(neigh.first,currTime+neigh.second,currVal,maxTime,v,adj);
        }
        v[src]=tmp;
    }
    int maximalPathQuality(vector<int>& v, vector<vector<int>>& e, int maxTime) {
        int n=v.size();
        vector<vector<pair<int,int> >> adj(n);
        for(int i=0;i<e.size();i++){
            adj[e[i][0]].push_back({e[i][1],e[i][2]});
            adj[e[i][1]].push_back({e[i][0],e[i][2]});
        }
        dfs(0,0,0,maxTime,v,adj);
        return res;
    }
};
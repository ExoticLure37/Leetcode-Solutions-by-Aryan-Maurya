class Solution {
public:
    int dp[1001][1001],n;
    int dfs(int curr,int k,vector<vector<pair<int,int>>>& g, vector<int>& cost){
        if(curr==n-1) // if destination reached, return it's cost
            return cost[n-1];
        if(dp[curr][k]!=-1)  // if already computed, return it
            return dp[curr][k];
        int mn=INT_MAX;
        for(int i=0;i<g[curr].size();i++){
            if(k<g[curr][i].second) // if time to visit the node, is less than remaining time, continue
                continue;
            int a=dfs(g[curr][i].first,k-g[curr][i].second,g,cost);
            if(a!=INT_MAX)
                mn=min(mn,cost[curr]+a);
        }
        return dp[curr][k]=mn;
    }
    int minCost(int k, vector<vector<int>>& edges, vector<int>& cost) {
        n=cost.size();
        int l=edges.size();
        vector<vector<pair<int,int>>>g(n);
        for(int i=0;i<l;i++){
            g[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            g[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        memset(dp,-1,sizeof(dp));
        dfs(0,k,g,cost); 
        return dp[0][k]==INT_MAX?-1:dp[0][k];
    }
};
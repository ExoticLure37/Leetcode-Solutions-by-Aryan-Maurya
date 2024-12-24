class Solution {
public:
     void dfs(int node,int par,unordered_map<int,vector<int>> &adj,int k,int level,int &ans){

        if(level<=k)
        ans++;

        for(auto i:adj[node]){
            if(i!=par)
            dfs(i,node,adj,k,level+1,ans);
        }
     }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
       unordered_map<int,vector<int>> adj1,adj2;

       for(auto e:edges1){
        adj1[e[0]].push_back(e[1]);
        adj1[e[1]].push_back(e[0]);
       }

       for(auto e:edges2){
        adj2[e[0]].push_back(e[1]);
        adj2[e[1]].push_back(e[0]);
       }

        int m=edges1.size()+1;
        int n=edges2.size()+1;


        vector<int> v(m,0);

        for(int i=0;i<m;i++){
            int ans=0;
            dfs(i,-1,adj1,k,0,ans);
            v[i]=ans;
        }
        int maxi=0;
        for(int i=0;i<n;i++){
            int ans=0;
            dfs(i,-1,adj2,k-1,0,ans);
            maxi=max(ans,maxi);
        }

        

        for(int i=0;i<m;i++){
            v[i]+=maxi;
        }

        return v;


    }
};
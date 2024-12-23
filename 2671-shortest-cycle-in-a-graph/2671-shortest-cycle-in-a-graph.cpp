class Solution {
public:
    int res;
    void dfs(int node,int parent,vector<int>& par,vector<vector<int> > &adjLs,vector<int> &vis,vector<int> &dist,int curlen){
        vis[node]=1;
        par[node]=parent;
        dist[node]=curlen;
        for(auto neigh:adjLs[node]){
            if(vis[neigh]==0){
                dfs(neigh,node,par,adjLs,vis,dist,curlen+1);
            }
            else if(vis[neigh]==1 && par[neigh]!=node){      //cycle present
                if(curlen-dist[neigh]>1) res=min(curlen-dist[neigh],res);
            }
        }
        vis[node]=0;
    }
    void bfs(int src,vector<vector<int> > &adjLs,int n){
        vector<int> dist(n,INT_MAX);
        vector<int> par(n,-1);
        queue<int> q;
        q.push(src);
        dist[src]=0;
        // vector<int> vis(n,0);
        while(q.size()){
            int node=q.front();
            q.pop();
            for(auto neigh:adjLs[node]){
                if(dist[neigh]==INT_MAX){
                    dist[neigh]=dist[node]+1;
                    par[neigh]=node;
                    q.push(neigh);
                }
                else if(par[node]!=neigh){
                    res=min(res,dist[neigh]+dist[node]+1);
                }
            }
        }
    }
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int> > adjLs(n);
        for(auto e:edges){
            adjLs[e[0]].push_back(e[1]);
            adjLs[e[1]].push_back(e[0]);
        }
        res=INT_MAX;
        queue<int> q;
        
        for(int i=0;i<n;i++){
            bfs(i,adjLs,n);
        }
        return res==INT_MAX?-1:res;
    }
};
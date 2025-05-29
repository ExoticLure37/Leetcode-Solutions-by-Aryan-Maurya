class Solution {
public:
    void DFS(int src,vector<vector<int> > &adj,vector<int> &vis,int color){
        vis[src]=color;
        
        if(color==1)    color=2;
        else color=1;

        for(auto neigh:adj[src]){
            if(vis[neigh]==0){
                DFS(neigh,adj,vis,color);
            }
        }
        return;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        int n=edges1.size();
        int m=edges2.size();
        n++,m++;

        vector<vector<int> > adj1(n);
        vector<vector<int> > adj2(m);

        for(auto c:edges1){
            adj1[c[0]].push_back(c[1]);
            adj1[c[1]].push_back(c[0]);
        }
        for(auto c:edges2){
            adj2[c[0]].push_back(c[1]);
            adj2[c[1]].push_back(c[0]);
        }

        vector<int> vis1(n,0);
        DFS(0,adj1,vis1,1);
        
        vector<int> vis2(m,0);
        DFS(0,adj2,vis2,1);

        int o=0,t=0;
        for(auto c:vis1){
            if(c==1)    o++;
            else t++;
        }

        for(auto &c:vis1){
            if(c==1) c=o;
            else c=t;
        }

        o=0,t=0;
        for(auto c:vis2){
            if(c==1)    o++;
            else t++;
        }

        for(auto &c:vis1){
            c+=max(o,t);
        }

        return vis1;
    }
};
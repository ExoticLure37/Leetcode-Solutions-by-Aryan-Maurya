class Solution {
public:
    bool DFS(int src, vector<set<int>>& adj, vector<int>& vis) {
        vis[src] = 1; 

        for (auto neigh : adj[src]) {
            if (vis[neigh] == 1) return true; 
            if (vis[neigh] == 0 && DFS(neigh, adj, vis)) return true; 
        }

        vis[src] = 2;  
        return false;
    }
    vector<int> topologicalsort(vector<set<int> >& adj,int k){
        vector<int> order;
        vector<int> indeg(k+1,0);
        for(int i=1;i<=k;i++){
            for(auto c:adj[i])  indeg[c]++;
        }

        queue<int> q;
        for(int i=1;i<=k;i++){
            if(indeg[i]==0)   q.push(i);
        }

        while(!q.empty()){
            int node=q.front();
            q.pop();
            order.push_back(node);

            for(auto neigh:adj[node]){
                indeg[neigh]--;
                if(indeg[neigh]==0)   q.push(neigh);
            }
        }

        return order;
    }        
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<set<int> > adjrow(k+1);    

        for(auto row:rowConditions){
            int u=row[0],v=row[1];
            adjrow[u].insert(v);
        }

        vector<int> vis(k+1,0);
        for(int i=1;i<=k;i++){
            if(vis[i]==0 && DFS(i,adjrow,vis)){
                return {};
            }
        }

        vector<set<int> > adjcol(k+1);    

        for(auto col:colConditions){
            int u=col[0],v=col[1];
            adjcol[u].insert(v);
        }

        fill(vis.begin(), vis.end(), 0);
        for(int i=1;i<=k;i++){
            if(vis[i]==0 && DFS(i,adjcol,vis)){
                return {};
            }
        }

        vector<int> rowSort = topologicalsort(adjrow,k);
        vector<int> colSort = topologicalsort(adjcol,k);
        
        unordered_map<int,int> rowIdx,colIdx;

        for(int i=0;i<k;i++) rowIdx[rowSort[i]]=i;
        for(int i=0;i<k;i++) colIdx[colSort[i]]=i;

        vector<vector<int> > mat(k,vector<int> (k,0));

        for(int i=1;i<=k;i++){
            int x=rowIdx[i];
            int y=colIdx[i];
            mat[x][y]=i;
        } 

        return mat;


    }
};
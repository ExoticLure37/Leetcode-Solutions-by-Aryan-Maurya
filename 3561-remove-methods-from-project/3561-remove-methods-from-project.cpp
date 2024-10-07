class Solution {
public:
    void dfs( int src,vector<vector<int> > &adjLs,vector<int> &vis,vector<int> &defect)
    {
        vis[src]=1;
        defect[src]=1;
        for(auto c:adjLs[src])
        {
            if(vis[c]==0)   dfs(c,adjLs,vis,defect);
        }
    }
    void dfs2(  int src,vector<vector<int> > &adjLs,vector<vector<int> > &adjLs2,vector<int> &vis,vector<int> &defect)
    {
        vis[src]=1;
        defect[src]=0;
        for(auto c:adjLs[src])
        {
            if(vis[c]==0) {  dfs2(c,adjLs,adjLs2,vis,defect);}
        }
        for(auto c:adjLs2[src])
        {
            if(vis[c]==0)   { dfs2(c,adjLs,adjLs2,vis,defect);}
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& in) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<int> defect(n,0);
        vector<int> vis(n,0);
        vector<vector<int> > adjLs(n);
        vector<vector<int> > adjLs2(n);
        for(auto c:in)
        {
            adjLs[c[0]].push_back(c[1]);
            adjLs2[c[1]].push_back(c[0]);
            
        }
        defect[k]=1;
        dfs(k,adjLs,vis,defect);
        for(int i=0;i<n;i++)    vis[i]=0;
        for(int i=0;i<n;i++)
        {
            if(defect[i]==0)    dfs2(i,adjLs,adjLs2,vis,defect);
        }

        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(defect[i]==0) ans.push_back(i);
        }

        return ans;
    }
};
class Solution {
public:
    int d1=INT_MIN;
    int d2=INT_MIN;
    void dfs1(int src,int par,vector<int>& vis1, vector<vector<int> >& g1,int tm){
        vis1[src]=tm;
        for(auto nbr:g1[src]){
            if(nbr!=par){
                dfs1(nbr,src,vis1,g1,tm+1);
            }
        }
        d1=max(d1,vis1[src]);
        return ;
    }
    void dfs2(int src,int par,vector<int>& vis2, vector<vector<int> >& g2,int tm){
        vis2[src]=tm;
        for(auto nbr:g2[src]){
            if(nbr!=par){
                dfs2(nbr,src,vis2,g2,tm+1);
            }
        }
        d2=max(d2,vis2[src]);
        return ;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n1=edges1.size();
        int n2=edges2.size();
        vector<vector<int> > g1(n1+1);
        vector<vector<int> > g2(n2+1);
        for(auto c:edges1){
            g1[c[0]].push_back(c[1]);
            g1[c[1]].push_back(c[0]);
        }
        for(auto c:edges2){
            g2[c[0]].push_back(c[1]);
            g2[c[1]].push_back(c[0]);
        }
        vector<int> vis1(n1+1,0);
        dfs1(0,-1,vis1,g1,0);
        int node=0;
        int mx=vis1[0];
        for(int i=0;i<=n1;i++){
            if(vis1[i]>mx){
                mx=vis1[i];
                node=i;
            }
        }
        d1=0;
        vis1.assign(n1+1,0);
        dfs1(node,-1,vis1,g1,0);
        // cout<<"d1="<<d1<<endl;
        vector<int> vis2(n2+1,0);
        dfs2(0,-1,vis2,g2,0);
        node=0;
        mx=vis2[0];
        for(int i=0;i<=n2;i++){
            if(vis2[i]>mx){
                mx=vis2[i];
                node=i;
            }
        }
        d2=0;
        vis2.assign(n2+1,0);
        dfs2(node,-1,vis2,g2,0);
        // cout<<"d2="<<d2<<endl;
        return max({d1,d2,(d1+1)/2+(d2+1)/2+1});
    }
};
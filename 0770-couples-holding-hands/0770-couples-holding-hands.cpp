class Solution {
public:
    void dfs(int src,vector<vector<int> > &adjLs,int n,vector<int> &vis){
        vis[src]=1;
        // cout<<"Src="<<src<<" : ";
        for(auto node:adjLs[src]){
            // cout<<"node="<<node<<" ";
            if(!vis[node]) 
            {
                vis[node]=1;
                dfs(node,adjLs,n,vis);
            }
        }
        cout<<endl;
        return;
    }
    int minSwapsCouples(vector<int>& row) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n=row.size();
        vector<vector<int> > adjLs(n);
        for(int i=0;i<n;i+=2){
            adjLs[i].push_back(i+1);
            adjLs[i+1].push_back(i);
            adjLs[row[i]].push_back(row[i+1]);
            adjLs[row[i+1]].push_back(row[i]);
        }
        int comp=0;
        for(int i=0;i<n;i++){
            // cout<<i<<" : ";
            for(auto c:adjLs[i]){
                // cout<<c<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cout<<"calling for..."<<i<<endl;
                vis[i]=1;
                dfs(i,adjLs,n,vis);
                comp++;
            }
        }
        cout<<"comp=" <<comp<<endl;
        return n/2-comp;
    }
};
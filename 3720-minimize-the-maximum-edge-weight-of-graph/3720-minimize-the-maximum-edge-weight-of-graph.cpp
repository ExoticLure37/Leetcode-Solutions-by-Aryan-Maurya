class Solution {
public:
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        vector<vector<pair<int,int> >>adjLs(n);
        int ans=-1;
        for(auto e:edges){
            adjLs[e[1]].push_back({e[0],e[2]});
            // ans=max(ans,e[2]);
        }
        auto bfs=[&](int m){
            vector<int> vis(n,0);
            queue<int > q;
            int count=1;
            vis[0]=1;
            q.push(0);
            while(q.size()){
                int node=q.front();
                q.pop();
                if(count==n)    return true;
                for(auto neigh:adjLs[node]){
                    if(neigh.second<=m && !vis[neigh.first]){
                        vis[neigh.first]=1;
                        count+=1;
                        q.push(neigh.first);
                    }
                }
            }
            return count==n;
        };
        // if(bfs(ans)==false) return -1;
        int l=0,r=1e6+10;
        while(l<=r){
            int m=l+(r-l)/2;
            if(bfs(m)){
                r=m-1;
                ans=m;
            }
            else    l=m+1;
        }
        return ans;
    }
};
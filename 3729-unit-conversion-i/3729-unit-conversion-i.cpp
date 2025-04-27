class Solution {
public:
    vector<int> baseUnitConversions(vector<vector<int>>& convo) {
        int n=convo.size();
        vector<int> res(100001,1);

        int mod=1e9+7;
        int mx=0;

        vector<vector<pair<int,int> > > adj(100001);

        for(int i=0;i<n;i++){
            vector<int> t=convo[i];
            int x=t[0];
            int y=t[1];
            int w=t[2];
            mx=max({mx,x,y});
            adj[x].push_back({y,w});
        }

        queue<int> q;
        unordered_set<int> s;

        q.push(0);
        s.insert(0);

        while(q.size()){
            int node=q.front();
            q.pop();
            int d=res[node];

            for(auto& [neigh,wt]:adj[node]){
                if(s.count(neigh)==0){
                    s.insert(neigh);
                    long long temp=(1ll*d%mod*wt%mod)%mod;
                    res[neigh]=(int)(temp%mod);
                    q.push(neigh);
                }
            }
        }

        vector<int>ans;
        for(int i=0;i<=mx;i++)   ans.push_back(res[i]);

        return ans;
    }
};
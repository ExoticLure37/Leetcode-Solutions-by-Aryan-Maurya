using ll=long long;
class Solution {
public:
    ll DFS(ll node,vector<ll> &vis,vector<set<ll> > &adj){
        vis[node]=1;
        ll sz=1;

        for(auto neigh:adj[node]){
            if(!vis[neigh]){
                sz+=DFS(neigh,vis,adj);
            }
        }

        return sz;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        ll n=bombs.size();

        vector<set<ll> > adj(n);

        for(ll i=0;i<n;i++){
            vector<int> f = bombs[i];
            ll x1=f[0],y1=f[1],r1=f[2];

            for(ll j=i+1;j<n;j++){
                vector<int> s=bombs[j];
                ll x2=s[0],y2=s[1],r2=s[2];

                ll d=pow(abs(x1-x2),2)+pow(abs(y1-y2),2);

                if(d<=(r1*r1)){
                    adj[i].insert(j);
                }
                if(d<=(r2*r2)){
                    adj[j].insert(i);
                }
            }
        }

        ll res=0;

        for(ll i=0;i<n;i++){
            vector<ll> vis(n,0);
            ll sz=DFS(i,vis,adj);
            res=max(res,sz);
        }

        return res;
    }
};
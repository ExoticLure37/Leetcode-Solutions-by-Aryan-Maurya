using ll=long long;
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {

        vector<ll> deg(n,0);

        for(auto c:roads){
            ll u=c[0],v=c[1];
            deg[u]++,deg[v]++;
        } 

        priority_queue<pair<ll,ll> > pq;

        for(ll i=0;i<n;i++){
            pq.push({deg[i],i});
        }
        
        vector<ll> ans(n,0);
        ll k=n;

        while(pq.size()){
            auto idx=pq.top().second;
            ans[idx]=k--;
            pq.pop();
        }

        ll sum=0;
        for(auto c:roads){
            ll u=c[0],v=c[1];
            sum+=ans[u]+ans[v];
        } 

        return sum;
    }
};
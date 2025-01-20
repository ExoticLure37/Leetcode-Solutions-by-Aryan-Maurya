using ll=long long;
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        map<ll,pair<ll,ll> > mp;
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                mp[mat[i][j]]={i,j};
            }
        }
        vector<ll> row(n,0);
        vector<ll> col(m,0);
        ll op=0;
        for(auto num:arr){
            ll r=mp[num].first;
            ll c=mp[num].second;
            if(row[r]==m-1 || col[c]==n-1) return op;
            row[r]++;
            col[c]++;
            op++;
        }
        return m*n;
    }
};
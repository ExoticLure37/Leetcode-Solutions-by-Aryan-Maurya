class Solution {
public:
    using ll=long long;
    long long dividePlayers(vector<int>& s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        multiset<int> m;
        // for(auto k:s)   m.insert(k);
        sort(s.begin(),s.end());
        ll sum=accumulate(s.begin(),s.end(),0ll);
        ll n=s.size(),tar=(sum*2)/n;
        // cout<<"sum="<<sum<<" tar="<<tar<<endl;
        ll i=0,j=n-1;
        ll k=0,ans=0;
        cout<<tar<<endl;
        while(i<j)
        {
            k=s[i]+s[j];
            if(k==tar){
                ans+=s[i]*s[j];
                i++,j--;
            }
            else    return -1;
        }

        
        return ans;
    }
};
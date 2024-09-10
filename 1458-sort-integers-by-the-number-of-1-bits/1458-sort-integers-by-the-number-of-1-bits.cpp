class Solution {
public:
    static bool cmp(pair<int,int > &a,pair<int,int> &b)
    {
        if(a.first<b.first) return true;
        else if(a.first==b.first)   return a.second<b.second;
        return false;
    } 
    vector<int> sortByBits(vector<int>& arr) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<pair<int,int > > res;
        for(auto num:arr)
        {
            res.push_back({__builtin_popcount(num),num});
        }
        sort(res.begin(),res.end(),cmp);
        vector<int> ans;
        for(auto k:res)
        {
            ans.push_back(k.second);
        }
        return ans;
    }
};
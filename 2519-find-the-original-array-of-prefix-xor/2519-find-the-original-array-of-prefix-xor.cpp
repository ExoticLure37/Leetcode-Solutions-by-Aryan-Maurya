class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<int> p;
        p.push_back(pref[0]);
        int n=pref.size();
        for(int i=1;i<n;i++)
        {
            int val = pref[i-1]^pref[i];
            p.push_back(val);
        }
        return p;
    }
};
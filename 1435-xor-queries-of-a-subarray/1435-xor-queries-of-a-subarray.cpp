class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& q) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n=arr.size();
        vector<int> pre(n+1,0);
        for(int i=0;i<n;i++)
        {
            pre[i+1] = pre[i]^arr[i];
        }
    
        vector<int> res;
        for(auto vec : q)
        {
            int l=vec[0],r=vec[1];
            int val = pre[r+1]^pre[l];
            res.push_back(val);
        }
        return res;
    }
};
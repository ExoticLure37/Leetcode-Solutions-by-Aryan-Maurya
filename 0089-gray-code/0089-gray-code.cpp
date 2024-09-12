class Solution {
public:
    vector<int> grayCode(int n) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<int> res;
        int len = pow(2,n);
        for(int i=0;i<len;i++)
        {
            int val = i^(i>>1);
            res.push_back(val);
        }
        return res;
    }
};
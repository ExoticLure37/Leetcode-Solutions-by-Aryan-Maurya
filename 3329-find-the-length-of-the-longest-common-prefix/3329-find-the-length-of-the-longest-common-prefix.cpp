class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        set<int> s;
        for(auto num : arr1)
        {
            while(s.count(num)==0 && num>0)
            {
                s.insert(num);
                num/=10;
            }
        }

        int res=0;
        for(auto num:arr2)
        {
            while(s.count(num)==0 && num>0)
            {
                num/=10;
            }
            if(num>0)
            {
                res = max(res, static_cast<int>(log10(num)+1) );
            }
        }
        return res;
    }
};
class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& b) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int i=0;
        map<string,int> mp;
        for(auto c:b)
        {
            mp[c]++;
        }
        for(auto c:message)
        {
            if(mp[c]>0) i++;
        }
        return i>1?true:false;
    }
};
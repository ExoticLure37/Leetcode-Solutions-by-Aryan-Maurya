class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int ans=0;
        set<char> s(allowed.begin(),allowed.end());
        for(auto w:words)
        {
            int fl=1;
            for(auto c:w)
            {
                if(s.find(c)==s.end())
                {
                    fl=0;
                    break;
                }
            }
            if(fl==0)   continue;
            else    ans++;
        }
        return ans;
    }
};
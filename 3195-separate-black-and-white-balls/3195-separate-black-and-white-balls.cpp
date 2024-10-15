class Solution {
public:
    long long minimumSteps(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        long long z=0,ans=0;
        for(int i=s.length()-1;i>=0;i--)
        {
            if(s[i]=='0')   z++;
            else ans+=z;
        }
        return ans;
    }
};
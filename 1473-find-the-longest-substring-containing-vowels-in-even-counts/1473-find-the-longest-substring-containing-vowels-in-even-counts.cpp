class Solution {
public:
    int findTheLongestSubstring(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0); 
        int n=s.length();
        map<int,int> mp;
        mp[0]=-1;
        int cnt=0,ans=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
            {   
                cnt = cnt^(1<<(s[i]-'a'));
            }
            if(mp.count(cnt))
            {
                ans = max(ans,i-mp[cnt]);
            }
            else
            {
                mp[cnt]=i;
            }
        }
        return ans;
    }
};
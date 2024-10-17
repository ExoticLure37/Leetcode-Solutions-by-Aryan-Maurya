class Solution {
public:
    int maximumSwap(int num) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int ans=num;
        string s=to_string(num);
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                swap(s[i],s[j]);
                ans=max(ans,stoi(s));
                swap(s[i],s[j]);
            }
        }
        return ans;
    }
};
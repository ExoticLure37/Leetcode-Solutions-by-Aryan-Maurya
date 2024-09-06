class Solution {
public:
    int balancedString(string s) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        map<char, int> mp;
        int n = s.length();
        int k = n / 4;
        for (char c : s) {
            mp[c]++;
        }
        string str = "";
        for (auto it : mp) {
            if (it.second > k) {
                str += string(it.second - k, it.first);
            }
        }
        
        if (str == "") return 0;
        vector<int> cnt(128, 0);
        int len = str.length();
        
        for (char c : str) cnt[c]++;
        
        int l = 0, r = 0, ans = n;
        
        while (r < n) {
            cnt[s[r]]--;
            if (cnt[s[r]] >= 0) len--;
            r++;
            while (l < r && len == 0) {
                ans = min(ans, r - l);
                cnt[s[l]]++;
                if (cnt[s[l]] > 0) len++;
                l++;
            }
        }
        
        return ans;
    }
};

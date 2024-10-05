class Solution {
public:
    int n;
    map<pair<int, string>, int> memo;

    bool hasUniqueChars(const string& s) {
        vector<int> freq(26, 0);
        for (char c : s) {
            if (++freq[c - 'a'] > 1) return false;
        }
        return true;
    }

    int solve(vector<string>& arr, int idx, string s) {
        if (idx == n) return s.length();
        
        pair<int, string> key = {idx, s};
        if (memo.find(key) != memo.end()) return memo[key];

        int incl = 0, excl = 0;
        
        string combined = s + arr[idx];
        if (hasUniqueChars(combined)) {
            incl = solve(arr, idx + 1, combined);
        }
        excl = solve(arr, idx + 1, s);
        
        memo[key] = max(incl, excl);
        return memo[key];
    }

    int maxLength(vector<string>& arr) {
        n = arr.size();
        return solve(arr, 0, "");
    }
};

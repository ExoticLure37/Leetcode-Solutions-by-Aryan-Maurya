class Solution {
public: 
    unordered_set<string> mp;
    int n;
    vector<int> dp;
    bool solve(int idx,string &s){
        if(idx>=n)  return true;

        if(dp[idx]!=-1) return dp[idx];

        string p="";
        for(int i=idx;i<n;i++){
            p+=s[i];

            if(mp.count(p)>0 && solve(i+1,s)){
                dp[idx]=true;
                return dp[idx];
            }
        }

        return dp[idx]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n=s.length();
        for(auto c:wordDict){
            mp.insert(c);
        }

        dp.resize(n+1,-1);
        bool res=solve(0,s);
        return res;
    }
};
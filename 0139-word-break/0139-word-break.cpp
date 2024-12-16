class Solution {
public:
    int n;
    map<string,int> mp;
    string empty="";
    int solve(string &s,string &curr,int idx,map<string,int> &dp){
        if(curr.length()>n) return 0;
        if(idx==n)  return mp[curr]>0;
        string key=curr+'-'+to_string(idx);
        if(dp.find(key)!=dp.end())  return dp[key];
        curr+=s[idx];
        int first=false,second=false;
        if(mp[curr]>0){        //can remove
            int f2=solve(s,curr,idx+1,dp);
            curr="";
            int f1=solve(s,curr,idx+1,dp);
            first= f1||f2;
        }
        else    second =solve(s,curr,idx+1,dp);
        return dp[key]=first||second;
    }
    bool wordBreak(string s, vector<string>& wd) {
        n=s.length();
        for(auto c:wd)  mp[c]++;
        map<string,int> dp;
        return solve(s,empty,0,dp);
    }
};
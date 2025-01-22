using ll=long long ;
class Solution {
public:
    ll n;
    long long dp[100001];
    ll solve(ll idx,vector<vector<int> > &questions){
        if(idx==n-1)  return questions[idx][0];
        if(idx>=n)  return 0;

        if(dp[idx]!=-1) return dp[idx];

        ll skip=0,notskip=0;
        notskip=solve(idx+questions[idx][1]+1,questions)+questions[idx][0];
        skip=solve(idx+1,questions)+0;
        
        return dp[idx]=max(skip,notskip);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        n=questions.size();

        memset(dp,-1,sizeof(dp));
        ll res=solve(0,questions);

        return res;
    }
};
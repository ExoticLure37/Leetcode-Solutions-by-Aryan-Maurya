using ll=long long;
class Solution {
public:
    ll dp[100001];
    ll solve(ll idx,vector<vector<int> > &ques){
        if(idx>=ques.size())    return 0;

        if(dp[idx]!=-1) return dp[idx];

        ll incl=0,excl=0;
        incl=solve(idx+ques[idx][1]+1,ques)+ques[idx][0];
        excl=solve(idx+1,ques)+0;

        return dp[idx]=max(incl,excl);
    }
    long long mostPoints(vector<vector<int>>& ques) {
        memset(dp,-1,sizeof(dp));
        ll res=solve(0,ques); 
        return res;       
    }
};
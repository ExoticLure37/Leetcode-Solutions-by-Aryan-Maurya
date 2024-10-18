class Solution {
public:
    int n,m;
    vector<vector<int> > dp;
    bool isAllstar(string& p,int j)
    {
        int i=0;
        for(i=0;i<=j;i++) {   if(p[i]!='*')   return false;}
        return true;
    }
    bool solve(string& s,string& p,int i,int j)
    {
        if(i<0 && j<0)  return true;
        if(i>=0 && j<0) return false;
        if(i<0 && j>=0) return isAllstar(p,j);
        if(dp[i][j]!=-1)    return dp[i][j];
        if(s[i]==p[j] || p[j]=='?') return dp[i][j]= solve(s,p,i-1,j-1);
        if(p[j]=='*')  return dp[i][j]=solve(s,p,i-1,j) || solve(s,p,i,j-1);
        return dp[i][j]=false;
    }
    bool isMatch(string s, string p) {
        ios_base::sync_with_stdio(0);
        cout.tie(0);
        cin.tie(0);
        n=s.length(),m=p.length();
        dp=vector<vector<int> > (n,vector<int > (m,-1));
        return solve(s,p,n-1,m-1);
    }
};
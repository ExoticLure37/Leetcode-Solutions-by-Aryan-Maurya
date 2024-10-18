class Solution {
public:
    vector<vector<int> > dp;
    bool valid(string &s,int j)
    {
        for(int i=0;i<j;i++)   {
            if(s[i]!='*')   return false;
        }
        return true;
    }
    bool helper(string &s,string& p,int i,int j)
    {
        if(i<0 && j<0)  return true;
        if(i>=0 && j<0) return false;
        if(i<0 && j>=0) {
            if(p[j]=='*')   return helper(s,p,i,j-2);
            return false;
        }
        if(dp[i][j]!=-1)    return dp[i][j];
        if(s[i]==p[j] || p[j]=='.') return dp[i][j]=helper(s,p,i-1,j-1);
        if (p[j] == '*') {  
            if (j >= 1 && (p[j - 1] == s[i] || p[j - 1] == '.')) {
                return dp[i][j] = helper(s, p, i - 1, j) || helper(s, p, i, j - 2);
            }
            return dp[i][j] = helper(s, p, i, j - 2);
        }return dp[i][j]=false;
    }
    bool isMatch(string s, string p) {
        dp=vector<vector<int> > (s.length(),vector<int>(p.length(),-1));
        return helper(s,p,s.length()-1,p.length()-1);
    }
};
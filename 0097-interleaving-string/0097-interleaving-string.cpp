class Solution {
public:
    int len1,len2,len3;
    int dp[101][101];
    bool solve(int idx1,int idx2,int idx3,string &s1,string &s2,string &s3){
        if(idx1==len1 && idx2==len2 && idx3==len3){
            return true;
        }
        if(idx1<len1 && idx2<len2 && dp[idx1][idx2]!=-1)    return dp[idx1][idx2];
        bool b=0,f=0,s=0;
        if(idx1<len1 && s1[idx1]==s3[idx3] && idx2<len2 && s2[idx2]==s3[idx3]){
            b=(solve(idx1+1,idx2,idx3+1,s1,s2,s3)||solve(idx1,idx2+1,idx3+1,s1,s2,s3));
        }
        else if(idx1<len1 && s1[idx1]==s3[idx3]){
            f=solve(idx1+1,idx2,idx3+1,s1,s2,s3);
        }
        else if(idx2<len2 && s2[idx2]==s3[idx3]){
            s=solve(idx1,idx2+1,idx3+1,s1,s2,s3);
        }
        else{
            return false;
        }
        return dp[idx1][idx2]=b||f||s;
    }
    bool isInterleave(string s1, string s2, string s3) {
        len1=s1.length();
        len2=s2.length();
        len3=s3.length();
        memset(dp,-1,sizeof(dp));
        if(len1+len2!=len3) return 0;
        int n=0,m=0;
        return solve(0,0,0,s1,s2,s3);
    }
};
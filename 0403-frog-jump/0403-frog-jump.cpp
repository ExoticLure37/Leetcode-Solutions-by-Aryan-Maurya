class Solution {
public:
    int n;
    int dp[2001][2001];
    map<int,int> mp;
    bool solve(int idx,int jumpLen,vector<int> stones){
        if(idx==n-1)    return true;
        if(idx>=n || jumpLen<=0)  return false;

        if(dp[idx][jumpLen]!=-1) return dp[idx][jumpLen];

        int k1=false;   //k-1
        int k2=false;   //k
        int k3=false;   //k+1
        if(mp.find(stones[idx]+jumpLen-1)!=mp.end())    
            k1=solve(mp[stones[idx]+jumpLen-1],jumpLen-1,stones);
        
        if(mp.find(stones[idx]+jumpLen)!=mp.end())    
            k2=solve(mp[stones[idx]+jumpLen],jumpLen,stones);
        
        if(mp.find(stones[idx]+jumpLen+1)!=mp.end())    
            k3=solve(mp[stones[idx]+jumpLen+1],jumpLen+1,stones);

        return dp[idx][jumpLen]=k1||k2||k3;
    }
    bool canCross(vector<int>& stones) {
        n=stones.size();
        if(stones[0]+1!=stones[1])  return  false; 

        for(int i=0;i<n;i++)    mp[stones[i]]=i;

        memset(dp,-1,sizeof(dp));
        bool res=solve(1,1,stones);

        return res;
    }
};
class Solution {
public:
static bool cmp(pair<char,pair<int,int> > &a,pair<char,pair<int,int> > &b){
    return a.second.first<b.second.first;
}
    int n,m;
    long long dp[101][10001];
    long long solve(int ridx,int fidx,vector<int> &robot,vector<int> &fact){
        if(ridx==n) return 0;
        if(fidx==m) return (1e18);
        if(dp[ridx][fidx]!=-1)  return dp[ridx][fidx];
        long long incl=abs(fact[fidx]-robot[ridx])+solve(ridx+1,fidx+1,robot,fact);
        long long excl=0+solve(ridx,fidx+1,robot,fact);
        return dp[ridx][fidx]=min(incl,excl); 
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(),robot.end());
        vector<int> fact;
        for(auto c:factory){
            int lim=c[1];
            while(lim--)    fact.push_back(c[0]);
        }
        sort(fact.begin(),fact.end());
        n=robot.size(),m=fact.size();
        memset(dp,-1,sizeof(dp));
        long long res=solve(0,0,robot,fact);
        return res;

    }
};
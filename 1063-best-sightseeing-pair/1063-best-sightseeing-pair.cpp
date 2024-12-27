class Solution {
public:
    int n;
    // int solve(vector<int> &add,int idx,vector<int> &dp){
    //     if(idx==n)  return 0;
    //     for(int i=0;i<)
    // }
    int maxScoreSightseeingPair(vector<int>& values) {
        n=values.size();
        vector<int> add(n);
        for(int i=0;i<n;i++)    add[i]=values[i]+i;
        vector<int> sub(n);
        for(int i=0;i<n;i++)    sub[i]=values[i]-i;

        vector<int> dp(n,-1);
        dp[0]=add[0];
        for(int i=1;i<n;i++){
            dp[i]=max(dp[i-1],add[i]);
        }
        int res=0;
        for(int j=1;j<n;j++)  res=max(res,dp[j-1]+sub[j]);
        // solve(add,0,dp);
        return res;
    }
};
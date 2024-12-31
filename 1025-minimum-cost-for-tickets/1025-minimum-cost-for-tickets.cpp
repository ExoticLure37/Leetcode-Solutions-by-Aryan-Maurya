class Solution {
public:
    int solve(vector<int>& days, vector<int>& cost,int index,int n,vector<int>& dp){
        if(index>=n)
            return 0;

        if(dp[index]!=-1)
            return dp[index];

        int op1 = cost[0] + solve(days,cost,index+1,n,dp);
        int i;
        for(i=1;i<n && days[i]<days[index]+7;i++);
        int op2 = cost[1] + solve(days,cost,i,n,dp);
        for(i=1;i<n && days[i]<days[index]+30;i++);
        int op3 = cost[2] + solve(days,cost,i,n,dp);
        
        dp[index] = min(op1,min(op2,op3));
        return dp[index];
    }
    int solveTab(vector<int>& days, vector<int>& cost,int index,int n){
        vector<int> dp(n+1,INT_MAX);
        dp[n] = 0;
        for(int k=n-1;k>=0;k--){
            int op1 = cost[0] + dp[k];
            int i;
            for(i=1;i<n && days[i]<days[index]+7;i++);
            int op2 = cost[1] + dp[i];
            for(i=1;i<n && days[i]<days[index]+30;i++);
            int op3 = cost[2] + dp[i];
            dp[k] = min(op1,min(op2,op3));
        }
        return dp[0];
    }
    int mincostTickets(vector<int>& days, vector<int>& cost) {
        int index=0;
        int n = days.size();
        
        vector<int> dp(n+1,-1);
        return solve(days,cost,index,n,dp);
    }
};
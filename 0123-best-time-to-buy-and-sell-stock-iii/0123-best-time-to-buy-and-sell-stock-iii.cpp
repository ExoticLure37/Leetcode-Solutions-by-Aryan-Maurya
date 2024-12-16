class Solution {
public:
    int n;
    int solve(vector<int> &p,int idx,int buy,int count,vector<vector<vector<int> > > memo){
        if(idx>=n)  return 0;
        if(count==0)    return 0;
        if(memo[idx][buy][count]!=-1)   return memo[idx][buy][count];
        int res=0;
        if(buy){
            int profit=-p[idx]+solve(p,idx+1,0,count,memo);
            int profit2=0+solve(p,idx+1,1,count,memo);
            res= max(profit,profit2);
        }
        else{
            int profit=p[idx]+solve(p,idx+1,1,count-1,memo);
            int profit2=0+solve(p,idx+1,0,count,memo);
            res= max(profit,profit2);
        }
        return memo[idx][buy][count]=res;
    }
    int maxProfit(vector<int>& p) {
        n=p.size();
        if(n==1)    return 0;
        if(n==2)    return max(0,p[1]-p[0]);
        vector<vector<vector<int> > > dp(n+1,vector<vector<int> > (2,vector<int> (3,0)));
        // for(int idx=0;idx<n;idx++){     //count=0
        //     for(int buy=0;buy<2;buy++){
        //         memo[idx][buy][0]=0;
        //     }
        // }
        // for(int count=0;count<3;count++){   //idx==n
        //     for(int buy=0;buy<2;buy++){
        //         memo[n][buy][count]=0;
        //     }            
        // }
        for(int idx=n-1;idx>=0;idx--){
            for(int buy=0;buy<=1;buy++){
                for(int count=1;count<=2;count++){
                    int res;
                    if(buy){
                        int profit=-p[idx]+dp[idx+1][0][count];
                        int profit2=0+dp[idx+1][1][count];
                        res= max(profit,profit2);
                    }
                    else{
                        int profit=p[idx]+dp[idx+1][1][count-1];
                        int profit2=0+dp[idx+1][0][count];
                        res= max(profit,profit2);
                    }
                    dp[idx][buy][count]=res;
                }
            }
        }
        return dp[0][1][2];
    }
};
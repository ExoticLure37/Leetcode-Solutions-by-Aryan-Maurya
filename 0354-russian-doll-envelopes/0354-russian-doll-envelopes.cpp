class Solution {
public:
    int n;

    // int solve(vector<vector<int>> &env, int idx, int prev,vector<vector<int> > &dp) {
    //     if (idx >= n) return 0;

    //     if(dp[idx][prev+1]!=-1) return dp[idx][prev+1];
    //     int unpick = solve(env, idx + 1, prev,dp);
    //     int pick = 0;

    //     if (prev == -1 || (env[prev][0] < env[idx][0] && env[prev][1] < env[idx][1])) {
    //         pick = 1 + solve(env, idx + 1, idx,dp);
    //     }

    //     return dp[idx][prev+1]=max(pick, unpick);
    // }

    int maxEnvelopes(vector<vector<int>>& env) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        n = env.size();

        sort(env.begin(), env.end(), [](vector<int> &a, vector<int> &b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });
        // vector<vector<int> > dp(n+1,vector<int> (n+1,-1));
        // return solve(env, 0, -1,dp);
        vector<int> dp;
        
        for (auto& e : env) {
            auto it = lower_bound(dp.begin(), dp.end(), e[1]);
            if (it == dp.end()) {
                dp.push_back(e[1]);
            } else {
                *it = e[1];
            }
        }
        return dp.size();
    }
};

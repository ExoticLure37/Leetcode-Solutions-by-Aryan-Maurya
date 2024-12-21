class Solution {
public:
    int cnt=0;
    long long solve(int node,vector<vector<int> >& adjLs,vector<int> &nums,vector<int> &vis,int k){
        vis[node]=nums[node];
        for(auto neigh:adjLs[node]){
            if(vis[neigh])    continue;
            vis[node]+=solve(neigh,adjLs,nums,vis,k);
            if(vis[node]>k)   return 1e8;
        }
        if(vis[node]==k) return 0;
        return vis[node];
    }
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        vector<vector<int> > adjLs(n);
        for(auto c:edges){
            adjLs[c[0]].push_back(c[1]);
            adjLs[c[1]].push_back(c[0]);
        }
        int res=0;
        for(int i=n;i>=1;i--){
            cnt=0;
            vector<int> vis(n);
            if(sum%i==0){
                int tmp=solve(0,adjLs,nums,vis,sum/i);
                if(tmp==0){ return i-1;}
                // cout<<endl;
            }
        }
        return res;
    }
};
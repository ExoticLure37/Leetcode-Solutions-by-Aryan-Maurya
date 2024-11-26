class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        vector<int> indeg(n,0);
        for(auto c:edges){
            indeg[c[1]]++;
        }
        int cnt=0;
        for(auto node:indeg){
            cnt+=(node==0);
        }
        int res=-1;
        if(cnt>1)   return res;
        for(int i=0;i<n;i++){
            if(indeg[i]==0)    res=i;
        }
        return res;
    }
};
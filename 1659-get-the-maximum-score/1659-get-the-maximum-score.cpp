class Solution {
public:
    map<int,set<int> > tree;
    int mod = 1e9+7;
    map<int,long long > memo;
    long long res=0;
    long long DFS(int node,int parent){
        int curr = node;
        long long child=0;

        if(memo.find(node)!=memo.end()) return memo[node];

        for(auto ngbr : tree[node]){
            if(ngbr!=parent){
                child = max(child, DFS(ngbr,node));
            }
        }
        res=max(res,(curr+child));
        return memo[node]=curr + child;
    }

    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        for(int i=0;i+1<nums1.size();i++){
            int u = nums1[i];
            int v = nums1[i+1];

            tree[u].insert(v);
        }

        for(int i=0;i+1<nums2.size();i++){
            int u = nums2[i];
            int v = nums2[i+1];
            
            tree[u].insert(v);
        }

        DFS(nums1[0],-1);

        DFS(nums2[0],-1);

        return res%mod;
    }
};
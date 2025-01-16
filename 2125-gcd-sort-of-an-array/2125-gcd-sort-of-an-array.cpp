class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int n;
    int find(int x){
        if(parent[x]==x)    return x;
        return parent[x]=find(parent[x]);
    }
    void Union(int x,int y){
        int px=find(x),py=find(y);
        if(px==py)  return ;
        if(rank[px]>rank[py]) parent[py]=px;
        else if(rank[py]>rank[px])    parent[px]=py;
        else{
            parent[px]=py;
            rank[py]++;
        }
        return;
    }
    bool gcdSort(vector<int>& nums) {
        n=*max_element(nums.begin(),nums.end());
        parent.resize(n+1);
        rank.resize(n+1,1);
        for(int i=1;i<=n;i++)    parent[i]=i;
        for(auto num:nums){
            for(int j=2;j*j<=num;j++){
                if(num%j==0){
                    Union(num,j);
                    Union(num,num/j);
                }
            }
        }
        vector<int> nums2(nums);
        sort(nums2.begin(),nums2.end());
        for(int i=0;i<nums.size();i++){
            if(find(nums[i])!=find(nums2[i]))   return 0;
        }
        return 1;
    }
};
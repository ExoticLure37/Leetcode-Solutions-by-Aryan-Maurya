class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        vector<int> res;
        int n=nums.size();
        if(n<=2*k)  return res;
        vector<int> l(n,0);
        l[0]=1;
        for(int i=1;i<n;i++){
            if(nums[i]<=nums[i-1])    l[i]=1;
        }
        vector<int> r(n,0);
        r[n-1]=1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<=nums[i+1])    r[i]=1;
        }
        for(int i=1;i<n;i++){
            if(l[i]!=0) l[i]+=l[i-1];
            else    l[i]=1;
        }
        for(int i=n-2;i>=0;i--){
            if(r[i]!=0) r[i]+=r[i+1];
            else    r[i]=1;
        }
        // for(auto c:l)   cout<<c<<" ";
        // cout<<endl;
        // for(auto c:r)   cout<<c<<" ";
        for(int i=k;i<=(n-k-1);i++){
            if(l[i-1]>=k && r[i+1]>=k)  res.push_back(i);
        }
        return res; 
    }
};
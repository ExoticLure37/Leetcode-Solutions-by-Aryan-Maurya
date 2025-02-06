class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();

        map<int,int> mp;
        for(int i=0;i+1<n;i++){
            for(int j=i+1;j<n;j++){
                mp[nums[i]*nums[j]]++;
            }
        }
        
        int res=0;

        for(int i=0;i+1<n;i++){
            for(int j=i+1;j<n;j++){
                int p=nums[i]*nums[j];
                res+=(mp[p]-1)*4;
            }
        }

        return res;

    }
};
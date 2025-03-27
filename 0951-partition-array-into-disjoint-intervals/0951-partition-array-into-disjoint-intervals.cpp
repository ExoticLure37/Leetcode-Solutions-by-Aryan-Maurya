class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n=nums.size();

        vector<int> left(n);
        vector<int> right(n);

        for(int i=0;i<n;i++){
            if(i==0)    left[i]=nums[i];
            else{
                left[i]=max(left[i-1],nums[i]);
            }
        }

        for(int i=n-1;i>=0;i--){
            if(i==n-1){
                right[i]=nums[n-1];
            }
            else{
                right[i] = min(right[i+1],nums[i]);
            }
        }


        // for(auto c:left){
        //     cout<<c<<" ";
        // }
        // cout<<endl;
        // for(auto c:right){
        //     cout<<c<<" ";
        // }

        int res=0;
        for(int i=0;i+1<n;i++){
            if(left[i]<=right[i+1]) return i+1;
        }
        return 3;
    }
};
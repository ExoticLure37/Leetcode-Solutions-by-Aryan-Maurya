class Solution {
public:
    int countSplits(vector<int> & nums,int sum){
        int n=nums.size();
        int noofSplits=1;
        int total_sum=0;
        for(int i=0;i<n;i++){
            if(total_sum+nums[i] > sum){
                noofSplits++;
                total_sum=0;
            }
            total_sum+=nums[i];
        }
        return noofSplits;
    }
    int splitArray(vector<int>& nums, int k) {
        int mx=-1,sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mx=max(mx,nums[i]);
            sum+=nums[i];
        }
        
        int low=mx,high=sum;
        while(low<high){
            int mid=(low+high)/2;
            int val=countSplits(nums,mid);
            if(val>k){
                low=mid+1;
            }
            else{
                high=mid;
            }
        }
        return low; 
    }
};
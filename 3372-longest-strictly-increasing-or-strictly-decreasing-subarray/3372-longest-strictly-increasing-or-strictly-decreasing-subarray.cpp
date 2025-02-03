class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        // if(n==1)    return 1;

        int len1=0,l=0;
        int i=0;
        int prev=0;
        for(int i=0;i<n;i++){
            if(nums[i] > prev){
                l++;
            }
            else{
                l=1;
            }
            len1=max(len1,l);
            prev=nums[i];
        }

        int len2=0;
        l=0;
        prev=51;
        for(int i=0;i<n;i++){
            if(nums[i] < prev){
                l++;
            }
            else{
                l=1;
            }
            len2=max(len2,l);
            prev=nums[i];
        }

        return max(len1,len2);
    }
};
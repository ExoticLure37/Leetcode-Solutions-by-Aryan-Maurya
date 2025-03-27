class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n=nums.size();

        // vector<set<int> > dmat(n);
        map<int,int> left;
        map<int,int> right;
        for(auto c:nums)    right[c]++;

        int mxF=0,ele=0;

        int i=0;
        while(i<n){
            int num=nums[i];
            left[num]++;
            right[num]--;

            if(left[num]*2>(i+1) && right[num]*2>(n-i-1)){
                return i;
            }
            i++;
        }  
        return -1;
    }
};
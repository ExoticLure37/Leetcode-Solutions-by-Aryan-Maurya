class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n=nums.size();

        set<int> s;
        int res=0;
        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++){
            int num=nums[i];
            if(s.count(num)==0){
                s.insert(num);
                // p.push_back(num);
            }
            else{
                int op=0;
                int prev=nums[i-1];
                int curr=prev+1;
                op=curr-nums[i];
                nums[i]=curr;
                s.insert(curr);
                res+=op;
            }
        }

        return res;
    }
};
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;

        int n=nums.size();

        for(int i=0;i<n;i++)    s.insert(nums[i]);

        vector<int> t(s.begin(),s.end());
        s.clear();
        int res=0;
        int tmp=0;

        int i=0;
        int prev=INT_MIN;
        while(i<t.size()){
            if(prev==INT_MIN){
                tmp++;
            }
            else if(prev+1==t[i]){
                tmp++;
            }
            else{
                tmp=1;
            }
            prev=t[i];
            res=max(res,tmp);
            i++;
        }
        return res;

    }
};
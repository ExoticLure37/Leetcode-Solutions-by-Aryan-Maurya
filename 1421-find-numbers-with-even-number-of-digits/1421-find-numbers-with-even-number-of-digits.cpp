class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int res=0;

        for(auto c:nums){
            if(to_string(c).length()&1){

            }
            else{
                res++;
            }
        }

        return res;
    }
};
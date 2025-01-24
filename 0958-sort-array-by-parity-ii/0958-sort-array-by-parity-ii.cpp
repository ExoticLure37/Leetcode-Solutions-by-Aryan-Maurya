class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> even,odd;
        vector<int> res;
        
        for(auto c:nums){
            if(c&1) odd.push_back(c);
            else    even.push_back(c); 
        }

        int ei=0,oi=0;
        int i=0;
        
        while(i<nums.size()){
            if(i&1) res.push_back(odd[oi++]);
            else    res.push_back(even[ei++]);
            i++;
        }
        
        return res;
    }
};
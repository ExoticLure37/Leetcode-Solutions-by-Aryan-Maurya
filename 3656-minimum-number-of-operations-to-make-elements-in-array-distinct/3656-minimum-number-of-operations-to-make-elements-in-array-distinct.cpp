class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();

        map<int,int> mp;
        for(int i=0;i<n;i++)    mp[nums[i]]++;

        int op=0;

        auto chkDistinct=[&](int idx){
            set<int> s;
            for(int i=idx;i<n;i++){
                if(s.count(nums[i])>0)  return false;
                s.insert(nums[i]);
            }

            return true;
        };

        for(int i=0;i<n;i+=3){
            bool res = chkDistinct(i);
            if(res==true)   return op;
            op++;
        }

        return op;

    }
};
class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n=nums.size();

        map<int,vector<int> > mp;

        for(int i=0;i<n;i++){
            int num=nums[i];
            string s=to_string(num);

            int key = 0;
            for(auto c:s){
                key += (c-'0');
            }

            mp[key].push_back(num);
        }

        for(auto &c:mp){
            sort(c.second.begin(),c.second.end());
        }

        int res=INT_MIN;

        for(auto c : mp){
            vector<int> vec = c.second;
            int sz=vec.size();
            if(sz>=2){
                res = max(res,vec[sz-1]+vec[sz-2]);
            }
        }

        if(res==INT_MIN){
            return -1;
        }
        return res;
    }
};
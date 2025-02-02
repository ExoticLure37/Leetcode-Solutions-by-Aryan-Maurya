class Solution {
public:
    bool check(vector<int>& nums) {
        int n= nums.size();

        deque<int> dq;

        auto solve=[&](deque<int> dq){
            int prev=0;

            for(auto c:dq){
                if(c>=prev){
                    prev = c;
                }
                else{
                    return false;
                }
            }

            return true;
        };

        for(auto c:nums)    dq.push_back(c);

        bool res;
        
        for(int i=0;i<n;i++){
            int f = dq.front();
            dq.pop_front();
            dq.push_back(f);
            res = solve(dq);
            if(res==true)   return res;
        }

        return false;
    }
};
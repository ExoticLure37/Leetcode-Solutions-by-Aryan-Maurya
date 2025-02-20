class Solution {
public:
    set<string> s;
    int n;

    string ans="";
    void solve(int idx,string tmp){
        if(idx==n){
            if(s.count(tmp)==0) ans=tmp;
            return ;
        }

        tmp+='1';
        solve(idx+1,tmp);
        tmp.pop_back();
        tmp+='0';
        solve(idx+1,tmp);

        return ;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        n=nums.size();

        for(auto c:nums)    s.insert(c);

        string tmp="";
        solve(0,tmp);

        return ans;
    }
};
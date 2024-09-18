class Solution {
public:
    static bool cmp(string &s1,string &s2){
        if(s1+s2>s2+s1) return true;
        return false;
    }
    string largestNumber(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<string> temp;
        for(auto i:nums)    temp.push_back(to_string(i));

        sort(temp.begin(),temp.end(),cmp);

        string ans;
        for(auto i:temp)    ans+=i;
        // return ans;

        // while(ans[0]=='0' && ans.length()>1)
        //     ans.erase(0,1);
        
        return ans[0]=='0' ? "0" : ans;
    }
};
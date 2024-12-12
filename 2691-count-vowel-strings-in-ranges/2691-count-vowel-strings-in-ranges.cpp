class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& q) {
        vector<int> ans;
        ans.push_back(0);
        for(auto str:words){
            int p=0;
            int n=str.length()-1;
            if(str[0]=='a' ||str[0]=='e' ||str[0]=='i' ||str[0]=='o' ||str[0]=='u'){
                if(str[n]=='a' ||str[n]=='e' ||str[n]=='i' ||str[n]=='o' ||str[n]=='u'){
                    p=1;
                }
            }
            ans.push_back(ans.back()+p);
        }
        vector<int> res;
        for(auto c:q){
            res.push_back(ans[c[1]+1]-ans[c[0]]);
        }
        return res;
    }
};
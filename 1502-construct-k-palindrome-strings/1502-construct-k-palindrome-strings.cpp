class Solution {
public:
    bool canConstruct(string s, int k) {
        int n=s.length();
        if(n<k) return 0;
        if(n==k)    return 1;
        map<char,int> mp;
        for(auto c:s)   mp[c]++;
        int o=0,e=0;
        for(auto c:mp){
            if(c.second%2==1)   o++;
            else    e++;
        }
        return o<=k;
    }
};
class Solution {
public:
    int maxDifference(string s) {
        int n=s.length();

        map<char,int> mp;
        for(auto c:s)   mp[c]++;

        vector<int> e,o;
        for(auto c:mp){
            if(c.second&1)  o.push_back(c.second);
            else e.push_back(c.second);
        }

        sort(o.begin(),o.end());
        sort(e.begin(),e.end());

        if(e.size()==0) return o[o.size()-1];
        else if(o.size()==0)    return e[0];
        return o[o.size()-1]-e[0];
    }
};
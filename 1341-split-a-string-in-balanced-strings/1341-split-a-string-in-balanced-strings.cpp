class Solution {
public:
    int balancedStringSplit(string s) {
        int n=s.length();
        vector<int> val(n);
        int c=0;
        for(int i=0;i<n;i++){
            if(s[i]=='R')   c++;
            else    c--;
            val[i]=c;
        }
        return count(val.begin(),val.end(),0);
    }
};
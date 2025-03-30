class Solution {
public:
    int reverseDegree(string s) {
        int res=0;

        for(int i=0;i<s.length();i++){
            char c = s[i];
            int p=26-(c-'a');
            int q=i+1;
            res+=p*q;
        }

        return res;
    }
};
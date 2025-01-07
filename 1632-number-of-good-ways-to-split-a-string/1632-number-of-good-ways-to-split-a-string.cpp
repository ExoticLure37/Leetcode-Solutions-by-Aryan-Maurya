class Solution {
public:
    int numSplits(string s) {
        set<char> unique;
        int n=s.length();
        vector<int> lr(n);
        for(int i=0;i<n;i++){
            unique.insert(s[i]);
            lr[i]=unique.size();
        }
        unique.clear();
        vector<int> rl(n);
        for(int i=n-1;i>=0;i--){
            unique.insert(s[i]);
            rl[i]=unique.size();
        }
        int res=0;
        for(int i=0;i<n-1;i++){
            if(lr[i]==rl[i+1])  res++;
        }
        return res;
    }
};
class Solution {
public:
    int n;
    bool solve(int idx,string s,unsigned long long prev){
        if(idx==n)  return 1;
        string p="";
        for(int i=idx;i<n;i++){
            p+=s[i];
            unsigned long long l=stoul(p);
            if(l!=prev-1)   continue;
            if(solve(i+1,s,l))  return 1;
        }
        return 0;
    }
    bool splitString(string s) {
        n=s.length();
        string res="";
        for(int i=0;i<n-1;i++){
            res+=s[i];
            unsigned long long l=stoul(res);
            if(solve(i+1,s,l))  return 1;
        }      
        return 0;
    }
};
class Solution {
public:
    int maxScore(string s) {
        int q;
        int n=s.length();
        if(n==2){
            if(s=="10")  return 0;
            if(s=="01")  return 2;
            return 1;
        }
        int res=0;
        vector<int> z(n,0);
        vector<int> o(n,0);
        for(int i=0;i<n;i++){
            if(s[i]=='0')   z[i]=1;
            else    o[i]=1;
        }      
        for(int i=1;i<n;i++)    z[i]+=z[i-1];
        for(int i=n-2;i>=0;i--)    o[i]+=o[i+1];
        for(int i=1;i<n-1;i++){
            res=max(res,z[i]+o[i]);
        }
        return res;
    }
};
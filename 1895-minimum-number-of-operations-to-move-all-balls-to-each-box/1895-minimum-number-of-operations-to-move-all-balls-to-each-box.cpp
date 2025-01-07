class Solution {
public:
    int n;
    vector<int> minOperations(string s) {
        n=s.length();
        vector<int> res(n);
        if(n==1){
            return {0};
        }
        vector<int> lr(n);
        vector<int> rl(n);
        lr[0]=s[0]-'0';
        rl[n-1]=s[n-1]-'0';
        for(int i=1;i<n;i++)    lr[i]=lr[i-1]+(s[i]-'0');
        for(int i=n-2;i>=0;i--) rl[i]=rl[i+1]+(s[i]-'0');
        for(int i=1;i<n;i++)    lr[i]+=lr[i-1];
        for(int i=n-2;i>=0;i--) rl[i]+=rl[i+1];
        res[0]=rl[1];
        res[n-1]=lr[n-2];
        for(int i=1;i<n-1;i++){
            res[i]=lr[i-1]+rl[i+1];
        }
        return res;
    }
};
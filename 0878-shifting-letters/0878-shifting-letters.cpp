class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n=s.length();
        vector<long long> f(n+1,0);
        int i=0;
        for(auto c:shifts){
            f[0]+=c;
            f[i+1]+=-c;
            i++;
        }
        for(int i=1;i<=n;i++)   f[i]+=f[i-1];
        for(int i=0;i<n;i++){
            long long p=s[i]-'a';
            long long k=(p+f[i]%26)%26;
            s[i]=k+'a';
        }
        return s;
    }
};
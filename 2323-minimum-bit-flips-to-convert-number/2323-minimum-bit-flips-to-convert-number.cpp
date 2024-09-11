class Solution {
public:
    string getStats(int n){
        string s;
        while(n){
            s+=n%2;
            n/=2;
        }
        return s;
    }
    int minBitFlips(int start, int goal) {
        string a=getStats(start);
        string b=getStats(goal);

        if(a.length()<b.length()){
            int k=b.length()-a.length();
            while(k--){
                a+='0';
            }
        }
        else{
            int k=a.length()-b.length();
            while(k--){
                b+='0';
            }
        }
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int cnt=0;
        for(int i=0;i<a.length();i++){
            if(a[i]!=b[i])  cnt++;
        }
        // return cnt;
        return __builtin_popcount(start^goal);
    }
};
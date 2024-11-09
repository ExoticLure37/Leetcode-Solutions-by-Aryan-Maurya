class Solution {
public:
    long long minEnd(int n, int x) {
        if(n==1)return x;
        long long last=x;
        while(n>1){
            last=(last+1)|x;
            n--;
        }
        return last;
    }
};
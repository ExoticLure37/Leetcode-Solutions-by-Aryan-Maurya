class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        vector<int> s(32);
        int k=0;
        uint32_t p=n;
        while(p){
            s[k]=p%2;
            p/=2;
            k++;
        }
        uint32_t res=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==1)   res+=(1<<(31-i));
        }
        return res;
    }
};
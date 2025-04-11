class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt=0;

        auto symm=[&](int num){
            string p=to_string(num);
            int len=p.length();
            if(len%2==1)    return false;
            
            int k=len/2;

            int a=0,b=0;

            for(int i=0;i<k;i++){
                a+=(p[i]-'0');
                b+=(p[i+k]-'0');
            }

            return a==b;
        };

        int num=low;
        while(num<=high){
            if(symm(num))   cnt++;
            num++;
        }

        return cnt;
    }
};
class Solution {
public:
    int minimizeXor(int num1, int num2) {
        // int p=__builtin_popcount(num2);
        int p=0;
        while(num2>0){
            p+=(num2%2);
            num2/=2;
        }
        // cout<<"p="<<p<<endl;
        int x=0;
        for(int i=31;i>=0;i--){
            if((num1>>i)&1){
                if(p>0){
                    x+=(1<<i);
                    p--;
                }
            }
        }
        if(p==0)    return x;
        for(int i=0;i<31;i++){
            if(((num1>>i)&1)==0){
                if(p>0){
                    x+=(1<<i);
                    p--;
                }
            }
        }
        return x;
    }
};
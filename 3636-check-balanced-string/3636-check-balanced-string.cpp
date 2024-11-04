class Solution {
public:
    bool isBalanced(string num) {
        int n=num.length();
        int odd=0;
        int even=0;
        for(int i=0;i<n;i++){
            if(i%2){
                odd+=(nums[i]-'0');
            }
            else{
                even+=(num[i]-'0');
            }
        }
        return odd==even;
    }
};
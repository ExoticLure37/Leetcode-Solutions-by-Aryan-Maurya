class Solution {
public:
    bool isSameAfterReversals(int num) {
        string s=to_string(num);
        reverse(s.begin(),s.end());
        int num1=stoi(s);
        // cout<<num1<<" ";
        s=to_string(num1);
        reverse(s.begin(),s.end());
        int num2=stoi(s);
        // cout<<num2<<" ";
        return num==num2;
    }
};
class Solution {
public:
    string solve(int n){
        if(n==1)    return "1";
        if(n==2)    return "11";
        if(n==3)    return "21";
        if(n==4)    return "1211";
        if(n==5)    return "111221";
        if(n==6)    return "312211";
        if(n==7)    return "13112221";

        string p=solve(n-1);
        string res="";

        int i=0;
        int len=p.length();

        while(i<len){
            int j=i;
            char c=p[j];
            int cnt=0;
            while(j<len && p[j]==c){
                j++;
                cnt++;
            }

            res+=(cnt+'0');
            res+=c;
            i=j;
        }

        return res;
    }
    string countAndSay(int n) {
        return solve(n);
    }
};
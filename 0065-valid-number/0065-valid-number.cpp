class Solution {
public:
    int n;
    bool alpha(string s){
        int cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='-' || s[i]=='+' || (s[i]>='0' && s[i]<='9') || s[i]=='.') continue;
            cnt++;
        }
        return cnt<=1;
    }
    // boolch
    bool isNumber(string s) {
        n=s.length();
        int i=0;
        if(s=="+." || s=="-.") return 0;
        // cout<<"n="<<n;
        if(n==1){
            if(s[i]>='0' && s[i]<='9')  return true;
            return false;
        }

        // 1 decimal
        // 1 aplhabet and that is 'e' or 'E'
        // only one sign if no e
        // two signs on either side of e
        // rhs of r should be decimal
        if(alpha(s)==false) return 0;
        if(s[0]=='-' || s[0]=='+')  i++;
        // cout<<"i="<<i;
        bool has_integer_part = false;
        while (i < n && isdigit(s[i])) {
            has_integer_part = true;
            i++;
        }
        bool has_decimal_part = false;
        if (i < n && s[i] == '.') {
            i++;
            if(i==n) has_decimal_part=true;   
            while (i < n && isdigit(s[i])) {
                has_decimal_part = true;
                i++;
            }
        }   
        if (i < n && (s[i] == 'e' || s[i] == 'E')) {
            i++;
            if (i < n && (s[i] == '+' || s[i] == '-')) i++;
            if (i == n || !isdigit(s[i])) {
                return false;
            }
            while (i < s.size() && isdigit(s[i])) {
                i++;
            }
        }
        return i == s.size() && (has_integer_part || has_decimal_part);
    }
};
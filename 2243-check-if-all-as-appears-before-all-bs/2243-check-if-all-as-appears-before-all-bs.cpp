class Solution {
public:
    bool checkString(string s) {
        int lastA=-1;
        
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]=='a'){
                lastA=i;
                break;
            }
        }

        if(lastA==-1)   return true;

        for(int i=0;i<lastA;i++){
            if(s[i]=='b')   return false;
        }

        return true;
    }
};
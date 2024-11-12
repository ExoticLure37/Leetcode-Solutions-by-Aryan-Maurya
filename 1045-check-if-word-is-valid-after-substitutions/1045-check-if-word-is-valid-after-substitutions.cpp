class Solution {
public:
    bool isValid(string str) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        if(str.length()==0) return true;
        else if(str.length()<=2)    return false;
        stack<char> s;
        for(auto c:str){
            if(c=='c' && s.size()>=2){
                char b=s.top();
                if(b=='b'){
                    s.pop();
                    char a=s.top();
                    if(a=='a'){
                        s.pop();
                    }
                    else{
                        s.push(b);
                    }
                }
                else{
                    s.push(c);
                }
            }
            else{
                s.push(c);
            }
        }
        return s.empty();
    }
};
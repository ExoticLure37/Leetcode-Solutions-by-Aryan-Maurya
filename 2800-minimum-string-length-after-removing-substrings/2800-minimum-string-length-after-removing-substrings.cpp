class Solution {
public:
    int minLength(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        stack<int> stk;
        for(auto c: s){
            if(c == 'B' && stk.size() && stk.top() == 'A') stk.pop();
            else if(c == 'D' && stk.size() && stk.top() == 'C') stk.pop();
            else stk.push(c);
        }
        return stk.size();
    }
};
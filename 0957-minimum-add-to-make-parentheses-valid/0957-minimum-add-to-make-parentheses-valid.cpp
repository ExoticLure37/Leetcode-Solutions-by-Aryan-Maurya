class Solution {
public:
    int minAddToMakeValid(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        stack<char> t;
        for(auto c:s)
        {
            if(!t.empty() && t.top()=='(' && c==')') t.pop();
            else t.push(c);
        }
        return t.size();
    }
};
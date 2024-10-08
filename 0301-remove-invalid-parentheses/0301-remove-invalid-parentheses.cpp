class Solution {
public:
    bool valid(string s)
    {
        stack<char> t;
        for(auto c:s)
        {
            if(c=='(' || c==')')
            {
                if(!t.empty() && t.top()=='(' && c==')') t.pop();
                else t.push(c);
            }
        }
        return t.size()==0;
    }
    set<string>res;
    int n;
    map<string,int> mp;
    void recur(string s,int remove)
    {
        if(mp[s]!=0)    return;
        else mp[s]++;
        if(remove<0)    return;
        if(remove==0)   
        {
            if(valid(s))
                res.insert(s);
            return;
        }
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==')' || s[i]=='(')
            {
                string p=s.substr(0,i);
                string q=s.substr(i+1);
                recur(p+q,remove-1);
            }
            // recur(s,remove);
        }
        return ;
    }
    vector<string> removeInvalidParentheses(string s) {
        stack<char> t;
        n=s.length();
        for(auto c:s){
            if(c=='(' || c==')')
            {
                if(!t.empty() && t.top()=='(' && c==')') t.pop();
                else t.push(c);
            }
        }
        int remove = t.size();
        recur(s,remove);
        vector<string> p;
        for(auto c:res)
        {
            p.push_back(c);
        }
        return p;
    }
};
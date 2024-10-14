class Solution {
public:
    int evalRPN(vector<string>& t) {
        stack<int> s;
        int ans=0;
        vector<string> v={"+","-","*","/"};
        for(auto& c:t)
        {
            if(count(v.begin(),v.end(),c)>0)
            {
                int p=s.top();
                s.pop();
                int q=s.top();
                s.pop();
                if(c=="+")  q+=p;
                else if(c=="-")  q-=p;
                else if(c=="*")  q*=p;
                else if(c=="/")  q/=p;
                s.push(q);
            }
            else
            {
                s.push(stoi(c));
            }
        }
        return s.top();
    }
};
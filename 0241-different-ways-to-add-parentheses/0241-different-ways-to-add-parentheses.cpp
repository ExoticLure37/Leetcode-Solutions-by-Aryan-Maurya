class Solution {
public:
    vector<int> diffWaysToCompute(string exp) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<int> res;
        if(exp.length()==0) return res;
        if(exp.length()==1)
        {
            res.push_back((exp[0]-'0'));
            return res;
        }
        else if(exp.length()==2)
        {
            int val = ((exp[0]-'0')*10)+(exp[1]-'0');
            res.push_back(val);
            return res;
        }

        int n=exp.length();
        for(int i=0;i<n;i++)
        {
            if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*')
            {
                auto left = diffWaysToCompute(exp.substr(0,i));
                auto right = diffWaysToCompute(exp.substr(i+1,n-i));
                for(auto num1:left)
                {
                    for(auto num2:right)
                    {
                        int val=0;
                        if(exp[i]=='+') val=num1+num2;
                        else if(exp[i]=='-') val=num1-num2;
                        else if(exp[i]=='*') val=num1*num2;
                        res.push_back(val);
                    }
                }
            }
        }
        return res;
    }
};
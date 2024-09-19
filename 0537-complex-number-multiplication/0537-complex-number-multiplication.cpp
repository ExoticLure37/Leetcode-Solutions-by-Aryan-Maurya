class Solution {
public:
    vector<int> getNum(string num1)
    {
        int a1=0;
        int i=0;
        int neg=1;
        if(num1[i]=='-')    neg=-1,i++;
        while(i<num1.length() && num1[i]!='+')
        {
            a1=a1*10+(num1[i]-'0');
            i++;
        }
        a1*=neg;
        int b1=0;
        int sign=1;
        if(num1[i+1]=='-')    sign=-1;
        int j=num1.length()-2;
        string p="";
        while(j>=0 && isdigit(num1[j]))
        {
            p+=num1[j];
            j--;
        }
        reverse(p.begin(),p.end());
        b1=stoi(p);
        b1*=sign;

        return {a1,b1};
    }
    string complexNumberMultiply(string num1, string num2) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<int> n1 = getNum(num1);
        vector<int> n2 = getNum(num2);

        int p = n1[0]*n2[0];
        int q = n1[0]*n2[1];
        int r = n1[1]*n2[0];
        int s = n1[1]*n2[1]*(-1);
        int qr = q+r;
        int ps = p+s;
        string res="";
        res+=to_string(ps);
        res+='+';
        res+=to_string(qr);
        res+='i';
        return res;
    }
};
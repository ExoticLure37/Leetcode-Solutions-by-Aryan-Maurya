class Solution {
public:
    string stob(string s)
    {
        int n=stoi(s);
        string a="";
        while(n)
        {
            int val = n%2;
            a+=to_string(val);
            n/=2;
        }
        reverse(a.begin(),a.end());
        return a;
    }
    string convertDateToBinary(string date) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        string res="";
        res=stob(date.substr(0,4))+'-'+stob(date.substr(5,2))+'-'+stob(date.substr(8,2));
        return res;
    }
};
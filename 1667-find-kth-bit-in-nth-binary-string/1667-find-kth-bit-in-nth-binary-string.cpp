class Solution {
public:
    string invert(string p)
    {
        string q="";
        for(auto c:p)
        {
            if(c=='1')  q+='0';
            else q+='1';
        }
        return q;
    }
    string rec(int n)
    {
        if(n==1)    return to_string(0);
        string p=rec(n-1);
        string q=invert(p);
        reverse(q.begin(),q.end());
        return (p+"1"+q);
    }
    char findKthBit(int n, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        string s=rec(n);
        // cout<<s<<endl;

        return s[k-1];
    }
};
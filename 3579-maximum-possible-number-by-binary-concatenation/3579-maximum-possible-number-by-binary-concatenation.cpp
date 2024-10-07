class Solution {
public:
    string bin(int num)
    {
        string p="";
        while(num)
        {
            int val=num%2;
            p+=(val+'0');
            num/=2;
        }
        reverse(p.begin(),p.end());
        return p;
    }
    long long get(string s1,string s2,string s3)
    {
        string s=s1+s2+s3;
        long long num=0;
        reverse(s.begin(),s.end());
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='1')   num+=(1ll<<i);
        }
        return num;
    }
    int maxGoodNumber(vector<int>& nums) {
        long long num=0;
        vector<string> v;
        for(auto c:nums)
        {
            string p=bin(c);
            v.push_back(p);
        }

        num=max({num,get(v[0],v[1],v[2]),get(v[0],v[2],v[1])});
        num=max({num,get(v[1],v[0],v[2]),get(v[1],v[2],v[0])});
        num=max({num,get(v[2],v[1],v[0]),get(v[2],v[0],v[1])});
        return num;
    }
};
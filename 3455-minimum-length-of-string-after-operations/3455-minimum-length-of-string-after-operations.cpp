class Solution {
public:
    int minimumLength(string s) {
        // map<char,int> mp;
        vector<int> v(26,0);
        int len=s.length();
        for(auto i:s)
        {
            v[i-'a']++;
        }

        for(auto c:v)
        {
            if(c>3)
            {
                int d = 0;
                if(c&1) d = c/2;
                else    d = floor((c-1)/2);
                len-=(d*2);
            }
            else if(c==3)
            {
                len-=2;
            }
            // cout << c<<" ";
        }
        return len;
    }
};
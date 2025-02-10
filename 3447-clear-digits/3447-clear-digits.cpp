class Solution {
public:
    string clearDigits(string s) {
        string c="";
        for(auto i:s)
        {
            if(i>='0' && i<='9')
            {
                c.pop_back();
            }
            else
            {
                c+=i;
            }
        }
        return c;
    }
};
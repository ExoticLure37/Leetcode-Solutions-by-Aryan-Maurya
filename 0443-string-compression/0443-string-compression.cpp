class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char> res;

        int n=chars.size();
        int i=0;

        while(i<n){
            int j=i;
            char c=chars[j];
            int cnt=0;

            while(j<n && chars[j]==c){
                cnt++;
                j++;    
            }

            i=j;
            res.push_back(c);
            if(cnt>1){
                string p=to_string(cnt);
                for(auto ch:p){
                    // cout<<"ch="<<ch<<endl;
                    res.push_back(ch);
                }
            }
            
        }
        chars=res;
        // cout<<"res.size()= "<<res.size()<<endl;
        return res.size();
    }
};
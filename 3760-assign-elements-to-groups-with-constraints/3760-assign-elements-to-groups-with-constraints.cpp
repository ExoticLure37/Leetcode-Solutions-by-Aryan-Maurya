class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        // int n=*max_element(groups.begin(),groups.end());
        
        vector<int> res(100001,-1);
        // set<int> s;
        // for(auto c:groups)  s.insert(c);

        for(int i=0;i<elements.size();i++){
            int num=elements[i];
            if(res[num]==-1) {
                res[num]=i;
                for(int j=num;j<100001;j+=num){
                    if(res[j]==-1){ 
                        res[j]=i;
                    }    
                }
            }            
        }

        vector<int> ans;
        for(int i=0;i<groups.size();i++){
            ans.push_back(res[groups[i]]);
        }

        return ans;
    }
};
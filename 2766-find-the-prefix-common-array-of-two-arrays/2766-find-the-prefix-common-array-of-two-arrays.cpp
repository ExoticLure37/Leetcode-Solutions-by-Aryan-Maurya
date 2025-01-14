class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        multiset<int> presentin1;
        multiset<int> presentin2;
        multiset<int>   both;
        int n=A.size();
        vector<int> res(n);
        for(int i=0;i<n;i++){
            presentin1.insert(A[i]);
            presentin2.insert(B[i]);
            if(presentin1.count(B[i])){
                both.insert(B[i]);
                presentin1.erase(B[i]);
                presentin2.erase(B[i]);
            }
            if(presentin2.count(A[i])){
                both.insert(A[i]);
                presentin2.erase(A[i]);
                presentin1.erase(A[i]);
            }
            res[i]=both.size();
        }
        return res;
    }
};
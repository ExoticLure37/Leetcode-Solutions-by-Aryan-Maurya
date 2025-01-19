class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n=tops.size();
        int a[7]={0};
        int b[7]={0};
        int c[7]={0};
        for(int i=0;i<n;i++){
            a[tops[i]]++;
            b[bottoms[i]]++;
            if(tops[i]==bottoms[i]) c[tops[i]]++;
        }
        for(int i=1;i<=6;i++){
            if(a[i]+b[i]-c[i]==n)   return min(a[i],b[i])-c[i];
        }
        return -1;
    }
};
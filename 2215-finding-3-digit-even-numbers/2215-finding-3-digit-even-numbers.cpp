class Solution {
public:
    const int N=10;
    int freq[10]={0};
    
    vector<int> findEvenNumbers(vector<int>& digits) {
        for(auto c:digits)  freq[c]++;

        vector<int> res;
        for(int i=100;i<=999;i+=2){
            int num=i;
            bool found=true;
            int tmp[10]={0};
            while(num){
                int d=num%10;
                tmp[d]++;
                num/=10;
            }

            for(int i=0;i<10;i++){
                if(tmp[i]>freq[i]) found=false;
            }

            if(found)   res.push_back(i);
        }
        
        return res;
    }
};
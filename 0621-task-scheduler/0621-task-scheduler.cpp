class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {0};
        for(char task : tasks){
            freq[task - 'A']++;
        }
        sort(begin(freq) , end(freq));
        int chunk = freq[25] - 1;
        int idel = chunk * n;
        cout<<"idel="<<idel<<endl;
        for(int i=24; i>=0; i--){
            idel -= min(chunk,freq[i]);
            cout<<"idel="<<idel<<endl;
        }

        return idel < 0 ? tasks.size() : tasks.size() + idel;
    }
};
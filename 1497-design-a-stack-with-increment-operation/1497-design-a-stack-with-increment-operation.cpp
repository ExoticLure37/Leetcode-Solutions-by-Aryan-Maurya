class CustomStack {
public:
    vector<int> v;
    int k;
    CustomStack(int maxSize) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        k=maxSize;
    }
    
    void push(int x) {
        if(v.size()==k) return ;
        v.push_back(x);
    }
    
    int pop() {
        if(v.size()==0) return -1;
        int val = v[v.size()-1];
        v.pop_back();
        return val;
    }
    
    void increment(int size, int val) {
        int l=v.size();
        for(int i=0;i<min(size,l);i++)
        {
            v[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
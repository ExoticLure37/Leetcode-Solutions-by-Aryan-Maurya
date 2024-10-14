class RandomizedSet {
    vector<int> v;
    map<int,int> mp;
    set<int> s;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp[val]==0)
        {
            mp[val]++;
            v.push_back(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(mp[val]>0)
        {
            mp[val]--;
            if(mp[val]==0)  mp.erase(val);
            int i=find(v.begin(),v.end(),val)-v.begin();
            v.erase(v.begin()+i);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
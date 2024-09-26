class MyCalendar {
public:
    vector<pair<int,int> > vec; 
    MyCalendar() {
        int i=0;
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    
    bool book(int start, int end) {
        for(auto c:vec)
        {
            if(c.first>=end) continue;
            if(c.second>start)    return false;
        }
        vec.push_back({start,end});
        sort(vec.begin(),vec.end());
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
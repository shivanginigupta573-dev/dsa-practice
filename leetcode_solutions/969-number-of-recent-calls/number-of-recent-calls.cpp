class RecentCounter {
public:
 queue<int>q;
    RecentCounter() {
        
    }
    
    int ping(int t) {
       
        q.push(t);
        int ans=0;
        int range[]={t-3000,t};
         size_t size = q.size();
        for (size_t i = 0; i < size; ++i) {
        int val = q.front();
        if(val>=t-3000 && val<=t)
        {
            ans++;
        }
        
        q.pop();        // Remove from front
        q.push(val);    // Put it back at the end
    }  
    return ans;    
        
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
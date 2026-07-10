class TimeMap {
public: 
    unordered_map<string,vector<pair<int,string>>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
       mp[key].push_back({timestamp,value});//timestamps are incresing so we can use bbinary search later
    }
    
    string get(string key, int timestamp) {
        //if no key present retur ""
        if(mp.count(key)==false)
        return "";
        //else we need to print the largest timestamp _prev
        auto& vec=mp[key];
        int beg=0,end=vec.size()-1;
        string res="";
        while(beg<=end)
        {
            int mid=beg+(end-beg)/2;
            if(vec[mid].first<=timestamp)
            {
                res=vec[mid].second;
                //check for bigger
                beg=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        return res;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
class SmallestInfiniteSet {
public:
    int curr;
    set<int>added;
    SmallestInfiniteSet() {
        curr=1;
    }
    
    int popSmallest() {
        if(!added.empty())
        {
            int x=*added.begin();
            added.erase(added.begin());
            return x;
        }
        return curr++;
    }
    
    void addBack(int num) {
        if(num<curr)//it mean it has been removed
        {
               added.insert(num);
        }
        //if it num>curr then it already there in the infinite set
        
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
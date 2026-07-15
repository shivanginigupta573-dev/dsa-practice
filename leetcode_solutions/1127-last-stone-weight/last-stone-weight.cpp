class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size()==1)
        return stones[0];
        int ans;
        priority_queue<int>pq(stones.begin(),stones.end());//max heap
       while(pq.size()>1)
       {
        int x=pq.top();
        pq.pop();
        int y=pq.top();
        pq.pop();
        if(x!=y)pq.push(x-y);
       }
       if(pq.empty())
       return 0;
       else
       return pq.top();

        
    }
};
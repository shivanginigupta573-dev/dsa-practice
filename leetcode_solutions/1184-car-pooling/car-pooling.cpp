class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        if(trips.empty())
        return true;
    //sort according to starting locations
      int n=trips.size();
      sort(trips.begin(),trips.end(),[](vector<int>&a ,vector<int>b)
      {
           return a[1]<b[1];
      });
      //now a minHeap if the to comes early than the next the seats become empty for the next interval
      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
      pq.emplace(trips[0][2],trips[0][0]);//stores//drop location + passengers
      //now go for each interval
      int occu=trips[0][0];
      if(occu>capacity)
      return false;
      for(int i=1;i<n;i++)
      {
          int a=trips[i][0];
          int b=trips[i][1];
          int c=trips[i][2];
          while(!pq.empty() && b>=pq.top().first )
          {
             occu-=pq.top().second;
             pq.pop();//already dropped off these people so clear off seats
            
          }
          pq.emplace(c,a);
          occu+=a;
          if(occu>capacity)//if at anytime occupancy >capacity
          return false;
      }
      return true;
    }
};
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int,vector<int>,greater<int>>leftHeap;
        priority_queue<int,vector<int>,greater<int>>rightHeap;
        int n=costs.size();
        int l=0;
        int r=n-1;
       long long sum=0;

        while(k--)
        {
            while(rightHeap.size()<candidates && l<=r)
            {
                  rightHeap.push(costs[r--]);
                  
            }
             while(leftHeap.size()<candidates && l<=r)
            { 
                  leftHeap.push(costs[l++]);
                  
            }
            
            if (leftHeap.empty()) {
                sum += rightHeap.top();
                rightHeap.pop();
                if (l <= r)
                    rightHeap.push(costs[r--]);
            }
            else if (rightHeap.empty()) {
                sum += leftHeap.top();
                leftHeap.pop();
                if (l <= r)
                    leftHeap.push(costs[l++]);
            }

            else if(leftHeap.top()>rightHeap.top())
                {
                    sum+=rightHeap.top();
                    rightHeap.pop();
                    if(l<=r)
                rightHeap.push(costs[r--]);
                }
            else
            {
                sum+=leftHeap.top();
                leftHeap.pop();
                if(l<=r)
               leftHeap.push(costs[l++]);
            }
        }
        return sum;
    }
};
class Solution {
public:
   int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char,int> freq;
    for(char t : tasks) freq[t]++;

    priority_queue<int> maxHeap; // just counts
    for(auto& [ch, cnt] : freq) maxHeap.push(cnt);

    int time = 0;
    while(!maxHeap.empty()) {
        vector<int> temp; // tasks we’ll put back after cooldown
        for(int i = 0; i <= n; ++i) { // one round = n+1 slots
            if(!maxHeap.empty()) {
                int cnt = maxHeap.top(); maxHeap.pop();
                if(--cnt > 0) temp.push_back(cnt);
            }
            time++;
            if(maxHeap.empty() && temp.empty()) break; // all done
        }
        for(int cnt : temp) maxHeap.push(cnt); // cooldown over
    }
    return time;
}
};
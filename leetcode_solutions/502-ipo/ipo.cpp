class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> projects(n);
       
        for (int i = 0; i < n; i++) {
            projects[i].first =capital[i];
            projects[i].second=profits[i];
        }
        sort(projects.begin(), projects.end());
        // sort in ascending order of capital
        // now create a maxHeap according to proft
        priority_queue<int> pq;
        // we can choose only k projects
        int i = 0; while (k--) {
            while (i < n && projects[i].first <= w) {
                pq.push(projects[i].second);
                i++;
            }

            if (pq.empty())
                break;

            w += pq.top();
            pq.pop();
        }

        return w;
    }
};
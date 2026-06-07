class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int i, len = intervals.size();
        
        for (i = 0; i < len; i++){
            //adding at the beginning
            if (newInterval[1] < intervals[i][0]) {
                ans.push_back(newInterval);
                while (i < len) {
                    ans.push_back(intervals[i]);
                    i++;
                }
                return ans;
            }//non overlapping but somewhere in between
            else if (newInterval[0] > intervals[i][1]) {
                ans.push_back(intervals[i]);
            }//overlaping condition
            else {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        //if added at end
        ans.push_back(newInterval);
        return ans;
    }
};

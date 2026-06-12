class Solution {
public:
    bool checkInclusion(string s1, string s2) {
      sort(s1.begin(), s1.end());
    int n = s1.size(), m = s2.size();
    for(int i = 0; i <= m - n; i++) {
        string t = s2.substr(i, n);
        sort(t.begin(), t.end());
        if(t == s1) return true;
    }
    return false;
    }
};
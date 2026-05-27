class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char,int>lastLower,firstUpper;
        for (int i=0;i<word.size();i++) {
            if (islower(word[i]))
                lastLower[word[i]]=i; 
            else if (isupper(word[i])&&firstUpper.find(word[i])==firstUpper.end())
                firstUpper[word[i]]=i;          
        }

        int count=0;
        for (auto& [ch,idx]:lastLower) {
            char up=toupper(ch);
            if (firstUpper.count(up)&&idx<firstUpper[up])
                count++;
        }
        return count;
    }
};
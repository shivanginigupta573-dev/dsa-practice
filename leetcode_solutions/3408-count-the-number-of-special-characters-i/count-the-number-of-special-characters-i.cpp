class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char>upper,lower;
        for(char ch:word)
        {
            if(islower(ch))
            lower.insert(ch);
            else if(isupper(ch))
            {
                upper.insert(ch);
            }
        }
        int count=0;
       
         for(char ch='a';ch <= 'z'; ch++) {
            if(lower.count(ch) && upper.count(toupper(ch))) {
                count++;
            }
        }
        return count;
    }
};
class Solution {
public:
    int maxVowels(string s, int k) {
        //fixed size sliding window
        int c=0;
        for( int i=0;i<k;i++)
        {
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
            {
                c++;
            }
        }
        int vowelmax=c;
        for(int i=k;i<s.size();i++)
        {
            // Condition 1: Outgoing is NOT a vowel AND Incoming IS a vowel
            if((s[i-k]!='a' && s[i-k]!='e' && s[i-k]!='i' && s[i-k]!='o' && s[i-k]!='u') && (s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'))
            {
                c++;
            }
            // Condition 2: Outgoing IS a vowel AND Incoming is NOT a vowel
            else if((s[i-k]=='a' || s[i-k]=='e' || s[i-k]=='i' || s[i-k]=='o' || s[i-k]=='u') && (s[i]!='a' && s[i]!='e' && s[i]!='i' && s[i]!='o' && s[i]!='u'))
            {
                c--;
            }
            vowelmax=max(c,vowelmax);
        }
        return vowelmax;
    }
};
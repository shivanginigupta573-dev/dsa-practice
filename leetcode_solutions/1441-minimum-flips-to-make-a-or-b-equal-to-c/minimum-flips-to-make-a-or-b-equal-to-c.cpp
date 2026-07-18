class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;
        for(int i = 0; i < 32; i++) {
            int bitA = (a >> i) & 1;
            int bitB = (b >> i) & 1;
            int bitC = (c >> i) & 1;

            if(bitC == 0) {
                // need a=0 and b=0
                flips += bitA + bitB; // count how many 1s need to become 0
            } else {
                // bitC == 1, need at least one of a,b = 1
                if(bitA == 0 && bitB == 0) {
                    flips += 1; // flip one of them
                }
            }
        }
        return flips;
    }
};
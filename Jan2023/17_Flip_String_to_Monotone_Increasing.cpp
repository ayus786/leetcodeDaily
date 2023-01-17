class Solution {
public: 
    int minFlipsMonoIncr(string S) {
        int flip=0,flip1=0;
        for (auto ch : S) flip=min(flip1 += ch - '0',flip + '1' - ch);
        return flip;
    }
};

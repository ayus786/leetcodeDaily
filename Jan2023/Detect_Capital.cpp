class Solution {
public:
    bool detectCapitalUse(string word) {
        int n=word.size();
        int x=0;
        for(int i=0; i<word.size(); i++){
            if(word[i]>='A' && word[i]<='Z') x++;
        }
        if(x==0 || x==n || (x==1 && (word[0]>='A' && word[0]<='Z'))) return true;
        return false;
    }
};

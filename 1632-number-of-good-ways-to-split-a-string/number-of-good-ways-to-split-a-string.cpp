class Solution {
public:
    int numSplits(string s) {
        int unql=0, unqr=0, res =0;
        vector<int> mp1(26,0);
        vector<int> mp2(26,0);
        for(auto ch:s){
            mp1[ch-'a']++;
            if(mp1[ch-'a']==1)
            unql++;
        }
        for(int i=s.length()-1; i>=0; i--){
            mp1[s[i]-'a']--;
            if(mp1[s[i]-'a']==0){
                unql--;
            }
            mp2[s[i]-'a']++;
            if(mp2[s[i]-'a']==1){
                unqr++;
            }
            if(unqr==unql){
                res++;
            }
        }
        return res;
    }
};
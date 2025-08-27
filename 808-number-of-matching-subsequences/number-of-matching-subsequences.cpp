#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<pair<int,int>>> buckets(26);
        for (int i = 0; i < words.size(); i++) {
            buckets[words[i][0]-'a'].push_back({i,0});
        }
        int res = 0;
        for (char c : s) {
            auto curr = buckets[c-'a'];
            buckets[c-'a'].clear();
            for (auto [i,pos] : curr) {
                pos++;
                if (pos == words[i].size()) res++;
                else buckets[words[i][pos]-'a'].push_back({i,pos});
            }
        }
        return res;
    }
};

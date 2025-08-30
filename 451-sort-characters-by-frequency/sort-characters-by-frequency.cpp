#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        for (char c : s) freq[c]++;

        int n = s.size();
        vector<vector<char>> buckets(n+1);

        for (auto &p : freq) {
            buckets[p.second].push_back(p.first);
        }

        string res;
        for (int i = n; i > 0; i--) {
            for (char c : buckets[i]) {
                res.append(i, c);
            }
        }
        return res;
    }
};

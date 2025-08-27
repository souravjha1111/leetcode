#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int res = 0;
        for (int num : s) {
            if (!s.count(num - 1)) { // start of a sequence
                int curr = num, streak = 1;
                while (s.count(curr + 1)) {
                    curr++;
                    streak++;
                }
                res = max(res, streak);
            }
        }
        return res;
    }
};

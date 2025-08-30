#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> count(3, 0);
        for (int n : nums) count[n]++;
        
        int idx = 0;
        for (int color = 0; color < 3; color++) {
            for (int c = 0; c < count[color]; c++) {
                nums[idx++] = color;
            }
        }
    }
};

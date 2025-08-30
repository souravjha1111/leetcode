#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;

        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());

        if (minVal == maxVal) return 0;

        int gap = ceil((double)(maxVal - minVal) / (n - 1));

        vector<int> bucketMin(n-1, INT_MAX);
        vector<int> bucketMax(n-1, INT_MIN);
        vector<bool> used(n-1, false);

        for (int num : nums) {
            if (num == minVal || num == maxVal) continue;
            int idx = (num - minVal) / gap;
            bucketMin[idx] = min(bucketMin[idx], num);
            bucketMax[idx] = max(bucketMax[idx], num);
            used[idx] = true;
        }

        int prev = minVal, ans = 0;
        for (int i = 0; i < n-1; i++) {
            if (!used[i]) continue;
            ans = max(ans, bucketMin[i] - prev);
            prev = bucketMax[i];
        }
        ans = max(ans, maxVal - prev);
        return ans;
    }
};

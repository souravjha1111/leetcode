class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        vector<int> lef(n, 0), rig(n, 0);

        lef[0] = h[0];
        for (int i = 1; i < n; i++) {
            lef[i] = max(lef[i - 1], h[i]);
        }
        rig[n - 1] = h[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rig[i] = max(rig[i + 1], h[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += max(0, min(lef[i], rig[i]) - h[i]);
        }

        return ans;
    }
};

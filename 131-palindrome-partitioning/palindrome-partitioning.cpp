#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> curr;
        dfs(0, s, curr, res);
        return res;
    }

private:
    void dfs(int start, string& s, vector<string>& curr, vector<vector<string>>& res) {
        if (start == s.size()) {
            res.push_back(curr);
            return;
        }
        for (int end = start; end < s.size(); end++) {
            if (isPalindrome(s, start, end)) {
                curr.push_back(s.substr(start, end - start + 1));
                dfs(end + 1, s, curr, res);
                curr.pop_back();
            }
        }
    }

    bool isPalindrome(string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++; r--;
        }
        return true;
    }
};

class Solution {
public:

    void solve(vector<int>& nums,vector<int>& curr, int pos, vector<vector<int>>& res){
        if(pos==nums.size()){
        res.push_back(curr);
        return;
        }
        curr.push_back(nums[pos]);
        solve(nums, curr, pos+1, res);
        curr.pop_back();
        solve(nums, curr, pos+1, res);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        solve(nums, curr, 0, res);
        return res;
    }
};
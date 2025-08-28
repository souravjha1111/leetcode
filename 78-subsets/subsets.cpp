class Solution {
public:

    void solve(vector<int>& nums, vector<vector<int>>& res, vector<int> temp, int currPos){
        if(currPos == nums.size())
        {
            res.push_back(temp);
            return;
        }
        temp.push_back(nums[currPos]);
        solve(nums, res, temp,currPos+1);
        temp.pop_back();
        solve(nums, res, temp, currPos+1);
    }

  vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()==0)
        return res;
        solve(nums,res, {},0);
        return res;
    }
};
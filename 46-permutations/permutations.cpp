class Solution {
public:
    void solve(set<vector<int>>& res, vector<int>& nums,vector<int>& temp, vector<bool> freq ){
        if(temp.size()==nums.size()){
            res.insert(temp);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(!freq[i]){
                freq[i]=true;
                temp.push_back(nums[i]);
                solve(res,nums,temp,freq);
                freq[i]=false;
                temp.pop_back();
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        set<vector<int>> res;
        vector<bool> freq(nums.size(), false);
        for(int i=0; i<nums.size(); i++)
            freq[i]=false;
        vector<int> temp;
        solve(res, nums, temp, freq);
        vector<vector<int>> finalv;
        for(auto el:res)
            finalv.push_back(el);
        return finalv;
    }
};
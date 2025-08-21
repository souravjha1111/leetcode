class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int cnt = 0;
        long long res = 0;
        for(auto el:nums){
            if(el==0){
                cnt++;
            }
            else{
                if(cnt!=0){
                    res += eval(cnt);
                }
                    cnt=0;
            }
        }
        if(cnt!=0)
        res += eval(cnt);

        return res;
    }

    long long eval(int n){
        return 1LL * n * (n + 1) / 2;
    }
};
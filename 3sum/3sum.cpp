class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i=0; i<(int)(nums.size()-2); i++) {
            if(i == 0 || (i > 0 && nums[i] != nums[i-1])) {
                int lo = i+1, hi = nums.size()-1, sum = 0-nums[i];
                while(lo < hi) {
                    if(nums[lo] + nums[hi] == sum) {
                        vector<int> temp = {nums[i], nums[lo], nums[hi]};
                        res.push_back(temp);
                        while(lo < hi && nums[lo] == nums[lo+1]) lo++;
                        while(lo < hi && nums[hi] == nums[hi-1]) hi--;
                        lo++, hi--;
                    } 
                    else if(nums[lo] + nums[hi] < sum) lo++;
                    else hi--;
                }
            } 
        }
        return res;
    }
};
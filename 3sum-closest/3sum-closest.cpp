class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = nums[0]+nums[1]+nums[2];
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-2; i++){
            int start = i+1, end = nums.size()-1;
            while(start < end) {
                int sum = nums[i] + nums[start] + nums[end];
                if(sum < target) {
                    start++;
                } else end--;
                if(abs(sum - target) < abs(res - target)) {
                    res = sum;
                }
            }
        }
        return res;
    }
};
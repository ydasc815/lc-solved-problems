class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ts = 0;
        for(int i:nums) ts += i;
        if(ts < target) return 0;
        int l = nums.size();
        int i=0, j=0, sum = nums[0];
        while(j < nums.size() && i <= j) {
            if(sum < target) {
                j++;
                if(j<nums.size()) sum += nums[j];
                else break;
            }
            else {
                l = min(l, j-i+1);
                sum -= nums[i];
                i++;
            }
        }
        return (l <= nums.size() ? l : 0);
    }
};
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            int currMax = nums[i];
            int currMin = nums[i];
            for (int j = i + 1; j < n; j++) {
                currMax = max(currMax, nums[j]);
                currMin = min(currMin, nums[j]);
                sum += (currMax - currMin);
            }
        }
        return sum;
    }
};
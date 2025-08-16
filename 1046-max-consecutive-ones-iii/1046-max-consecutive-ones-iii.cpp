class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0, r=0, maxlen=0;
        int temp=k;
        int n = nums.size();
        while(r<n){
            if(nums[r]==0) k--;
            while(k < 0){
                if(nums[l]==0) k++;
                l++;
            }
            maxlen=max(maxlen, r-l+1);
            r++;
        }
        return maxlen;
    }
};
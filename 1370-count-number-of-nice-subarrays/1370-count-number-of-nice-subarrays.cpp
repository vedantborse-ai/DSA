class Solution {
public:
    int fun(vector<int>& nums, int k){
        int l=0, r=0, count=0, ans=0;;
        while(r<nums.size()){
            if(nums[r]%2==1) count++;
            while(count>k){
                if(nums[l]%2==1) count--;
                l++;
            }
            ans+=(r-l+1);
            r++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return fun(nums, k) - fun(nums, k-1);
    }
};
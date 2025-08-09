class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int leftMax = 0, rightMax = 0, total = 0, l = 0;
        int r=n-1;
        while(l<r){
            if(height[l]<=height[r]){
                if(leftMax>height[l]){
                    total+=leftMax-height[l];
                }
                else{
                    leftMax=height[l];
                }
                l++;
            }
            else{
                if(rightMax>height[r]){
                    total+=rightMax-height[r];
                }
                else{
                    rightMax=height[r];
                }
                r--;
            }
        }
        return total;
    }
};
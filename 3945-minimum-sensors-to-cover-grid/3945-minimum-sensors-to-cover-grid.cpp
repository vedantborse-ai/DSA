class Solution {
public:
    int minSensors(int n, int m, int k) {
        int s=2*k+1;
        int rows=(n+s-1)/s;
        int cols=(m+s-1)/s;
        return rows*cols;
    }
};
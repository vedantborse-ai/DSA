class Solution {
public:
    int lHist(vector<int>& arr){
        int n=arr.size();
        stack<int> st;
        int maxArea=0;

        for(int i = 0; i <= n; i++) {
            int currHeight = (i == n ? 0 : arr[i]);

            while (!st.empty() && currHeight < arr[st.top()]) {
                int h = arr[st.top()];
                st.pop();
                int leftIndex = st.empty() ? -1 : st.top();
                int width = i - leftIndex - 1;
                maxArea = max(maxArea, h * width);
            }
            st.push(i);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int maxArea=0;
        vector<vector<int>> pSum(n, vector<int>(m, 0));
        for(int j=0; j<m; j++){
            int sum=0;
            for(int i=0; i<n; i++){
                int val = matrix[i][j] - '0';
                if (val == 0) sum = 0;
                else sum += val;
                pSum[i][j] = sum;
            }
        }
        for(int i=0; i<n; i++){
            maxArea = max(maxArea, lHist(pSum[i]));
        }
        return maxArea;
    }
};